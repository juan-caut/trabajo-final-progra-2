#pragma once
#include"FormJuego.h"

namespace TrabajoF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormConfigurarNivel1
	/// </summary>
	public ref class FormConfigurarNivel1 : public System::Windows::Forms::Form
	{
	private:

		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//fondo del form
		Bitmap^ bmpFondo;

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::DomainUpDown^ domainUpDown1;
	private: System::Windows::Forms::DomainUpDown^ domainUpDown2;
	private: System::Windows::Forms::DomainUpDown^ domainUpDown3;
	private: System::Windows::Forms::DomainUpDown^ domainUpDown4;
	private: System::Windows::Forms::DomainUpDown^ domainUpDown5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	public:
		FormConfigurarNivel1(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			//buffer
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);

			//fondo
			bmpFondo = gcnew Bitmap("imagenes/fondo_configurarnivel1.png");

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormConfigurarNivel1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->domainUpDown1 = (gcnew System::Windows::Forms::DomainUpDown());
			this->domainUpDown2 = (gcnew System::Windows::Forms::DomainUpDown());
			this->domainUpDown3 = (gcnew System::Windows::Forms::DomainUpDown());
			this->domainUpDown4 = (gcnew System::Windows::Forms::DomainUpDown());
			this->domainUpDown5 = (gcnew System::Windows::Forms::DomainUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormConfigurarNivel1::timer1_Tick);
			// 
			// domainUpDown1
			// 
			this->domainUpDown1->BackColor = System::Drawing::Color::DarkRed;
			this->domainUpDown1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->domainUpDown1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->domainUpDown1->Font = (gcnew System::Drawing::Font(L"Agency FB", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->domainUpDown1->ForeColor = System::Drawing::SystemColors::Menu;
			this->domainUpDown1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->domainUpDown1->Items->Add(L"01");
			this->domainUpDown1->Items->Add(L"02");
			this->domainUpDown1->Items->Add(L"03");
			this->domainUpDown1->Items->Add(L"04");
			this->domainUpDown1->Items->Add(L"05");
			this->domainUpDown1->Location = System::Drawing::Point(279, 154);
			this->domainUpDown1->Name = L"domainUpDown1";
			this->domainUpDown1->ReadOnly = true;
			this->domainUpDown1->Size = System::Drawing::Size(45, 32);
			this->domainUpDown1->TabIndex = 1;
			this->domainUpDown1->Text = L"01";
			this->domainUpDown1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// domainUpDown2
			// 
			this->domainUpDown2->BackColor = System::Drawing::Color::DarkRed;
			this->domainUpDown2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->domainUpDown2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->domainUpDown2->Font = (gcnew System::Drawing::Font(L"Agency FB", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->domainUpDown2->ForeColor = System::Drawing::SystemColors::Menu;
			this->domainUpDown2->Items->Add(L"05");
			this->domainUpDown2->Items->Add(L"10");
			this->domainUpDown2->Items->Add(L"15");
			this->domainUpDown2->Items->Add(L"20");
			this->domainUpDown2->Items->Add(L"25");
			this->domainUpDown2->Items->Add(L"30");
			this->domainUpDown2->Items->Add(L"35");
			this->domainUpDown2->Items->Add(L"40");
			this->domainUpDown2->Items->Add(L"45");
			this->domainUpDown2->Items->Add(L"50");
			this->domainUpDown2->Items->Add(L"55");
			this->domainUpDown2->Items->Add(L"59");
			this->domainUpDown2->Location = System::Drawing::Point(344, 154);
			this->domainUpDown2->Name = L"domainUpDown2";
			this->domainUpDown2->ReadOnly = true;
			this->domainUpDown2->Size = System::Drawing::Size(45, 32);
			this->domainUpDown2->TabIndex = 2;
			this->domainUpDown2->Text = L"30";
			this->domainUpDown2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// domainUpDown3
			// 
			this->domainUpDown3->BackColor = System::Drawing::Color::DarkRed;
			this->domainUpDown3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->domainUpDown3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->domainUpDown3->Font = (gcnew System::Drawing::Font(L"Agency FB", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->domainUpDown3->ForeColor = System::Drawing::SystemColors::Menu;
			this->domainUpDown3->Items->Add(L"20");
			this->domainUpDown3->Items->Add(L"25");
			this->domainUpDown3->Items->Add(L"30");
			this->domainUpDown3->Items->Add(L"35");
			this->domainUpDown3->Items->Add(L"40");
			this->domainUpDown3->Items->Add(L"45");
			this->domainUpDown3->Items->Add(L"50");
			this->domainUpDown3->Location = System::Drawing::Point(111, 237);
			this->domainUpDown3->Name = L"domainUpDown3";
			this->domainUpDown3->ReadOnly = true;
			this->domainUpDown3->Size = System::Drawing::Size(45, 32);
			this->domainUpDown3->TabIndex = 3;
			this->domainUpDown3->Text = L"30";
			this->domainUpDown3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// domainUpDown4
			// 
			this->domainUpDown4->BackColor = System::Drawing::Color::DarkRed;
			this->domainUpDown4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->domainUpDown4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->domainUpDown4->Font = (gcnew System::Drawing::Font(L"Agency FB", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->domainUpDown4->ForeColor = System::Drawing::SystemColors::Menu;
			this->domainUpDown4->Items->Add(L"02");
			this->domainUpDown4->Items->Add(L"03");
			this->domainUpDown4->Items->Add(L"04");
			this->domainUpDown4->Items->Add(L"05");
			this->domainUpDown4->Location = System::Drawing::Point(305, 324);
			this->domainUpDown4->Name = L"domainUpDown4";
			this->domainUpDown4->ReadOnly = true;
			this->domainUpDown4->Size = System::Drawing::Size(45, 32);
			this->domainUpDown4->TabIndex = 4;
			this->domainUpDown4->Text = L"03";
			this->domainUpDown4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// domainUpDown5
			// 
			this->domainUpDown5->BackColor = System::Drawing::Color::DarkRed;
			this->domainUpDown5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->domainUpDown5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->domainUpDown5->Font = (gcnew System::Drawing::Font(L"Agency FB", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->domainUpDown5->ForeColor = System::Drawing::SystemColors::Menu;
			this->domainUpDown5->Items->Add(L"01");
			this->domainUpDown5->Items->Add(L"02");
			this->domainUpDown5->Items->Add(L"03");
			this->domainUpDown5->Location = System::Drawing::Point(462, 237);
			this->domainUpDown5->Name = L"domainUpDown5";
			this->domainUpDown5->ReadOnly = true;
			this->domainUpDown5->Size = System::Drawing::Size(48, 32);
			this->domainUpDown5->TabIndex = 5;
			this->domainUpDown5->Text = L"02";
			this->domainUpDown5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::SaddleBrown;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Agency FB", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Gold;
			this->button1->Location = System::Drawing::Point(507, 346);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(102, 38);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Continuar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &FormConfigurarNivel1::Click_Continuar);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::SaddleBrown;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Font = (gcnew System::Drawing::Font(L"Agency FB", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Gold;
			this->button2->Location = System::Drawing::Point(12, 346);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(102, 38);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Atrás";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &FormConfigurarNivel1::Click_Atras);
			// 
			// FormConfigurarNivel1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(621, 396);
			this->ControlBox = false;
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->domainUpDown5);
			this->Controls->Add(this->domainUpDown4);
			this->Controls->Add(this->domainUpDown3);
			this->Controls->Add(this->domainUpDown2);
			this->Controls->Add(this->domainUpDown1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(637, 435);
			this->MinimumSize = System::Drawing::Size(637, 435);
			this->Name = L"FormConfigurarNivel1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EvadeCov-22: Configurar Nivel 1";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &FormConfigurarNivel1::FormConfigurarNivel1_FormClosed);
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//borrar
		buffer->Graphics->Clear(Color::WhiteSmoke);

		//dibujar
		buffer->Graphics->DrawImage(bmpFondo, 0, 0, bmpFondo->Width * 0.9, bmpFondo->Height * 0.9);//dibujando fondo


		//Render
		buffer->Render(g);
	}
	private: System::Void FormConfigurarNivel1_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		timer1->Enabled = false;
		this->Close();
	}
private: System::Void Click_Continuar(System::Object^ sender, System::EventArgs^ e) {

	int nivel = 1;
	int minutos = Convert::ToInt32(domainUpDown1->Text);
	int segundos = Convert::ToInt32(domainUpDown2->Text);
	int cantAliados = Convert::ToInt32(domainUpDown3->Text);
	int cantHabitantes = Convert::ToInt32(domainUpDown4->Text);
	int cantAgentes = Convert::ToInt32(domainUpDown5->Text);

	//mostrar formulario del juego nivel 1
	this->Visible = false;
	Formulario1^ frmJuego = gcnew Formulario1(minutos, segundos, cantHabitantes, cantAliados, cantAgentes, 0, nivel);
	frmJuego->ShowDialog();
	this->Close();
}
private: System::Void Click_Atras(System::Object^ sender, System::EventArgs^ e) {
	timer1->Enabled = false;
	this->Close();
}
};
}
