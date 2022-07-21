#include "LoginForm.h"
#include "passwordValidating.h"
#include <msclr\marshal_cppstd.h>

using namespace PassSaver;

System::Void LoginForm::buttonCreateDB_Click(System::Object^ sender, System::EventArgs^ e) {
	isImport = 0;

	labelPassword->ForeColor = Color::Gainsboro;
	textBoxPassword->BackColor = Color::FromArgb(30, 30, 30);
	textBoxPassword->Enabled = true;

	labelRepeatPassword->ForeColor = Color::Gainsboro;
	textBoxReapeatPassword->BackColor = Color::FromArgb(30, 30, 30);
	textBoxReapeatPassword->Enabled = true;

	labelDBLocation->ForeColor = Color::Gainsboro;
	textBoxDBPath->BackColor = Color::FromArgb(30, 30, 30);
	textBoxDBPath->Enabled = true;

	buttonSetPath->Enabled = 1;
	buttonLaunch->Enabled = 1;

	buttonImportDB->BackColor = Color::FromArgb(20, 20, 20);
	buttonCreateDB->BackColor = Color::FromArgb(40, 40, 40);
}

System::Void LoginForm::buttonImportDB_Click(System::Object^ sender, System::EventArgs^ e) {
	isImport = 1;

	labelPassword->ForeColor = Color::Gainsboro;
	textBoxPassword->BackColor = Color::FromArgb(30, 30, 30);
	textBoxPassword->Enabled = true;

	labelRepeatPassword->ForeColor = Color::FromArgb(70, 70, 70);
	textBoxReapeatPassword->BackColor = Color::FromArgb(10, 10, 10);
	textBoxReapeatPassword->Enabled = false;

	labelDBLocation->ForeColor = Color::Gainsboro;
	textBoxDBPath->BackColor = Color::FromArgb(30, 30, 30);
	textBoxDBPath->Enabled = true;

	textBoxDBPath->Enabled = 1;
	buttonSetPath->Enabled = 1;

	buttonLaunch->Enabled = 1;

	buttonImportDB->BackColor = Color::FromArgb(40, 40, 40);
	buttonCreateDB->BackColor = Color::FromArgb(20, 20, 20);
}

System::Void LoginForm::buttonSetPath_Click(System::Object^ sender, System::EventArgs^ e) {
	if (IsImport() == 0)
	{
		saveFileDialog1->Filter = "PassSaverDB files (*.psdb)|*.psdb";
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		{
			return;
		}
		String^ filePath = saveFileDialog1->FileName;
		textBoxDBPath->Text = filePath;
	}
	if (IsImport() == 1)
	{
		openFileDialog1->Filter = "PassSaverDB files (*.psdb)|*.psdb";
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		{
			return;
		}
		String^ filePath = openFileDialog1->FileName;
		textBoxDBPath->Text = filePath;
	}
}

System::Void LoginForm::textBoxPassword_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	switch (passwordRating(textBoxPassword->Text))
	{
	case 0:
		labelPasswordStatus->Text = "";
		break;
	
	case 1:
		labelPasswordStatus->Text = "Weak";
		labelPasswordStatus->ForeColor = Color::Red;
		break;

	case 2:
		labelPasswordStatus->Text = "Medium";
		labelPasswordStatus->ForeColor = Color::DarkOrange;
		break;

	case 3:
		labelPasswordStatus->Text = "Strong";
		labelPasswordStatus->ForeColor = Color::Green;
		break;
	}
	
	const int firstLocation = 628;
	labelPasswordStatus->Left = firstLocation - labelPasswordStatus->Width;
}

System::Void LoginForm::buttonLaunch_Click(System::Object^ sender, System::EventArgs^ e) {
	try
	{
		if (textBoxDBPath->Text == "")
		{
			throw 1;
		}
		if (textBoxPassword->Text == "")
		{
			throw 2;
		}

		String^ path = textBoxDBPath->Text;
		DataBasePath = path;

		if (IsImport() == 0)
		{
			if (textBoxPassword->Text != textBoxReapeatPassword->Text)
			{
				throw 3;
			}

			System::IO::StreamWriter^ file = System::IO::File::CreateText(path);
			file->Close();
		}
		if (IsImport() == 1)
		{
			System::IO::StreamReader^ file = System::IO::File::OpenText(path);
			String^ tempString = file->ReadLine();
			file->Close();
			if (tempString == nullptr)
			{
				throw 4;
			}
		}

		if (textBoxPassword->Text->Length < 8)
		{
			throw 6;
		}

		bool check = 0;
		bool &linkcheck = check;
		
		passwordValidate(textBoxPassword->Text, linkcheck);
		if (!check)
		{
			throw 5;
		}

		pass = textBoxPassword->Text;

		this->Hide();
		MainForm^ form = gcnew MainForm;
		form->Show();
	}
	catch (int ex)
	{
		switch (ex)
		{
		case 1:
			MessageBox::Show("You have to set up DB Location", "DB Location Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			break;
		
		case 2:
			MessageBox::Show("You have to write a password", "Password Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			break;
		
		case 3:
			MessageBox::Show("Password fields have to be the same", "Password Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			break;

		case 4:
			MessageBox::Show("DB file is emtpy...", "DB Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			break;

		case 5:
			MessageBox::Show("Password can contain only English letters, digits and special symbols", "Password Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			break;

		case 6:
			MessageBox::Show("Password`s length has to be at least 8", "Password Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			break;
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message, ex->GetType()->Name, MessageBoxButtons::OK, MessageBoxIcon::Error);
		Application::ExitThread();
	}
}

System::Void LoginForm::LoginForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	Application::Exit();
}