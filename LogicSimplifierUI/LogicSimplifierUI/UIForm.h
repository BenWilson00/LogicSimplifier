#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

// Get the simplified logical expression for an output set, based on 1's or 0's as specified by <lookUp>.
std::vector< std::vector<char> > getLogic(std::vector<char> outputSet, int nInputs, char lookUp);

// If <item> is in <vec>, return index of <item>, else return -1.
template<typename T> int get_pos(std::vector<T> vec, T item);

// Print an integer in binary with <len> digits.
void printBinary(int n, int len);

namespace LogicSimplifierUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// This GUI allows you to enter a variable number of inputs, check boxes for 
	/// high outputs or outputs for which you don't care about the state, then
	/// generates a simplified logical expression for the gates required.
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


	private: System::Windows::Forms::Button^  confirmButton;

	private: System::Windows::Forms::ComboBox^  nInputDropDown;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckedListBox^  highOutCheckedListBox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::CheckedListBox^  dontCareCheckedListBox;
	private: System::Windows::Forms::Label^  outputResultBox;


	private: System::Windows::Forms::CheckBox^  sumOrProductCheckBox;

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
			this->confirmButton = (gcnew System::Windows::Forms::Button());
			this->nInputDropDown = (gcnew System::Windows::Forms::ComboBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->highOutCheckedListBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dontCareCheckedListBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->outputResultBox = (gcnew System::Windows::Forms::Label());
			this->sumOrProductCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// confirmButton
			// 
			this->confirmButton->BackColor = System::Drawing::SystemColors::ControlLight;
			this->confirmButton->Location = System::Drawing::Point(0, 970);
			this->confirmButton->Name = L"confirmButton";
			this->confirmButton->Size = System::Drawing::Size(318, 75);
			this->confirmButton->TabIndex = 2;
			this->confirmButton->Text = L"confirm";
			this->confirmButton->UseVisualStyleBackColor = false;
			this->confirmButton->Click += gcnew System::EventHandler(this, &UIForm::confirmButton_Click);
			// 
			// nInputDropDown
			// 
			this->nInputDropDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->nInputDropDown->FormattingEnabled = true;
			this->nInputDropDown->IntegralHeight = false;
			this->nInputDropDown->Items->AddRange(gcnew cli::array< System::Object^  >(7) { L"2", L"3", L"4", L"5", L"6", L"7", L"8" });
			this->nInputDropDown->Location = System::Drawing::Point(215, 4);
			this->nInputDropDown->Margin = System::Windows::Forms::Padding(0);
			this->nInputDropDown->MaxDropDownItems = 6;
			this->nInputDropDown->Name = L"nInputDropDown";
			this->nInputDropDown->Size = System::Drawing::Size(90, 33);
			this->nInputDropDown->TabIndex = 6;
			this->nInputDropDown->SelectedIndexChanged += gcnew System::EventHandler(this, &UIForm::nInputDropDown_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::MintCream;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label1->Location = System::Drawing::Point(3, 4);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(206, 38);
			this->label1->TabIndex = 7;
			this->label1->Text = L"inputs :";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// highOutCheckedListBox
			// 
			this->highOutCheckedListBox->FormattingEnabled = true;
			this->highOutCheckedListBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"00", L"01", L"10", L"11" });
			this->highOutCheckedListBox->Location = System::Drawing::Point(0, 103);
			this->highOutCheckedListBox->Name = L"highOutCheckedListBox";
			this->highOutCheckedListBox->Size = System::Drawing::Size(209, 888);
			this->highOutCheckedListBox->TabIndex = 8;
			this->highOutCheckedListBox->Click += gcnew System::EventHandler(this, &UIForm::yyy);
			this->highOutCheckedListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &UIForm::highOutCheckedListBox_UpdateDontCares);
			this->highOutCheckedListBox->Leave += gcnew System::EventHandler(this, &UIForm::highOutCheckedListBox_UpdateDontCares);
			// 
			// label2
			// 
			this->label2->AllowDrop = true;
			this->label2->BackColor = System::Drawing::Color::MintCream;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label2->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label2->Location = System::Drawing::Point(0, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(209, 54);
			this->label2->TabIndex = 9;
			this->label2->Text = L"High Output\r\nCombinations";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label2->Click += gcnew System::EventHandler(this, &UIForm::yyy);
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::MintCream;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label3->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label3->Location = System::Drawing::Point(215, 46);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(94, 54);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Don\'t\r\nCare\r\n";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label3->Click += gcnew System::EventHandler(this, &UIForm::yyy);
			// 
			// dontCareCheckedListBox
			// 
			this->dontCareCheckedListBox->FormattingEnabled = true;
			this->dontCareCheckedListBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"#", L"#", L"#", L"#" });
			this->dontCareCheckedListBox->Location = System::Drawing::Point(215, 103);
			this->dontCareCheckedListBox->Name = L"dontCareCheckedListBox";
			this->dontCareCheckedListBox->Size = System::Drawing::Size(94, 888);
			this->dontCareCheckedListBox->TabIndex = 11;
			this->dontCareCheckedListBox->Click += gcnew System::EventHandler(this, &UIForm::yyy);
			// 
			// outputResultBox
			// 
			this->outputResultBox->BackColor = System::Drawing::SystemColors::ControlLight;
			this->outputResultBox->Cursor = System::Windows::Forms::Cursors::No;
			this->outputResultBox->Location = System::Drawing::Point(338, 46);
			this->outputResultBox->Name = L"outputResultBox";
			this->outputResultBox->Size = System::Drawing::Size(624, 107);
			this->outputResultBox->TabIndex = 12;
			this->outputResultBox->Text = L"output goes here";
			// 
			// sumOrProductCheckBox
			// 
			this->sumOrProductCheckBox->BackColor = System::Drawing::Color::MintCream;
			this->sumOrProductCheckBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.5F));
			this->sumOrProductCheckBox->Location = System::Drawing::Point(325, 978);
			this->sumOrProductCheckBox->Margin = System::Windows::Forms::Padding(0);
			this->sumOrProductCheckBox->Name = L"sumOrProductCheckBox";
			this->sumOrProductCheckBox->Size = System::Drawing::Size(656, 60);
			this->sumOrProductCheckBox->TabIndex = 15;
			this->sumOrProductCheckBox->Text = L"Leave unchecked for Sum of Products; check for Product of Sums";
			this->sumOrProductCheckBox->UseVisualStyleBackColor = false;
			// 
			// UIForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(974, 1043);
			this->Controls->Add(this->sumOrProductCheckBox);
			this->Controls->Add(this->outputResultBox);
			this->Controls->Add(this->confirmButton);
			this->Controls->Add(this->dontCareCheckedListBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->nInputDropDown);
			this->Controls->Add(this->highOutCheckedListBox);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1000, 1114);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(1000, 1114);
			this->Name = L"UIForm";
			this->ShowInTaskbar = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"UIForm";
			this->ResumeLayout(false);

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

	private: System::Void outputResults(std::vector< std::vector<char> > values, bool sumOfProducts) {
		std::string alphabet = "ABCDEFGH";
		std::string str;
		int first;
		if (!sumOfProducts) { str += "("; }
		for (int i = 0; i != values.size(); ++i) {
			first = std::min(get_pos(values[i], '0'), get_pos(values[i], '1'));
			if (first == -1) { first = get_pos(values[i], '0'); }
			if (first == -1) { first = get_pos(values[i], '1'); }
			for (int j = 0; j != values[i].size(); ++j) {
				if (values[i][j] == '1') {
					if (!sumOfProducts && (j != first)) { str += " + "; }
					str += alphabet[j];
					
				}
				else if (values[i][j] == '0') {
					if (!sumOfProducts && (j != first)) { str += " + "; }
					str += alphabet[j];
					str += '\'';
					
				}
				
			}
			if (i != values.size() - 1) {
				if (sumOfProducts) { str += " + "; }
				else { str += ")("; }
			}
		}
		if (!sumOfProducts) { str += ")"; }
		System::String^ converted = gcnew String(str.c_str());
		this->outputResultBox->Text = converted;
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

	private: System::Void confirmButton_Click(System::Object^  sender, System::EventArgs^  e) {

		std::vector<char> outputSet = get_outputSet();

		for (int i = 0; i < outputSet.size(); ++i) {
			//std::cout << outputSet[i] << std::endl;
		}

		std::vector< std::vector<char> > sumOfProducts = getLogic(outputSet, get_nInputs(), '1');
		std::vector< std::vector<char> > productOfSums = getLogic(outputSet, get_nInputs(), '0');
	
		if (this->sumOrProductCheckBox->Checked) { outputResults(productOfSums, false); }
		else { outputResults(sumOfProducts, true); }
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

