#pragma once

namespace TrabajoF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de FormGameOver_YouWin
	/// </summary>
	public ref class FormGameOver_YouWin : public System::Windows::Forms::Form
	{
	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//fondos you win//game over
		Bitmap^ bmpYouWin;
		Bitmap^ bmpGameOver;

		//music
		SoundPlayer^ spMusicGameOver;
		SoundPlayer^ spMusicYouWin;

		//resultado
		char resultado;

	public:
		FormGameOver_YouWin(char r)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			//buffer
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);

			//fondos you win/game over
			bmpYouWin = gcnew Bitmap("imagenes/fondo_youwin.png");
			bmpGameOver = gcnew Bitmap("imagenes/fondo_gameover.png");

			//audio
			spMusicGameOver = gcnew SoundPlayer("sonidos/audio_gameover.wav");
			spMusicYouWin = gcnew SoundPlayer("sonidos/audio_youwin.wav");

			//resultado
			resultado = r;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormGameOver_YouWin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Timer^ timer1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::SaddleBrown;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Agency FB", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Gold;
			this->button1->Location = System::Drawing::Point(476, 298);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 34);
			this->button1->TabIndex = 1;
			this->button1->TabStop = false;
			this->button1->Text = L"volver";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &FormGameOver_YouWin::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormGameOver_YouWin::timer1_Tick);
			// 
			// FormGameOver_YouWin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(563, 344);
			this->ControlBox = false;
			this->Controls->Add(this->button1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(579, 383);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(579, 383);
			this->Name = L"FormGameOver_YouWin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormGameOver_YouWin";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &FormGameOver_YouWin::FormGameOver_YouWin_FormClosed);
			this->Load += gcnew System::EventHandler(this, &FormGameOver_YouWin::FormGameOver_YouWin_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		
		//borrar
		buffer->Graphics->Clear(Color::WhiteSmoke);
		
		//dinujar
		if (resultado == 'Y') {//si gano
			this->Text = "EvadeCov-22: G A N A S T E";
			buffer->Graphics->DrawImage(bmpYouWin, 0, 0, bmpYouWin->Width * 0.44, bmpYouWin->Height * 0.46);//dibujando fondo you win
		}
		if (resultado == 'G') {//si perdio
			this->Text = "EvadeCov-22: P E R D I S T E";
			buffer->Graphics->DrawImage(bmpGameOver, 0, 0, bmpGameOver->Width * 0.44, bmpGameOver->Height * 0.43);//dibujando fondo game over
		}
		//Render
		buffer->Render(g);
	}
	private: System::Void FormGameOver_YouWin_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		//Cuando se presiona 'X' o se cierra el formulario 
		timer1->Enabled = false;
		this->Close();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = false;
		this->Close();
	}
	private: System::Void FormGameOver_YouWin_Load(System::Object^ sender, System::EventArgs^ e) {
		if (resultado == 'Y') {//si ganó
			spMusicYouWin->PlayLooping();
		}
		if (resultado == 'G') {//si perdio
			spMusicGameOver->PlayLooping();
		}
		
	}
};
}
