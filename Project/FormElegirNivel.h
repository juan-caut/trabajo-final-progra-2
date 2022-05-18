#pragma once
#include"FormConfigurarNivel1.h"
#include"FormConfigurarNivel2.h"

namespace TrabajoF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormElegirNivel
	/// </summary>
	public ref class FormElegirNivel : public System::Windows::Forms::Form
	{
	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

		//fondo del form
		Bitmap^ bmpFondo;

		SoundPlayer^ spMusicFondo;

	public:
		FormElegirNivel(SoundPlayer^ spMusicInicio)
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
			bmpFondo = gcnew Bitmap("imagenes/fondo_elegirnivel.png");

			spMusicFondo = spMusicInicio;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormElegirNivel()
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormElegirNivel::timer1_Tick);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::SaddleBrown;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Agency FB", 25, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Gold;
			this->button1->Location = System::Drawing::Point(215, 144);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(212, 59);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Nivel 1";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &FormElegirNivel::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::SaddleBrown;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Font = (gcnew System::Drawing::Font(L"Agency FB", 25, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Gold;
			this->button2->Location = System::Drawing::Point(215, 240);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(212, 59);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Nivel 2";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &FormElegirNivel::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::SaddleBrown;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->Font = (gcnew System::Drawing::Font(L"Agency FB", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Gold;
			this->button3->Location = System::Drawing::Point(12, 346);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(102, 38);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Atrás";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &FormElegirNivel::button3_Click);
			// 
			// FormElegirNivel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(621, 396);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(637, 435);
			this->MinimumSize = System::Drawing::Size(637, 435);
			this->Name = L"FormElegirNivel";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EvadeCov-22: Elegir Nivel";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &FormElegirNivel::FormElegirNivel_FormClosed);
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
	private: System::Void FormElegirNivel_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		timer1->Enabled = false;
		this->Close();
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//
	this->Visible = false;
	FormConfigurarNivel1^ frmCN1 = gcnew FormConfigurarNivel1();
	frmCN1->ShowDialog();
	this->Visible = true;
	spMusicFondo->PlayLooping();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	timer1->Enabled = false;
	this->Close();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	this->Visible = false;
	FormConfigurarNivel2^ frmCN2 = gcnew FormConfigurarNivel2();
	frmCN2->ShowDialog();
	this->Visible = true;
	spMusicFondo->PlayLooping();
}
};
}
