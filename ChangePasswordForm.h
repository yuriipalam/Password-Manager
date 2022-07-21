#pragma once
#include "passwordValidating.h"
#include "LoginForm.h"

namespace PassSaver {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ ChangePasswordForm
	/// </summary>
	public ref class ChangePasswordForm : public System::Windows::Forms::Form
	{
	public:
		ChangePasswordForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		static bool GetSuccessResult()
		{
			return isSuccess;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ChangePasswordForm()
		{
			if (components)
			{
				delete components;
			}
		}
		static bool isSuccess;

	private: System::Windows::Forms::Label^ labelPasswordStatus;
	protected:
	private: System::Windows::Forms::Label^ labelRepeatPassword;
	private: System::Windows::Forms::TextBox^ textBoxReapeatPassword;
	private: System::Windows::Forms::Button^ buttonLaunch;
	private: System::Windows::Forms::Label^ labelPassword;
	private: System::Windows::Forms::TextBox^ textBoxPassword;

	protected:



	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ChangePasswordForm::typeid));
			this->labelPasswordStatus = (gcnew System::Windows::Forms::Label());
			this->labelRepeatPassword = (gcnew System::Windows::Forms::Label());
			this->textBoxReapeatPassword = (gcnew System::Windows::Forms::TextBox());
			this->buttonLaunch = (gcnew System::Windows::Forms::Button());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// labelPasswordStatus
			// 
			this->labelPasswordStatus->AutoSize = true;
			this->labelPasswordStatus->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->labelPasswordStatus->Location = System::Drawing::Point(547, 85);
			this->labelPasswordStatus->Name = L"labelPasswordStatus";
			this->labelPasswordStatus->Size = System::Drawing::Size(0, 21);
			this->labelPasswordStatus->TabIndex = 20;
			this->labelPasswordStatus->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// labelRepeatPassword
			// 
			this->labelRepeatPassword->AutoSize = true;
			this->labelRepeatPassword->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelRepeatPassword->Location = System::Drawing::Point(165, 147);
			this->labelRepeatPassword->Name = L"labelRepeatPassword";
			this->labelRepeatPassword->Size = System::Drawing::Size(129, 21);
			this->labelRepeatPassword->TabIndex = 18;
			this->labelRepeatPassword->Text = L"Repeat Password";
			// 
			// textBoxReapeatPassword
			// 
			this->textBoxReapeatPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->textBoxReapeatPassword->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxReapeatPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->textBoxReapeatPassword->Location = System::Drawing::Point(169, 171);
			this->textBoxReapeatPassword->Name = L"textBoxReapeatPassword";
			this->textBoxReapeatPassword->Size = System::Drawing::Size(375, 21);
			this->textBoxReapeatPassword->TabIndex = 13;
			this->textBoxReapeatPassword->UseSystemPasswordChar = true;
			// 
			// buttonLaunch
			// 
			this->buttonLaunch->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->buttonLaunch->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->buttonLaunch->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonLaunch->ForeColor = System::Drawing::SystemColors::Control;
			this->buttonLaunch->Location = System::Drawing::Point(169, 209);
			this->buttonLaunch->Name = L"buttonLaunch";
			this->buttonLaunch->Size = System::Drawing::Size(375, 56);
			this->buttonLaunch->TabIndex = 16;
			this->buttonLaunch->Text = L"Confirm";
			this->buttonLaunch->UseVisualStyleBackColor = false;
			this->buttonLaunch->Click += gcnew System::EventHandler(this, &ChangePasswordForm::buttonLaunch_Click);
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->ForeColor = System::Drawing::Color::Gainsboro;
			this->labelPassword->Location = System::Drawing::Point(165, 85);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(113, 21);
			this->labelPassword->TabIndex = 15;
			this->labelPassword->Text = L"New Password";
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->textBoxPassword->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->textBoxPassword->Location = System::Drawing::Point(169, 109);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->Size = System::Drawing::Size(375, 21);
			this->textBoxPassword->TabIndex = 12;
			this->textBoxPassword->UseSystemPasswordChar = true;
			this->textBoxPassword->TextChanged += gcnew System::EventHandler(this, &ChangePasswordForm::textBoxPassword_TextChanged);
			// 
			// ChangePasswordForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->ClientSize = System::Drawing::Size(710, 357);
			this->Controls->Add(this->labelPasswordStatus);
			this->Controls->Add(this->labelRepeatPassword);
			this->Controls->Add(this->textBoxReapeatPassword);
			this->Controls->Add(this->buttonLaunch);
			this->Controls->Add(this->labelPassword);
			this->Controls->Add(this->textBoxPassword);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ChangePasswordForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Change Password";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonLaunch_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void textBoxPassword_TextChanged(System::Object^ sender, System::EventArgs^ e);
};
}
