#pragma once
#include<ctime>
#include"Controlador_Juego.h"
#include"FormGameOver_YouWin.h"

namespace TrabajoF {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de Formulario1
	/// </summary>
	
	public ref class Formulario1 : public System::Windows::Forms::Form
	{
	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmaps Imagenes/Sprites
		Bitmap^ bmpLider;
		Bitmap^ bmpEnfermera;
		Bitmap^ bmpVirus;
		Bitmap^ bmpCiudadano;
		Bitmap^ bmpBalas;

		//Mapa
		Bitmap^ bmpMapa;

		//controlador
		CControlador* controlador;

		//music
		SoundPlayer^ spMusicLevel1;
		SoundPlayer^ spMusicLevel2;

		//Nivel
		int nivel;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Timer^ timerTemporizador;
	private: System::Windows::Forms::Timer^ timerNivel2;
	private: System::Windows::Forms::Timer^ timerAgentesNivel2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;


	private: System::Windows::Forms::Timer^ timerNivel1;

	public:
		Formulario1(int minutos,int segundos, int cantHabitantes, int cantAliados, int cantAgentes, int cantVacunas, int _nivel)
		{
			srand(time(NULL));
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			//buffer
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);

			//Nivel
			nivel = _nivel;

			//mapa
			bmpMapa = gcnew Bitmap("imagenes/mapa1.png");

			//sprites
			bmpLider = gcnew Bitmap("imagenes/doctor.png");
			bmpEnfermera = gcnew Bitmap("imagenes/enfermera1.png");
			bmpVirus = gcnew Bitmap("imagenes/virus.png");
			bmpCiudadano = gcnew Bitmap("imagenes/habitante.png");
			bmpBalas = gcnew Bitmap("imagenes/bala.png");

			//controlador
			controlador = new CControlador(bmpLider, bmpCiudadano, minutos, segundos, cantHabitantes, cantAliados, cantAgentes, cantVacunas, nivel);

			//Music
			spMusicLevel1 = gcnew SoundPlayer("sonidos/audio_level1.wav");
			spMusicLevel2 = gcnew SoundPlayer("sonidos/audio_level2.wav");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Formulario1()
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
			this->timerNivel1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->timerTemporizador = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerNivel2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerAgentesNivel2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timerNivel1
			// 
			this->timerNivel1->Tick += gcnew System::EventHandler(this, &Formulario1::timerNivel1_Tick);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::SlateGray;
			this->button1->Enabled = false;
			this->button1->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(614, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 33);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Firebrick;
			this->button2->Enabled = false;
			this->button2->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Gold;
			this->button2->Location = System::Drawing::Point(306, 0);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 54);
			this->button2->TabIndex = 1;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::SlateGray;
			this->button3->Enabled = false;
			this->button3->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(12, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(115, 33);
			this->button3->TabIndex = 2;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = false;
			// 
			// timerTemporizador
			// 
			this->timerTemporizador->Enabled = true;
			this->timerTemporizador->Interval = 1000;
			this->timerTemporizador->Tick += gcnew System::EventHandler(this, &Formulario1::timerrTemporizador);
			// 
			// timerNivel2
			// 
			this->timerNivel2->Tick += gcnew System::EventHandler(this, &Formulario1::timerNivel2_Tick);
			// 
			// timerAgentesNivel2
			// 
			this->timerAgentesNivel2->Interval = 2000;
			this->timerAgentesNivel2->Tick += gcnew System::EventHandler(this, &Formulario1::timerAgentesNivel2_Tick);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button4->Enabled = false;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::DarkRed;
			this->button4->Location = System::Drawing::Point(332, 585);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(88, 49);
			this->button4->TabIndex = 3;
			this->button4->Text = L"bt4";
			this->button4->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button4->UseVisualStyleBackColor = false;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button6->Enabled = false;
			this->button6->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button6->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->button6->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::Color::DarkRed;
			this->button6->Location = System::Drawing::Point(520, 585);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(88, 49);
			this->button6->TabIndex = 5;
			this->button6->Text = L"bt6";
			this->button6->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button6->UseVisualStyleBackColor = false;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button5->Enabled = false;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::DarkRed;
			this->button5->Location = System::Drawing::Point(426, 585);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(88, 49);
			this->button5->TabIndex = 6;
			this->button5->Text = L"bt5";
			this->button5->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button5->UseVisualStyleBackColor = false;
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button7->Enabled = false;
			this->button7->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button7->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->button7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::Color::DarkRed;
			this->button7->Location = System::Drawing::Point(614, 585);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(88, 49);
			this->button7->TabIndex = 7;
			this->button7->Text = L"bt7";
			this->button7->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Visible = false;
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button8->Enabled = false;
			this->button8->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button8->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->button8->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->ForeColor = System::Drawing::Color::DarkRed;
			this->button8->Location = System::Drawing::Point(28, 585);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(88, 49);
			this->button8->TabIndex = 8;
			this->button8->Text = L"bt8";
			this->button8->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Visible = false;
			// 
			// Formulario1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(776, 658);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(792, 697);
			this->MinimumSize = System::Drawing::Size(792, 697);
			this->Name = L"Formulario1";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EvadeCov-22: Jugar";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Formulario1::Formulario1_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Formulario1::Formulario1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Formulario1::Formulario1_KeyDown);
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void timerNivel1_Tick(System::Object^ sender, System::EventArgs^ e) {

		//borrar
		buffer->Graphics->Clear(Color::WhiteSmoke);
		
		//mover
		controlador->moverVirus(buffer->Graphics);
		controlador->moverAliados(buffer->Graphics);
		controlador->moverCiudadanos(buffer->Graphics);
		
		//dibujar
		buffer->Graphics->DrawImage(bmpMapa, 0, 0, bmpMapa->Width * 0.9, bmpMapa->Height * 0.9);//dibujando mapa
		
		controlador->getLider()->dibujar(buffer->Graphics, bmpLider);
		controlador->dibujarCiudadanos(buffer->Graphics, bmpCiudadano);
		controlador->dibujarEnfermeras(buffer->Graphics, bmpEnfermera);
		controlador->dibujarVirus(buffer->Graphics, bmpVirus);

		///reportes 
		button1->Text = "Puntaje: " + controlador->getPuntaje();//visualizador del puntaje
		button2->Text = "Nivel 1";//Visualizador de nivel
		button3->Text = "" + controlador->getMinutos() + ":" + controlador->getSegundos();//visualizador del tiempo
		button4->Text = "" + controlador->getcantAliados();//visualizador de la cantidad de aliados disponibles
		button5->Text = "" + controlador->getAliadosMisionCumplido();//visualizador de la cantidad de aliados con mision cumplido
		button6->Text = "" + controlador->getAliadosFallecidos();//visualizador de la cantidad de aliados fallecidos
		
		//Render
		buffer->Render(g);
		
		//comprobar puntaje	
		if (controlador->getPuntaje() >= 100) {
			timerNivel1->Enabled = false;										                   
			timerTemporizador->Enabled = false;	
			FormGameOver_YouWin^ fgoyw = gcnew FormGameOver_YouWin('Y');
			fgoyw->ShowDialog();
			this->Close();
		}
	}
	private: System::Void Formulario1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (nivel == 1) {
			switch (e->KeyCode)
			{
			case Keys::A: case Keys::Left:
				controlador->getLider()->mover(buffer->Graphics, 'A'); break;
			case Keys::D: case Keys::Right:
				controlador->getLider()->mover(buffer->Graphics, 'D'); break;
			case Keys::W: case Keys::Up:
				controlador->getLider()->mover(buffer->Graphics, 'W'); break;
			case Keys::S: case Keys::Down:
				controlador->getLider()->mover(buffer->Graphics, 'S'); break;
			case Keys::Space:
				controlador->addAliado(bmpEnfermera);
				controlador->addAgente(bmpVirus);
				break;
			}
		}
		else if (nivel == 2) {
			switch (e->KeyCode)
			{
			case Keys::A: case Keys::Left:
				controlador->getLider()->mover(buffer->Graphics, 'A'); break;
			case Keys::D: case Keys::Right:
				controlador->getLider()->mover(buffer->Graphics, 'D'); break;
			case Keys::X:
				controlador->addVacunas(bmpBalas); break;

			case Keys::Space:
				controlador->addAliado(bmpEnfermera);
				break;
			}
		}
	}
private: System::Void Formulario1_Load(System::Object^ sender, System::EventArgs^ e) {

	if      (nivel == 1) { 
		spMusicLevel1->PlayLooping();//iniciar audio
		timerNivel1->Enabled = true;
		button4->BackgroundImage = gcnew Bitmap("imagenes/fondo_botonA.png");//fondo del button4
		button5->BackgroundImage = gcnew Bitmap("imagenes/fondo_botonAMC.png");//fondo del button5
		button6->BackgroundImage = gcnew Bitmap("imagenes/fondo_botonAF.png");//fondo del button6
	}
	else if (nivel == 2) { 
		spMusicLevel2->PlayLooping();//iniciar audio
		timerNivel2->Enabled = true; 
		timerAgentesNivel2->Enabled = true;
		button4->BackgroundImage = gcnew Bitmap("imagenes/fondo_botonAMC.png");//fondo del button4
		button5->BackgroundImage = gcnew Bitmap("imagenes/fondo_botonAF.png");//fondo del button5
		button6->BackgroundImage = gcnew Bitmap("imagenes/fondo_botonEM.png");//fondo del button6
		button7->Visible = true; button7->BackgroundImage = gcnew Bitmap("imagenes/fondo_botonA.png");//fondo del button7
		button8->Visible = true; button8->BackgroundImage = gcnew Bitmap("imagenes/fondo_botonV.png");//fondo del button8
	}
}
private: System::Void timerrTemporizador(System::Object^ sender, System::EventArgs^ e) {

	if (controlador->getMinutos() >= 0) {                 
														  
		if (controlador->getSegundos() >= 0) {			  
			controlador->disminuirSegundos();			  
		}												  
		if (controlador->getSegundos() == -1) {			  
			controlador->restaurarSegundos();			  
			controlador->disminuirMinutos();			  
		}												  
	}
	if (nivel == 1) {
		if (controlador->getMinutos() == 0 && controlador->getSegundos() == 0 || controlador->getcantAliados() == 0) {
			button3->Text = "0" + controlador->getMinutos() + ":" + controlador->getSegundos();//visualizador de tiempo
			timerNivel1->Enabled = false;
			timerNivel2->Enabled = false;
			timerTemporizador->Enabled = false;
			timerAgentesNivel2->Enabled = false;
			FormGameOver_YouWin^ fgoyw = gcnew FormGameOver_YouWin('G');
			fgoyw->ShowDialog();
			this->Close();
		}
	}
	else if (nivel == 2) {
		if (controlador->getMinutos() == 0 && controlador->getSegundos() == 0 || controlador->getcantAliados() == 0 || controlador->getcantVacunas() == 0) {
			button3->Text = "0" + controlador->getMinutos() + ":" + controlador->getSegundos();//visualizador de tiempo
			timerNivel1->Enabled = false;
			timerNivel2->Enabled = false;
			timerTemporizador->Enabled = false;
			timerAgentesNivel2->Enabled = false;
			FormGameOver_YouWin^ fgoyw = gcnew FormGameOver_YouWin('G');
			fgoyw->ShowDialog();
			this->Close();
		}
	}

}
private: System::Void Formulario1_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	//Cuando se presiona 'X' o se cierra el formulario 
	spMusicLevel1->Stop();
	spMusicLevel2->Stop();
	timerNivel1->Enabled = false;
	timerTemporizador->Enabled = false;
	timerNivel2->Enabled = false;
	timerAgentesNivel2->Enabled = false;
	this->Close();
}

private: System::Void timerNivel2_Tick(System::Object^ sender, System::EventArgs^ e) {

	//borrar
	buffer->Graphics->Clear(Color::WhiteSmoke);

	//mover
	controlador->moverVirus(buffer->Graphics);
	controlador->moverAliados(buffer->Graphics);
	controlador->moverCiudadanos(buffer->Graphics);
	controlador->moverVacunas(buffer->Graphics);

	//dibujar
	buffer->Graphics->DrawImage(bmpMapa, 0, 0, bmpMapa->Width * 0.9, bmpMapa->Height * 0.9);//dibujando mapa

	controlador->getLider()->dibujar(buffer->Graphics, bmpLider);
	controlador->dibujarCiudadanos(buffer->Graphics, bmpCiudadano);
	controlador->dibujarEnfermeras(buffer->Graphics, bmpEnfermera);
	controlador->dibujarVirus(buffer->Graphics, bmpVirus);
	controlador->dibujarVacunas(buffer->Graphics, bmpBalas);

	//reportes
	button1->Text = "Puntaje: " + controlador->getPuntaje();//visualizador del puntaje
	button2->Text = "Nivel 2";//Visualizador de nivel
	button3->Text = controlador->getMinutos() + ":" + controlador->getSegundos();//visualizador del tiempo
	button7->Text = "" + controlador->getcantAliados();//visualizador de la cantidad de aliados disponibles
	button4->Text = "" + controlador->getAliadosMisionCumplido();//visualizador de la cantidad de aliados con mision cumplido
	button5->Text = "" + controlador->getAliadosFallecidos();//visualizador de la cantidad de aliados con mision cumplido
	button6->Text = "" + controlador->getAgentesMuertos();//visualizador de la cantidad de aliados fallecidos
	button8->Text = "" + controlador->getcantVacunas();//visualizador de la cantidad de vacunas

	//Render
	buffer->Render(g);

	//comprobar puntaje	
	if (controlador->getPuntaje() >= 100) {
		timerNivel2->Enabled = false;
		timerTemporizador->Enabled = false;
		timerAgentesNivel2->Enabled = false;
		FormGameOver_YouWin^ fgoyw = gcnew FormGameOver_YouWin('Y');
		fgoyw->ShowDialog();
		this->Close();
	}
}
private: System::Void timerAgentesNivel2_Tick(System::Object^ sender, System::EventArgs^ e) {
	//En el nivel 2, agrega agente(virus) cada 2 segundos
	controlador->addAgente(bmpVirus);
}
};
}
