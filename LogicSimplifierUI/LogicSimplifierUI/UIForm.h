#pragma once
#include <iostream>
#include <string>
#include <sstream>

namespace LogicSimplifierUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UIForm
	/// </summary>
	public ref class UIForm : public System::Windows::Forms::Form
	{
	public:
		UIForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UIForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckedListBox^  checkedListBox1;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UIForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button1->Location = System::Drawing::Point(-2, 998);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(227, 46);
			this->button1->TabIndex = 2;
			this->button1->Text = L"confirm";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// toolStrip1
			// 
			this->toolStrip1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripButton1 });
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(974, 39);
			this->toolStrip1->TabIndex = 4;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(36, 36);
			this->toolStripButton1->Text = L"toolStripButton1";
			// 
			// comboBox1
			// 
			this->comboBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->IntegralHeight = false;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"2", L"3", L"4" });
			this->comboBox1->Location = System::Drawing::Point(211, 0);
			this->comboBox1->MaxDropDownItems = 3;
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(55, 33);
			this->comboBox1->TabIndex = 6;
			this->comboBox1->SelectedIndex = 0;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &UIForm::comboBox1_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label1->Location = System::Drawing::Point(103, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 31);
			this->label1->TabIndex = 7;
			this->label1->Text = L"inputs :";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"00", L"01", L"10", L"11" });
			this->checkedListBox1->Location = System::Drawing::Point(0, 70);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(219, 940);
			this->checkedListBox1->TabIndex = 8;
			// 
			// UIForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(974, 1043);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->checkedListBox1);
			this->Name = L"UIForm";
			this->Text = L"UIForm";
			this->Load += gcnew System::EventHandler(this, &UIForm::UIForm_Load);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void UIForm_Load(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		this->checkedListBox1->Items->Clear();
		int nInputs = int::Parse(this->comboBox1->GetItemText(this->comboBox1->SelectedItem));
		
		std::string str("");
		for (int i = 0; i < 1 << nInputs; ++i) {
			for (int mask = (1 << (nInputs - 1)); mask >= 1; mask = mask >> 1) {
				if (mask & i) { str += "1"; }
				else { str += "0"; }
			}

			System::String^ converted = gcnew String(str.c_str());
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(1) { converted });
			str = "";
		}
	}
};
}
