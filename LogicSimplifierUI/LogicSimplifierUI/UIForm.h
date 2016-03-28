#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

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
			
			this->nInputDropDown->SelectedIndex = 0;
			
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

	private: System::Windows::Forms::ComboBox^  nInputDropDown;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckedListBox^  highOutCheckedListBox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::CheckedListBox^  dontCareCheckedListBox;



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
			this->nInputDropDown = (gcnew System::Windows::Forms::ComboBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->highOutCheckedListBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dontCareCheckedListBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button1->Location = System::Drawing::Point(-2, 998);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(211, 46);
			this->button1->TabIndex = 2;
			this->button1->Text = L"confirm";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &UIForm::button1_Click);
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
			// nInputDropDown
			// 
			this->nInputDropDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->nInputDropDown->FormattingEnabled = true;
			this->nInputDropDown->IntegralHeight = false;
			this->nInputDropDown->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"2", L"3", L"4" });
			this->nInputDropDown->Location = System::Drawing::Point(211, 0);
			this->nInputDropDown->MaxDropDownItems = 3;
			this->nInputDropDown->Name = L"nInputDropDown";
			this->nInputDropDown->Size = System::Drawing::Size(55, 33);
			this->nInputDropDown->TabIndex = 6;
			this->nInputDropDown->SelectedIndexChanged += gcnew System::EventHandler(this, &UIForm::nInputDropDown_SelectedIndexChanged);
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
			// highOutCheckedListBox
			// 
			this->highOutCheckedListBox->FormattingEnabled = true;
			this->highOutCheckedListBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"00", L"01", L"10", L"11" });
			this->highOutCheckedListBox->Location = System::Drawing::Point(0, 131);
			this->highOutCheckedListBox->Name = L"highOutCheckedListBox";
			this->highOutCheckedListBox->Size = System::Drawing::Size(137, 888);
			this->highOutCheckedListBox->TabIndex = 8;
			this->highOutCheckedListBox->Click += gcnew System::EventHandler(this, &UIForm::yyy);
			this->highOutCheckedListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &UIForm::highOutCheckedListBox_UpdateDontCares);
			this->highOutCheckedListBox->Leave += gcnew System::EventHandler(this, &UIForm::highOutCheckedListBox_UpdateDontCares);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::MintCream;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label2->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label2->Location = System::Drawing::Point(-5, 76);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(148, 54);
			this->label2->TabIndex = 9;
			this->label2->Text = L"High Output\r\nCombinations";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label2->Click += gcnew System::EventHandler(this, &UIForm::yyy);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::MintCream;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label3->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label3->Location = System::Drawing::Point(142, 76);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 54);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Don\'t\r\nCare\r\n";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label3->Click += gcnew System::EventHandler(this, &UIForm::yyy);
			// 
			// dontCareCheckedListBox
			// 
			this->dontCareCheckedListBox->FormattingEnabled = true;
			this->dontCareCheckedListBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"#", L"#", L"#", L"#" });
			this->dontCareCheckedListBox->Location = System::Drawing::Point(142, 131);
			this->dontCareCheckedListBox->Name = L"dontCareCheckedListBox";
			this->dontCareCheckedListBox->Size = System::Drawing::Size(64, 888);
			this->dontCareCheckedListBox->TabIndex = 11;
			this->dontCareCheckedListBox->Click += gcnew System::EventHandler(this, &UIForm::yyy);
			// 
			// UIForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(974, 1043);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dontCareCheckedListBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->nInputDropDown);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->highOutCheckedListBox);
			this->Name = L"UIForm";
			this->Text = L"UIForm";
			this->Load += gcnew System::EventHandler(this, &UIForm::UIForm_Load);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: int get_nInputs() {
		return  int::Parse(this->nInputDropDown->GetItemText(this->nInputDropDown->SelectedItem));
	}

	private: std::vector<char> get_outputSet() {

		std::vector<char> outputSet(1 << get_nInputs(), '0');

		IEnumerator^ dontCareEnum = this->dontCareCheckedListBox->CheckedIndices->GetEnumerator();
		while (dontCareEnum->MoveNext()) {
			int thisIndex = *safe_cast<Int32^>(dontCareEnum->Current);
			outputSet[thisIndex] = '*';
		}

		IEnumerator^ highOutEnum = this->highOutCheckedListBox->CheckedIndices->GetEnumerator();
		while (highOutEnum->MoveNext()) {
			int thisIndex = *safe_cast<Int32^>(highOutEnum->Current);
			outputSet[thisIndex] = '1';
		}
		return outputSet;
	}

	private: std::vector<std::vector<char>> get_Kmap() {

	}

	private: System::Void UIForm_Load(System::Object^  sender, System::EventArgs^  e) {

	}

	private: System::Void nInputDropDown_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		this->highOutCheckedListBox->Items->Clear();
		this->dontCareCheckedListBox->Items->Clear();

		int nInputs = get_nInputs();

		std::string str("");
		for (int i = 0; i < 1 << nInputs; ++i) {
			for (int mask = (1 << (nInputs - 1)); mask >= 1; mask = mask >> 1) {
				if (mask & i) { str += "1"; }
				else { str += "0"; }
			}

			System::String^ converted = gcnew String(str.c_str());
			this->highOutCheckedListBox->Items->Add( converted );
			this->dontCareCheckedListBox->Items->Add( L"#" );
			str = "";
		}
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		std::vector<char> outputSet = get_outputSet();

		for (int i = 0; i < outputSet.size(); ++i) {
			std::cout << outputSet[i] << std::endl;
		}
	}

	private: System::Void highOutCheckedListBox_UpdateDontCares(System::Object^  sender, System::EventArgs^  e) {

		int last = 0;
		IEnumerator^ highOutEnum = this->highOutCheckedListBox->Items->GetEnumerator();
		for (Int32 i = 0; i < (1 << get_nInputs()); ++i) {

			bool highOutChecked = (this->highOutCheckedListBox->GetItemCheckState(i) == System::Windows::Forms::CheckState::Checked);
			bool dontCareChecked = (this->dontCareCheckedListBox->GetItemCheckState(0) == System::Windows::Forms::CheckState::Checked);

			this->dontCareCheckedListBox->Items->RemoveAt(0);

			if (highOutChecked) {
				this->dontCareCheckedListBox->Items->Add(L"--", dontCareChecked);
			}
			else {
				this->dontCareCheckedListBox->Items->Add(L"#", dontCareChecked);
			}
		
		}

	}

private: System::Void yyy(System::Object^  sender, System::EventArgs^  e) {
}
};
}