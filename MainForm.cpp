#include "MainForm.h"
#include "LoginForm.h"
#include "ChangePasswordForm.h"
#include "base64.h"
#include <iostream>
#include <msclr\marshal.h>
#include <Windows.h>
#include <array>
#include <vector>

using namespace PassSaver;

bool isSuccess = 0;

std::string exec(const char* cmd) {
	std::array<char, 128> buffer;
	std::string result;
	std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
	if (!pipe) {
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}
	return result;
}

System::Void MainForm::infoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("PassManager (Password Manager) is an application to store your passwords safety\nDatabase file is encrypted using AES algorithm\nForms and other stuff are written on C++\nAES enc\\dec script is written on Python\nSource code is available on Github: nohackingnolife\n====\nstay safe\n====", "Info", MessageBoxButtons::OK, MessageBoxIcon::None);
}

System::Void MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Are you sure?", "Submiting", MessageBoxButtons::OKCancel, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::OK)
	{
		dataGridView1->Rows->Clear();
	}
}

System::Void MainForm::exitWithoutSavingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Are you sure?", "Submiting", MessageBoxButtons::OKCancel, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::OK)
	{
		Application::ExitThread();
	}	
}

System::Void MainForm::MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (MessageBox::Show("Are you sure?", "Submiting", MessageBoxButtons::OKCancel, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::OK)
	{
		saveToolStripMenuItem_Click(sender, e);
		if (!isSuccess)
		{
			e->Cancel = 1;
		}
		else
		{
			Application::ExitThread();
		}
	}
	else
	{
		e->Cancel = 1;
	}
}

System::Void MainForm::saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	System::IO::StreamWriter^ file = System::IO::File::CreateText(LoginForm::DBPath());
	file->Close();
	try
	{
		isSuccess = 0;

		int amount = dataGridView1->Rows->Count;
		if (amount > 1)
		{
			amount--;
		}

		String^ tempText;

		for (int row = 0; row < amount; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				String^ value = dataGridView1->Rows[row]->Cells[col]->Value->ToString();
				if (col == 2 && row == amount - 1)
				{
					tempText += value;
				}
				else
				{
					tempText += value + "\n";
				}
			}
		}

		std::vector<BYTE> myData;

		for (int i = 0; i < tempText->Length; i++)
		{
			myData.push_back(int(tempText[i]));
		}

		std::string encodedData = base64_encode(&myData[0], myData.size());
		String^ result = gcnew String(encodedData.c_str());

		String^ consoleCode = "passmanagercrypto.exe --encrypt " + LoginForm::Password() + " " + LoginForm::DBPath() + " \"" + result + "\"";
		msclr::interop::marshal_context^ context = gcnew msclr::interop::marshal_context();
		const char* charsConsoleCode = context->marshal_as<const char*>(consoleCode);
		WinExec(charsConsoleCode, SW_HIDE);
		
		isSuccess = 1;
		
		MessageBox::Show("Successfully saved", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (System::NullReferenceException^ ex)
	{
		MessageBox::Show("Fields cannot be empty", "Fields error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Void MainForm::changePasswordStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	ChangePasswordForm^ testDialog = gcnew ChangePasswordForm;
	testDialog->ShowDialog();
	if (ChangePasswordForm::GetSuccessResult())
	{
		MessageBox::Show("Your password was succesfully changed, but you need to save your database for the changes to take effect. If you do not do this, your password will not be updated", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

System::Void MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	dataGridView1->Rows[0]->Height = 25;
	if (LoginForm::IsImport() == 0)
	{
		return;
	}
	if (LoginForm::IsImport() == 1)
	{
		try
		{
			String^ tempString;

			int counter = 0;

			String^ consoleCode = "passmanagercrypto.exe --decrypt " + LoginForm::Password() + " " + LoginForm::DBPath();
			msclr::interop::marshal_context^ context = gcnew msclr::interop::marshal_context();
			const char* charsConsoleCode = context->marshal_as<const char*>(consoleCode);
			std::string stdDecryptedText = exec(charsConsoleCode);
			
			if (stdDecryptedText == "wrong\n")
			{
				throw 1;
			}

			std::vector<BYTE> decodedData = base64_decode(stdDecryptedText);
			std::string tempSTDstring;
		
			for (int i = 0; i < decodedData.size(); i++)
			{
				tempSTDstring += decodedData[i];
			}

			String^ text = gcnew String(tempSTDstring.c_str());

			array<String^>^ array = text->Split((Char)'\n');
			counter = array->Length;
			int rows = counter / 3;
			counter = 0;
			
			for (int row = 0; row < rows; row++)
			{
				dataGridView1->Rows->Add();
				for (int col = 0; col < 3; col++)
				{
					dataGridView1->Rows[row]->Cells[col]->Value = array[counter + col];
				}
				counter += 3;
			}
		}
		catch (int ex)
		{
			if (ex == 1)
			{
				MessageBox::Show("Password is wrong or DataBase file is corrupted", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				Application::ExitThread();
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message, ex->GetType()->Name, MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}