#include "ChangePasswordForm.h"

using namespace PassSaver;

System::Void ChangePasswordForm::buttonLaunch_Click(System::Object^ sender, System::EventArgs^ e) {
	try
	{
		isSuccess = 0;

		if (textBoxPassword->Text == "")
		{
			throw 1;
		}

		if (textBoxPassword->Text->Length < 8)
		{
			throw 4;
		}

		if (textBoxPassword->Text != textBoxReapeatPassword->Text)
		{
			throw 2;
		}

		bool check = 0;
		bool& linkcheck = check;
		passwordValidate(textBoxPassword->Text, linkcheck);
		if (!check)
		{
			throw 3;
		}

		LoginForm::SetPassword(textBoxPassword->Text);

		isSuccess = 1;

		this->Close();
	}
	catch (int ex)
	{
		switch (ex)
		{
		case 1:
			MessageBox::Show("You have to write a password", "Password Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			break;

		case 2:
			MessageBox::Show("Password fields have to be the same", "Password Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			break;

		case 3:
			MessageBox::Show("Password can contain only English letters, digits and special symbols", "Password Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			break;

		case 4:
			MessageBox::Show("Password`s length has to be at least 8", "Password Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			break;
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message, ex->GetType()->Name, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Void ChangePasswordForm::textBoxPassword_TextChanged(System::Object^ sender, System::EventArgs^ e) {
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

	const int firstLocation = 550;
	labelPasswordStatus->Left = firstLocation - labelPasswordStatus->Width;
}