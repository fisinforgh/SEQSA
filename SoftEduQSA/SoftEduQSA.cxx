/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
// NOTICE OF COPYRIGHT                                                         //
//                                                                             //
// Copyright (C) 2023                                                          //
//                                                                             //
// Authors:								       //
//   [1] AndrésFelipe García Cárdenas*					       //
//   [2] Julian Andrés Salamanca Bernal**                                      //
//   [3] Diego Julián Rodríguez-Patarroyo***				       //         			           
//                                                                             //
//   [1] andrfgarciac@udistrital.edu.co (Licenciada Universidad Distrital)     //
//   [2] jasalamanca@udistrital.edu.co (profesor Universidad Distrital)        //
//   [3] djrodriguezp@udistrital.edu.co (profesor Universidad Distrital)       //
//									       //
//  *,** Grupo de Física e Informática (FISINFOR)		               //
//  *** Grupo de Laboratorio de Fuentes Alternas de Energía (LIFAE)	       //
//  *,**,*** Universidad Distrital Francisco José de Caldas (Bogotá, Colombia) //	
//                                                                             //
// Web page:								       //
//   https://github.com/fisinforgh/SoftEduQSA                                  //
//                                                                             //
// This program isFree software; you can redistribute it and/or modify        //
// it under the terms of the GNU General Public License as published by        //
// the Free Software Foundation; either version 2 of the License, or           //
// (at your option) any later version.                                         //
//                                                                             //
// This program is distributed in the hope that it will be useful,             //
// but WITHOUT ANY WARRANTY; without even the implied warranty of              //
// MERCHANTABILITY or FITNESsFOR A PARTICULAR PURPOSE.  See the               //
// GNU General Public License for more details:                                //
//                                                                             //
//               http://www.gnu.org/copyleft/gpl.html                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


#include "TGDockableFrame.h"
#include "TGMdiDecorFrame.h"
#include "TG3DLine.h"
#include "TGMdiFrame.h"
#include "TGMdiMainFrame.h"
#include "TGMdiMenu.h"
#include "TGListBox.h"
#include "TGNumberEntry.h"
#include "TGScrollBar.h"
#include "TGComboBox.h"
#include "TGuiBldHintsEditor.h"
#include "TRootBrowser.h"
#include "TGuiBldNameFrame.h"
#include "TGFrame.h"
#include "TGMenu.h"
#include "TGFileDialog.h"
#include "TGShutter.h"
#include "TGButtonGroup.h"
#include "TGCommandPlugin.h"
#include "TGCanvas.h"
#include "TGFSContainer.h"
#include "TGuiBldEditor.h"
#include "TGColorSelect.h"
#include "TGTextEdit.h"
#include "TGButton.h"
#include "TRootContextMenu.h"
#include "TGFSComboBox.h"
#include "TGLabel.h"
#include "TGView.h"
#include "TGMsgBox.h"
#include "TRootGuiBuilder.h"
#include "TGFileBrowser.h"
#include "TGTab.h"
#include "TGListView.h"
#include "TGSplitter.h"
#include "TGTextEditor.h"
#include "TRootCanvas.h"
#include "TGStatusBar.h"
#include "TGListTree.h"
#include "TGuiBldGeometryFrame.h"
#include "TGToolTip.h"
#include "TGToolBar.h"
#include "TRootEmbeddedCanvas.h"
#include "TCanvas.h"
#include "TGuiBldDragManager.h"
#include "TGHtmlBrowser.h"


#include <TApplication.h>
#include <TGClient.h>
#include <TCanvas.h>
#include "TMatrix.h"
#include <TGButton.h>
#include <TGFrame.h>
#include <TMath.h>
#include <TRootEmbeddedCanvas.h>
#include <TGraph.h>
#include <TGTab.h>
#include <TTimer.h>
#include <TText.h>
#include <TGNumberEntry.h>
#include <TGLabel.h>
#include <TLine.h>
#include <TLatex.h>
#include <TArrow.h>
#include <TPaveText.h>
#include <TColor.h>
#include <TGIcon.h>
#include <TEllipse.h>
#include <TMatrixT.h>
#include <TROOT.h>
#include <TGComboBox.h>
#include <iostream>
#include <cmath>
#include <TString.h>
#include <TPaveText.h>
#include <TSystem.h>
#include <TGToolTip.h>
#include "Riostream.h"
#include "SoftEduQSA.h"

//Elipse
   TEllipse *circle;
   TEllipse *circle1;
   
//flecha
   TArrow *flecha1;
   TArrow *flecha2;
   TArrow *flecha3;
   TArrow *flecha4;
   TArrow *flecha5;
   TArrow *flecha6;
   TArrow *flecha7;
   TArrow *flecha8;
   TArrow *flecha9;
   TArrow *flecha10;
   TArrow *flecha11;
   TArrow *flecha12;
   TArrow *flecha13;
   TArrow *flecha14;
   TArrow *flecha15;
   TArrow *flecha16;
   TArrow *flecha17;
   TArrow *flecha18;
   TArrow *flecha19;
   TArrow *flecha20;

//Constructor
MyMainFrame::MyMainFrame(const TGWindow *p, UInt_t w, UInt_t h){
 
	//Rutas hacia la carpeta de ICONOS
	TString spathHIDEN_FILE(gSystem->HomeDirectory());
        spathHIDEN_FILE.Append("/.pathDIR_SoftEduQSA.txt");

        std::ifstream inHidenFile;
        inHidenFile.open(spathHIDEN_FILE);
        
        std::string spathICONS;
        getline(inHidenFile, spathICONS);
        pathDIR_ICONS.Append(spathICONS);
        pathDIR_ICONS.Append("/ICONS/");
	
 //Interfaz
 //Main frame
 fMain = new TGMainFrame(p, w, h);
 fMain->SetWindowName("Quantum Shor Algorithm");

//Composite frame
fMainFrame4645 = new TGCompositeFrame(fMain,894,534,kVerticalFrame);

//Horizontal frame
fHorizontalFrame1240 = new TGHorizontalFrame(fMainFrame4645,890,530,kHorizontalFrame);

//Vertical frame
fVerticalFrameMENUS = new TGVerticalFrame(fHorizontalFrame1240,222,526,kVerticalFrame|kRaisedFrame);

//MENU 1
fGroupFrameMENU1 = new TGGroupFrame(fVerticalFrameMENUS,"MENU 1");

//Label numero a factorizar   
fLabelNUMFACTOR = new TGLabel(fGroupFrameMENU1,"NUM. FACTOR");
fLabelNUMFACTOR->SetTextJustify(36);
fLabelNUMFACTOR->SetMargins(0,0,0,0);
fLabelNUMFACTOR->SetWrapLength(-1);
fGroupFrameMENU1->AddFrame(fLabelNUMFACTOR, new TGLayoutHints(kLHintsLeft |kLHintsTop|kLHintsCenterY,50,2,10,2));
fLabelNUMFACTOR->MoveResize(59,28,88,14);

ULong_t ucolor;        
gClient->GetColorByName("#ffffff",ucolor);

//Combo box de numeros a factorizar
fComboBoxNUMSFACTORS = new TGComboBox(fGroupFrameMENU1,-1,kHorizontalFrame|kSunkenFrame|kOwnBackground);
fComboBoxNUMSFACTORS->AddEntry("15",15);
fComboBoxNUMSFACTORS->AddEntry("21",21);
fComboBoxNUMSFACTORS->AddEntry("35",35);
fComboBoxNUMSFACTORS->Resize(102,20);
fComboBoxNUMSFACTORS->Select(-1);
fComboBoxNUMSFACTORS->Connect("Selected(Int_t)", "MyMainFrame", this,"DoSelection(Int_t)");
fComboBoxNUMSFACTORS->Connect("Selected(Int_t)", "MyMainFrame", this,"DoWelcome()");


fGroupFrameMENU1->AddFrame(fComboBoxNUMSFACTORS, new TGLayoutHints(kLHintsLeft|kLHintsTop|kLHintsCenterY,40,2,5,2));
fComboBoxNUMSFACTORS->MoveResize(52,43,102,20);

gClient->GetColorByName("#ffffff",ucolor);
   
//Label valores de A
fLabelVALUEA = new TGLabel(fGroupFrameMENU1,"VALUE a");
fLabelVALUEA->SetTextJustify(36);
fLabelVALUEA->SetMargins(0,0,0,0);
fLabelVALUEA->SetWrapLength(-1);
fGroupFrameMENU1->AddFrame(fLabelVALUEA, new TGLayoutHints(kLHintsLeft|kLHintsTop |kLHintsCenterY,60,2,10,2));
fLabelVALUEA->MoveResize(70,90,64,16);

//Combo box valores de A
fComboBoxVALUESA = new TGComboBox(fGroupFrameMENU1,-1,kHorizontalFrame|kSunkenFrame|kOwnBackground);
fComboBoxVALUESA->Resize(102,20);
fComboBoxVALUESA->Select(-1);
fGroupFrameMENU1->AddFrame(fComboBoxVALUESA, new TGLayoutHints(kLHintsLeft|kLHintsTop|kLHintsCenterY,40,2,5,2));
fComboBoxVALUESA->MoveResize(52,116,102,20);

fComboBoxVALUESA->SetEnabled(false);

//Opciones de visualizacion del menu 1
fGroupFrameMENU1->SetLayoutManager(new TGVerticalLayout(fGroupFrameMENU1));
fGroupFrameMENU1->Resize(216,170);
fVerticalFrameMENUS->AddFrame(fGroupFrameMENU1, new TGLayoutHints(kLHintsCenterX|kLHintsExpandY|kLHintsCenterY|kLHintsExpandX,2,2,2,2));
fGroupFrameMENU1->MoveResize(3,3,216,170);

//MENU 2
TGGroupFrame *fGroupFrameMENU2 = new TGGroupFrame(fVerticalFrameMENUS,"MENU 2");

//Boton START 
fTextButtonSTART = new TGTextButton(fGroupFrameMENU2,"START",kRaisedFrame);
fTextButtonSTART->SetTextJustify(36);
fTextButtonSTART->SetMargins(40,40,3,3);
fTextButtonSTART->SetWrapLength(-1);
fTextButtonSTART->Resize(97,26);
fGroupFrameMENU2->AddFrame(fTextButtonSTART, new TGLayoutHints(kLHintsCenterY|kLHintsExpandY,35,2,2,2));
fTextButtonSTART->MoveResize(56,21,97,26);
fTextButtonSTART->Connect("Clicked()", "MyMainFrame", this, "DoStart()");
fTextButtonSTART->Connect("Clicked()", "MyMainFrame", this, "DoClassical()");
fTextButtonSTART->Connect("Clicked()", "MyMainFrame", this, "DoCircuit()");
fTextButtonSTART->Connect("Clicked()", "MyMainFrame", this, "DoQuantum()");
 
//Boton CONCEPTS   
fTextButtonCONCEPTS = new TGTextButton(fGroupFrameMENU2,"CONCEPTS",kRaisedFrame);
fTextButtonCONCEPTS->SetTextJustify(36);
fTextButtonCONCEPTS->SetMargins(26,26,3,3);
fTextButtonCONCEPTS->SetWrapLength(-1);
fTextButtonCONCEPTS->Resize(97,29);
fGroupFrameMENU2->AddFrame(fTextButtonCONCEPTS, new TGLayoutHints(kLHintsCenterY|kLHintsExpandY,35,2,2,2));
fTextButtonCONCEPTS->MoveResize(56,54,97,29);
fTextButtonCONCEPTS->Connect("Clicked()", "MyMainFrame", this, "DoConcepts()");
    
//Boton HELP
fTextButtonHELP = new TGTextButton(fGroupFrameMENU2,"HELP",kRaisedFrame);
fTextButtonHELP->SetTextJustify(36);
fTextButtonHELP->SetMargins(44,43,3,3);
fTextButtonHELP->SetWrapLength(-1);
fTextButtonHELP->Resize(97,27);
fGroupFrameMENU2->AddFrame(fTextButtonHELP, new TGLayoutHints(kLHintsCenterY|kLHintsExpandY,35,2,2,2));
fTextButtonHELP->MoveResize(56,92,97,27);
fTextButtonHELP->Connect("Clicked()", "MyMainFrame", this, "DoHelp()");

//Boton EXIT
fTextButtonEXIT = new TGTextButton(fGroupFrameMENU2,"EXIT",kRaisedFrame);
fTextButtonEXIT->SetTextJustify(36);
fTextButtonEXIT->SetMargins(47,46,3,3);
fTextButtonEXIT->SetWrapLength(-1);
fTextButtonEXIT->Resize(97,25);
fGroupFrameMENU2->AddFrame(fTextButtonEXIT, new TGLayoutHints(kLHintsCenterY|kLHintsExpandY,35,2,2,2));
fTextButtonEXIT->MoveResize(57,130,97,25);

//Opciones de visualizacion del menu 2
fGroupFrameMENU2->SetLayoutManager(new TGVerticalLayout(fGroupFrameMENU2));
fGroupFrameMENU2->Resize(208,171);
fVerticalFrameMENUS->AddFrame(fGroupFrameMENU2, new TGLayoutHints(kLHintsCenterX|kLHintsTop|kLHintsCenterY|kLHintsExpandY|kLHintsExpandX,2,2,2,2));
fGroupFrameMENU2->MoveResize(3,177,208,171);
   
//Icono SoftEdu  
TGIcon *fIconSOFTEDU = new TGIcon(fVerticalFrameMENUS, pathDIR_ICONS + "IconoQSA1.png");
fVerticalFrameMENUS->AddFrame(fIconSOFTEDU, new TGLayoutHints(kLHintsCenterX | kLHintsCenterY,2,2,2,2));
fIconSOFTEDU->MoveResize(2,362,216,161);

//Fin del VerticalFrameMenus
fHorizontalFrame1240->AddFrame(fVerticalFrameMENUS, new TGLayoutHints(kLHintsLeft|kLHintsTop|kLHintsExpandY,2,2,2,2));
fVerticalFrameMENUS->MoveResize(2,2,222,526);

//VerticalFrame de explicaciones 
TGVerticalFrame *fVerticalFrameDIAGRAMS = new TGVerticalFrame(fHorizontalFrame1240,660,526,kVerticalFrame);

//Crear los tabs
fTabAll = new TGTab(fVerticalFrameDIAGRAMS,656,352);
tab1CLASSICAL = fTabAll->AddTab("CLASSICAL");
tab2CIRCUIT = fTabAll->AddTab("CIRCUIT");
tab3QUANTUM = fTabAll->AddTab("QUANTUM");

fTabAll->SetTab(0);
fTabAll->Connect("Selected(Int_t)", "MyMainFrame", this, "CambioTab(Int_t)"); 

//Canvas 1
fRootEmbeddedCanvasDRAWCLASSICAL = new TRootEmbeddedCanvas("fRootEmbeddedCanvasDRAWCLASSICAL",tab1CLASSICAL,660,325,kSunkenFrame);
tab1CLASSICAL->AddFrame(fRootEmbeddedCanvasDRAWCLASSICAL, new TGLayoutHints(kLHintsExpandX|kLHintsExpandY));

//Canvas 2
fRootEmbeddedCanvasDRAWCIRCUIT = new TRootEmbeddedCanvas("fRootEmbeddedCanvasDRAWCIRCUIT",tab2CIRCUIT,660,325,kSunkenFrame);
tab2CIRCUIT->AddFrame(fRootEmbeddedCanvasDRAWCIRCUIT, new TGLayoutHints(kLHintsExpandX|kLHintsExpandY));

//Canvas 3
fRootEmbeddedCanvasDRAWQUANTUM = new TRootEmbeddedCanvas("fRootEmbeddedCanvasDRAWQUANTUM",tab3QUANTUM,660,325,kSunkenFrame);
tab3QUANTUM->AddFrame(fRootEmbeddedCanvasDRAWQUANTUM, new TGLayoutHints(kLHintsExpandX|kLHintsExpandY));

//Agregar los tabs
fVerticalFrameDIAGRAMS->AddFrame(fTabAll, new TGLayoutHints(kLHintsLeft|kLHintsTop|kLHintsExpandX|kLHintsExpandY,2,2,2,2));

//Contenedor para el canvas EXPLINATION
TGHorizontalFrame* fExplanationFrame = new TGHorizontalFrame(fVerticalFrameDIAGRAMS, 660, 103, kSunkenFrame);

// Canvas Explicacion
fRootEmbeddedCanvasEXPLINATION = new TRootEmbeddedCanvas("fRootEmbeddedCanvasEXPLINATION", fExplanationFrame, 660, 103);
//fRootEmbeddedCanvasEXPLINATION->Resize();

// Añadir el canvas al contenedor con layout hints
fExplanationFrame->AddFrame(fRootEmbeddedCanvasEXPLINATION, new TGLayoutHints(kLHintsExpandX|kLHintsExpandY));

// Añadir el contenedor al frame principal
fVerticalFrameDIAGRAMS->AddFrame(fExplanationFrame, new TGLayoutHints(kLHintsExpandX));

// Mover y redimensionar el contenedor 
fExplanationFrame->MoveResize(2, 400, 660, 103); 

//Horizontal frame OPTIONS
fHorizontalFrameOPTIONS = new TGHorizontalFrame(fVerticalFrameDIAGRAMS,656,60,kHorizontalFrame);

//Boton BACK 
fTextButtonBACK = new TGTextButton(fHorizontalFrameOPTIONS,"BACK",kRaisedFrame);
fTextButtonBACK->SetTextJustify(36);
fTextButtonBACK->SetMargins(0,0,10,10);
fTextButtonBACK->SetWrapLength(-1);
fTextButtonBACK->Resize(131,20);
fHorizontalFrameOPTIONS->AddFrame(fTextButtonBACK, new TGLayoutHints(kLHintsCenterX | kLHintsCenterY | kLHintsExpandX,10,2,20,2));
fTextButtonBACK->MoveResize(10,20,131,20);
fTextButtonBACK->Connect("Clicked()", "MyMainFrame", this, "DoBack()");

//Boton CLEAR
fTextButtonCLEAR = new TGTextButton(fHorizontalFrameOPTIONS,"CLEAR",kRaisedFrame);
fTextButtonCLEAR->SetTextJustify(36);
fTextButtonCLEAR->SetMargins(0,0,10,10);
fTextButtonCLEAR->SetWrapLength(-1);
fTextButtonCLEAR->Resize(131,20);
fHorizontalFrameOPTIONS->AddFrame(fTextButtonCLEAR, new TGLayoutHints(kLHintsCenterX | kLHintsCenterY | kLHintsExpandX,19,2,20,2));
fTextButtonCLEAR->MoveResize(162,20,131,20); 
fTextButtonCLEAR->Connect("Clicked()", "MyMainFrame", this, "DoClear()");

//Boton NEXT   
fTextButtonNEXT = new TGTextButton(fHorizontalFrameOPTIONS,"NEXT",kRaisedFrame);
fTextButtonNEXT->SetTextJustify(36);
fTextButtonNEXT->SetMargins(0,0,10,10);
fTextButtonNEXT->SetWrapLength(-1);
fTextButtonNEXT->Resize(131,20); 
fTextButtonNEXT->Connect("Clicked()", "MyMainFrame", this, "DoNext()");

//Opciones de visualizacion de los botones en options
fHorizontalFrameOPTIONS->AddFrame(fTextButtonNEXT, new TGLayoutHints(kLHintsCenterX | kLHintsCenterY | kLHintsExpandX,12,2,20,2));
fTextButtonNEXT->MoveResize(500,20,131,20);

//ICONO UD*********************** 
TGIcon *fIconUD = new TGIcon(fHorizontalFrameOPTIONS, pathDIR_ICONS + "logoUD.png");
fHorizontalFrameOPTIONS->AddFrame(fIconUD, new TGLayoutHints(kLHintsCenterX | kLHintsRight | kLHintsTop | kLHintsCenterY,2,2,2,2));
fIconUD->MoveResize(462,2,192,56);

//Opciones de visualizacion de options en diagrams 
fVerticalFrameDIAGRAMS->AddFrame(fHorizontalFrameOPTIONS, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX,2,2,2,2));
fHorizontalFrameOPTIONS->MoveResize(2,464,656,60);

//Opciones de visualizacion   
fHorizontalFrame1240->AddFrame(fVerticalFrameDIAGRAMS, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY,2,2,2,2));
fVerticalFrameDIAGRAMS->MoveResize(228,2,660,526);   

 //Opciones de visualizacion
fMainFrame4645->AddFrame(fHorizontalFrame1240, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY,2,2,2,2));
fHorizontalFrame1240->MoveResize(2,2,890,530);

 //Botones activos/desactivados
	fTextButtonSTART->SetState(kButtonDisabled, kTRUE);
	fTextButtonBACK->SetState(kButtonDisabled, kTRUE);
	fTextButtonCLEAR->SetState(kButtonDisabled, kTRUE);
	fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
	fTextButtonEXIT->SetCommand("gApplication->Terminate(0)");
	
DoWelcome();

//Opciones de visualizacion
fMain->AddFrame(fMainFrame4645, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
fMain->MoveResize(0,0,894,534);
fMain->SetMWMHints(kMWMDecorAll, kMWMFuncAll, kMWMInputModeless);
fMain->MapSubwindows();
fMain->Resize(fMain->GetDefaultSize());
fMain->MapWindow();	
fMain->Resize(1200,680);
}

//////Funciones/////////
/*************************************************/
void MyMainFrame::DoWelcome(){		

fTabAll->SetEnabled(0,kTRUE);
fTabAll->SetEnabled(1,kFALSE);
fTabAll->SetEnabled(2,kFALSE);

fTextButtonCONCEPTS->SetState(kButtonUp, kTRUE);
fTextButtonHELP->SetState(kButtonUp, kTRUE);
fTextButtonBACK->SetState(kButtonDisabled, kTRUE);
fTextButtonCLEAR->SetState(kButtonDisabled, kTRUE);
fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);	

//Diagrama de bienvenida
TCanvas *Bienvenida = fRootEmbeddedCanvasDRAWCLASSICAL->GetCanvas();
Bienvenida->SetFixedAspectRatio();
Bienvenida->SetFillColor(0);
Bienvenida->SetEditable(1);
Bienvenida->Clear();
Bienvenida->Update();
Bienvenida->cd();
    
//Definir el titulo
TPaveText *TPTTitle = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
TPTTitle->SetTextFont(62);
TPTTitle->SetTextSize(0.07);
TPTTitle->SetFillColor(0); 
TPTTitle->SetShadowColor(kGray);
TPTTitle->SetMargin(0.03);
TPTTitle->AddText("Quantum Shor Algorithm #color[2]{Soft}ware #color[4]{Edu}cation");
TPTTitle->Draw();

//Creacion de las separaciones
	TPad *pad1 = new TPad("pad1","This is pad1",0.01,0.001,0.34,0.84); 
	pad1->SetFillColor(0);
	pad1->Draw();
	
	TPad *pad2 = new TPad("pad2","This is pad2",0.345,0.001,0.67,0.84);
	pad2->SetFillColor(0);
	pad2->Draw();

	TPad *pad3 = new TPad("pad3","This is pad3",0.675,0.001,0.997,0.84);
	pad3->SetFillColor(0);
	pad3->Draw();
    

//Texto dentro del pad1
	//Texto dentro del pad1
	pad1->cd();
	TPaveText *TPTQSAGui = new TPaveText(0.0099, 0.0099, 0.99, 0.999, "NDC"); 
 	TPTQSAGui->SetTextFont(42);
	TPTQSAGui->SetTextSize(0.040);
	TPTQSAGui->SetFillColor(kGreen-10); 
	TPTQSAGui->SetShadowColor(kGray);
	TPTQSAGui->SetTextAlign(22);
	TPTQSAGui->SetMargin(0.03);
	TPTQSAGui->AddText("");
 	TPTQSAGui->AddText("#font[62]{#scale[1.6]{QSA GUI}}");
 	TPTQSAGui->AddText("");
 	TPTQSAGui->AddText("#font[62]{0.} To start, select a value to factor #font[62]{NUM. FACTOR}.");
 	TPTQSAGui->AddText("#font[62]{1.} Select the coprime value #font[62]{VALUE a}.");
 	TPTQSAGui->AddText("#font[62]{2.} Once you choose the two options, press the button.");
 	TPTQSAGui->AddText("#font[62]{START} that takes you to the boxes of procedures and");
 	TPTQSAGui->AddText("steps of the #font[62]{Shor's algorithm}");
 	TPTQSAGui->AddText("#font[62]{3.} To move forward and backward through the boxes of");
 	TPTQSAGui->AddText("Explanation press the buttons #font[62]{BACK} and #font[62]{NEXT}.");
 	TPTQSAGui->AddText("#font[62]{4.} You will be able to see the changes in a classic way");
 	TPTQSAGui->AddText("and quantum along with the circuit by pressing the");
 	TPTQSAGui->AddText("#font[62]{TABS} at the top.");
 	TPTQSAGui->AddText("#font[62]{5.} To return to the main window, press the button");
 	TPTQSAGui->AddText("#font[62]{CLEAR}.");
 	TPTQSAGui->AddText("#font[62]{6.} Return to #font[62]{step 0} to run the interface after pressing ");
 	TPTQSAGui->AddText("the button #font[62]{CLEAR}.");
 	TPTQSAGui->AddText("#font[62]{7.} Press the button #font[62]{HELP} for more information about");
 	TPTQSAGui->AddText("the interface.");
 	TPTQSAGui->AddText("#font[62]{8.} Press the button #font[62]{CONCEPTS} for more");
 	TPTQSAGui->AddText("information about the mathematical procedures.");
 	TPTQSAGui->AddText("#font[62]{9.} To exit the interface, press the button");
 	TPTQSAGui->AddText("#font[62]{EXIT}");
 	TPTQSAGui->AddText("");
 	TPTQSAGui->Draw();
//Texto dentro del pad2
	pad2->cd();
	TPaveText *TPTQSAExplination = new TPaveText(0.0099, 0.0099, 0.99, 0.999, "NDC"); 
 	TPTQSAExplination->SetTextFont(42);
	TPTQSAExplination->SetTextSize(0.040);
	TPTQSAExplination->SetFillColor(kRed-10); 
	TPTQSAExplination->SetShadowColor(kGray);
	TPTQSAExplination->SetTextAlign(22);
	TPTQSAExplination->SetMargin(0.03);
	TPTQSAExplination->AddText("");
 	TPTQSAExplination->AddText("#font[62]{#scale[1.6]{SHOR'S ALGORITHM}}");
 	TPTQSAExplination->AddText("");
 	TPTQSAExplination->AddText("#font[62]{#scale[1.2]{In a CLASSIC form:}}");
 	TPTQSAExplination->AddText("#font[62]{0.} Number to factor   N = P*Q ");
 	TPTQSAExplination->AddText("#font[62]{1.} Coprime value with N   a");
 	TPTQSAExplination->AddText("#font[62]{2.} modular function   F_{a, N} = a^{r}mod N");
 	TPTQSAExplination->AddText("#font[62]{3.} Period of the modular function   r");
 	TPTQSAExplination->AddText("#font[62]{4.} Value to verify the period r   X = a^{#frac{r}{2}}mod N");
 	TPTQSAExplination->AddText("#font[62]{5.} Greatest Common Divisor   GCD(X#pm 1, N)");
 	TPTQSAExplination->AddText("#font[62]{#scale[1.2]{In a QUANTUM form:}}"); 
 	TPTQSAExplination->AddText("#font[62]{0.} Number to factor   N = P*Q");
 	TPTQSAExplination->AddText("#font[62]{1.} Number of Qubits needed   n");
 	TPTQSAExplination->AddText("#font[62]{2.} Number of possible states    N* = 2^{n}");
 	TPTQSAExplination->AddText("#font[62]{3.} Hadamard gate on |x#GT    H^{#otimes n} = #frac{1}{#sqrt{N*}}#sum_{0}^{N*-1}|x#GT^{#otimes n}");
	TPTQSAExplination->AddText("Gate U_{a, N}   U =|a^{r}mod N#GT");

	TPTQSAExplination->AddText("#font[62]{5.} QFT^{+}  #frac{1}{#sqrt{N*}}#sum_{y=0}^{N*-1} e^{#frac{-2#pi ixy}{N*}}|y#GT^{#otimes n}  ");
 	TPTQSAExplination->AddText("#font[62]{6.} Maximum value for the results  #frac{jN}{r}");
	TPTQSAExplination->AddText("#font[62]{7.} Greatest Common Divisor   GCD(X#pm 1, N)");
	TPTQSAExplination->AddText("");
	TPTQSAExplination->Draw();
 
        //Texto dentro del pad3
	pad3->cd();
	TPaveText *TPTConsideraciones = new TPaveText(0.0099, 0.0099, 0.99, 0.999,"NDC"); 
 	TPTConsideraciones->SetTextFont(42);
	TPTConsideraciones->SetTextSize(0.040);
	TPTConsideraciones->SetFillColor(kYellow-10); 
	TPTConsideraciones->SetShadowColor(kGray);
	TPTConsideraciones->SetTextAlign(22);
	TPTConsideraciones->SetMargin(0.03);
	TPTConsideraciones->AddText("");
 	TPTConsideraciones->AddText("#font[62]{#scale[1.6]{CONSIDERATIONS}}");
 	TPTConsideraciones->AddText("");
 	TPTConsideraciones->AddText("Before starting with the interface, it is suggested");
 	TPTConsideraciones->AddText("to review the concepts of #font[62]{Hadamard gate}");
 	TPTConsideraciones->AddText("#font[62]{Gate U_{a, N} and modular algebra} on the button");
 	TPTConsideraciones->AddText("#font[62]{CONCEPTS}.");
 	TPTConsideraciones->AddText("#font[62]{1.} You should know the basic concepts of");
 	TPTConsideraciones->AddText("quantum computing such as:");
 	TPTConsideraciones->AddText("#font[62]{Qubit, Logic gate, etc.}");
 	TPTConsideraciones->AddText("#font[62]{2.} If you have questions about using the interface");
 	TPTConsideraciones->AddText("press the button #font[62]{HELP} which will explain to you");
 	TPTConsideraciones->AddText("how to interact with the interface in a more");
 	TPTConsideraciones->AddText("precise.");
 	TPTConsideraciones->AddText("#font[62]{3.} To return to the main window, press the");
 	TPTConsideraciones->AddText("button #font[62]{CLEAR} once you have selected the");
 	TPTConsideraciones->AddText("main values and pressed the button #font[62]{START}.");
 	TPTConsideraciones->AddText("");
 	TPTConsideraciones->Draw();

//Actualizacion del canvas
Bienvenida->Update();
Bienvenida->SetEditable(0);

//Canvas de explicaciones/agradecimientos
	TCanvas *Agradecimiento = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	Agradecimiento->SetFixedAspectRatio();
	Agradecimiento->SetFillColor(0);
	Agradecimiento->SetEditable(1);
	Agradecimiento->Clear();
	Agradecimiento->Update();
	Agradecimiento->cd();
	
	TPad *padExp = new TPad("padExp","This is padExp", 0.001, 0.001, 0.999, 0.999); 
	padExp->SetFillColor(0);
	padExp->Draw();
	
	padExp->cd();
	TPaveText *TPTAgradecimientos = new TPaveText(0.00099, 0.0099, 0.999, 0.999,"NDC");
	TPTAgradecimientos->SetFillColor(kCyan - 10);     
	TPTAgradecimientos->SetLineColor(kBlue - 7);    
	TPTAgradecimientos->SetShadowColor(kGray + 2);   
	TPTAgradecimientos->SetTextAlign(22);              
	TPTAgradecimientos->SetMargin(0.05);
	TPTAgradecimientos->AddText("#font[62]{#scale[1.6]{Autores}}");
 	TPTAgradecimientos->AddText("#scale[0.8]{Andres Felipe Garcia Cardenas^{1}, #font[62]{Julian A. Salamanca Bernal^{2}}, #font[62]{Diego J. Rodriguez Patarroyo^{3}}}");
 	TPTAgradecimientos->AddText("#scale[0.8]{#font[62]{Facultad Ciencias y Educacion}^{1, 2}, #font[62]{Facultad Ingenieria}^{3}, Grupo de Fisica e Informatica #font[62]{Fisinfor}^{1, 2}}, #scale[0.8]{Grupo de Laboratorio de Fuentes Alternas de Energia #font[62]{LIFAE}^{2, 3}}");
 	TPTAgradecimientos->AddText("#scale[0.8]{Universidad Distrital Francisco Jose de Caldas.^{1, 2, 3}}");
	TPTAgradecimientos->Draw();
 	
 	Agradecimiento->Update();
	Agradecimiento->SetEditable(0);
}
/************************************************************/
void MyMainFrame::DoSelection(Int_t Opt){
    
    Opt = fComboBoxNUMSFACTORS->GetSelected();
    fComboBoxVALUESA->RemoveAll();
   
    switch (Opt) {
        case 15:
            CTab = false;
            fComboBoxVALUESA->SetEnabled(true);
            fComboBoxVALUESA->AddEntry("13", 13);
            fComboBoxVALUESA->AddEntry("14", 14);
            fTextButtonSTART->SetState(kButtonUp, kTRUE);
            
            
            break;
        case 21:
            CTab = false;
            fComboBoxVALUESA->SetEnabled(true);
            fComboBoxVALUESA->AddEntry("2", 2);
            fComboBoxVALUESA->AddEntry("4", 4);
            fComboBoxVALUESA->AddEntry("5", 5);
            fTextButtonSTART->SetState(kButtonUp, kTRUE);
            
            break;
        case 35:
            CTab = false;
            fComboBoxVALUESA->SetEnabled(true);
            fComboBoxVALUESA->AddEntry("2", 1);
            fComboBoxVALUESA->AddEntry("11", 11);
            fTextButtonSTART->SetState(kButtonUp, kTRUE);
            break;  
    }
    
    fComboBoxVALUESA->Select(-1);
    fComboBoxVALUESA->Layout();
}
/************************************************************/
void MyMainFrame::DoStart(){

CTab = false;

fTabAll->SetEnabled(0,kTRUE);
fTabAll->SetEnabled(1,kTRUE);
fTabAll->SetEnabled(2,kTRUE);
 
fTabAll->SetTab(0);
CambioTab(0);

//Desactivar los boxes
fComboBoxNUMSFACTORS->SetEnabled(kFALSE);
fComboBoxVALUESA->SetEnabled(kFALSE);

//Botones que estaran activos.
fTextButtonSTART->SetState(kButtonDisabled, kTRUE);
fTextButtonCONCEPTS->SetState(kButtonDisabled, kTRUE);
fTextButtonHELP->SetState(kButtonDisabled, kTRUE);
fTextButtonBACK->SetState(kButtonUp, kTRUE);
fTextButtonCLEAR->SetState(kButtonUp, kTRUE);
fTextButtonNEXT->SetState(kButtonUp, kTRUE);

//Funciones a iniciar
DoClassical();
fTabAll->Layout();  	   
}
/************************************************************/
void MyMainFrame::DoConcepts(){

CTab = true;
CambioTab(fTabAll->GetCurrent());

fTextButtonSTART->SetState(kButtonDisabled, kTRUE);
fTextButtonCONCEPTS->SetState(kButtonDisabled, kTRUE);
fTextButtonHELP->SetState(kButtonUp, kTRUE);
fTextButtonBACK->SetState(kButtonDisabled, kTRUE);
fTextButtonCLEAR->SetState(kButtonUp, kTRUE);
fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);

//Obtener la pestaña seleccionada
	fTabAll->SetEnabled(0,kTRUE);
	fTabAll->SetEnabled(1,kTRUE);
	fTabAll->SetEnabled(2,kTRUE);

}
/*************************************************************/
void MyMainFrame::DoHelp(){

CTab = false;

fTabAll->SetEnabled(0,kTRUE);
fTabAll->SetEnabled(1,kFALSE);
fTabAll->SetEnabled(2,kFALSE);

fTabAll->SetTab(0);

fTextButtonSTART->SetState(kButtonDisabled, kTRUE);
fTextButtonCONCEPTS->SetState(kButtonUp, kTRUE);
fTextButtonHELP->SetState(kButtonDisabled, kTRUE);
fTextButtonBACK->SetState(kButtonDisabled, kTRUE);
fTextButtonCLEAR->SetState(kButtonUp, kTRUE);
fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);

TCanvas *Ayuda = fRootEmbeddedCanvasDRAWCLASSICAL->GetCanvas();
Ayuda->SetFixedAspectRatio();
Ayuda->SetFillColor(0);
Ayuda->SetEditable(1);
Ayuda->Clear();
Ayuda->Update();
Ayuda->cd();

	//presentacion
	//Definir el titulo
	TPaveText *TPTTitle = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	TPTTitle->SetFillColor(0); 
	TPTTitle->SetShadowColor(kGray);
	TPTTitle->SetMargin(0.1);
	TPTTitle->AddText("Help with Managing QSA #color[2]{Soft}ware #color[4]{Edu}cational");
	TPTTitle->Draw();
	
	//Creacion de las separaciones 
	TPad *paso1 = new TPad("pad1","This is pad1",0.01 ,0.42, 0.50, 0.83); 
	paso1->SetFillColor(0);
	paso1->Draw();
	
	TPad *paso2 = new TPad("pad2","This is pad2",0.51 ,0.42, 0.99, 0.83); 
	paso2->SetFillColor(0);
	paso2->Draw();

	TPad *paso3 = new TPad("pad3","This is pad3",0.01, 0.01, 0.50, 0.40);
	paso3->SetFillColor(0);
	paso3->Draw();
	
	TPad *paso4 = new TPad("pad3","This is pad3",0.51, 0.01, 0.99, 0.40);
	paso4->SetFillColor(0);
	paso4->Draw();
	
	//Texto dentro del pad1
	paso1->cd();
	TPaveText *TPTPaso1 = new TPaveText(0.001 ,0.009, 0.995, 0.995, "NDC"); 
	TPTPaso1->SetTextFont(42);
	TPTPaso1->SetFillColor(kBlue-10); 
	TPTPaso1->SetShadowColor(kGray);
	TPTPaso1->SetTextAlign(12);
	TPTPaso1->SetMargin(0.04);
	TPTPaso1->AddText("");
 	TPTPaso1->AddText("  #font[62]{#scale[1.7]{STEP #1}}");
 	TPTPaso1->AddText("Select the value #font[62]{NUM. FACTOR} and the coprime value #font[62]{Value a}");
 	TPTPaso1->AddText("After selecting them, press the #font[62]{START} button to proceed to");
 	TPTPaso1->AddText("the procedure panels.");
 	TPTPaso1->AddText("");
 	TPTPaso1->Draw();
 	
 	//Texto dentro del pad2
	paso2->cd();
	TPaveText *TPTPaso2 = new TPaveText(0.001 ,0.009, 0.995, 0.995, "NDC"); 
	TPTPaso2->SetTextFont(42);
	TPTPaso2->SetFillColor(kGreen-10); 
	TPTPaso2->SetShadowColor(kGray);
	TPTPaso2->SetTextAlign(12);
	TPTPaso2->SetMargin(0.04);
	TPTPaso2->AddText("");
 	TPTPaso2->AddText("  #font[62]{#scale[1.7]{STEP #2}}");
 	TPTPaso2->AddText("Navigate through the slides using the #font[62]{BACK and NEXT} buttons");
 	TPTPaso2->AddText("To observe the changes in the classical part, quantum part,");
 	TPTPaso2->AddText("and the circuit. Select the #font[62]{TABS} at the top of the title.");
 	TPTPaso2->AddText("Each #font[62]{TAB} displays the different processes of Shor's algorithm.");
 	TPTPaso2->AddText("");
 	TPTPaso2->Draw();
 	
 	//Texto dentro del pad3
 	paso3->cd();
	TPaveText *TPTPaso3 = new TPaveText(0.001 ,0.009, 0.995, 0.995, "NDC"); 
	TPTPaso3->SetTextFont(42);
	TPTPaso3->SetFillColor(kMagenta-10); 
	TPTPaso3->SetShadowColor(kGray);
	TPTPaso3->SetTextAlign(12);
	TPTPaso3->SetMargin(0.04);
	TPTPaso3->AddText("");
 	TPTPaso3->AddText("  #font[62]{#scale[1.7]{STEP #3}}");
 	TPTPaso3->AddText("Press the #font[62]{CLEAR} button to return to the home screen.");
 	TPTPaso3->AddText("To reset the interface, go back to #font[62]{step 1}.");
 	TPTPaso3->AddText("As a recommendation to the user, it is advised to have knowledge of");
 	TPTPaso3->AddText("prior knowledge of #font[62]{Quantum Computing and Quantum Mechanics} to");
 	TPTPaso3->AddText("proceed to the next step.");
 	TPTPaso3->AddText("");
 	TPTPaso3->Draw();
 	
 	//Texto dentro del pad4
 	paso4->cd();
	TPaveText *TPTPaso4 = new TPaveText(0.001 ,0.009, 0.995, 0.995, "NDC"); 
	TPTPaso4->SetTextFont(42);
	TPTPaso4->SetFillColor(kCyan-10); 
	TPTPaso4->SetShadowColor(kGray);
	TPTPaso4->SetTextAlign(12);
	TPTPaso4->SetMargin(0.04);
	TPTPaso4->AddText("");
  	TPTPaso4->AddText("  #font[62]{#scale[1.7]{STEP #4}}");
 	TPTPaso4->AddText("On the left side of the interface, you will find the buttons for");
 	TPTPaso4->AddText("#font[62]{CONCEPTS and HELP} which will assist you with the explanations");
 	TPTPaso4->AddText("mathematical and conceptual aspects of the algorithm along with");
 	TPTPaso4->AddText("the management of the interface.");
 	TPTPaso4->AddText("To exit the interface, press the #font[62]{EXIT} button.");
 	TPTPaso4->AddText("");
 	TPTPaso4->Draw();

	//Actualizacion del canvas
	Ayuda->Update();
	Ayuda->SetEditable(0);
	
	//2do canvas ayuda
	TCanvas *ExpHelp = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpHelp->SetFixedAspectRatio();
	ExpHelp->SetFillColor(0);
	ExpHelp->SetEditable(1);
	ExpHelp->Clear();
	ExpHelp->Update();
	
	TPaveText *TPTHelp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC"); 
	TPTHelp->SetTextFont(42);
	TPTHelp->SetFillColor(0); 
	TPTHelp->SetShadowColor(kGray);
	TPTHelp->SetTextAlign(12);
	TPTHelp->SetMargin(0.01);
 	TPTHelp->AddText("Here you will find help with the user interface management. The steps are explained simply to make it intuitive to use.");
 	TPTHelp->AddText("Each panel contains the functionality of the buttons and the selection of initial values to get started with the interface.");
 	TPTHelp->AddText("Press the #font[62]{CLEAR} button to return to the home screen, or select the values #font[62]{NUM. FACTOR and Value a}, and then press #font[62]{START}.");
 	TPTHelp->Draw();
 	
 	ExpHelp->Update();
	ExpHelp->SetEditable(0);
}
/*************************************************************/
void MyMainFrame::DoConceptsClassical(){

TCanvas *ConceptosClasicos = fRootEmbeddedCanvasDRAWCLASSICAL->GetCanvas();
	ConceptosClasicos->SetFixedAspectRatio();
	ConceptosClasicos->SetFillColor(0);
	ConceptosClasicos->SetEditable(1);
	ConceptosClasicos->Clear();
	ConceptosClasicos->cd();

	TPaveText *Pasos_Clasicos = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Pasos_Clasicos->SetTextFont(62);
	Pasos_Clasicos->SetFillColor(0); 
	Pasos_Clasicos->SetShadowColor(kGray);
	Pasos_Clasicos->SetMargin(0.1);
	Pasos_Clasicos->AddText("#color[2]{Clas}sical #color[4]{Con}cepts of Shor's Algorithm");
	Pasos_Clasicos->Draw();

	//Creacion de las separaciones 
	TPad *paso1 = new TPad("pad1","This is pad1",0.01 ,0.42, 0.50, 0.83); 
	paso1->SetFillColor(0);
	paso1->Draw();
	
	TPad *paso2 = new TPad("pad2","This is pad2",0.51 ,0.42, 0.99, 0.83); 
	paso2->SetFillColor(0);
	paso2->Draw();

	TPad *paso3 = new TPad("pad3","This is pad3",0.01, 0.01, 0.50, 0.40);
	paso3->SetFillColor(0);
	paso3->Draw();
	
	TPad *paso4 = new TPad("pad3","This is pad3",0.51, 0.01, 0.99, 0.40);
	paso4->SetFillColor(0);
	paso4->Draw();
	
	//Texto dentro del pad1
	paso1->cd();
	TPaveText *TPTAlgoritmoEuclides = new TPaveText(0.001 ,0.009, 0.995, 0.995, "NDC"); 
 	TPTAlgoritmoEuclides->SetTextFont(42);
	TPTAlgoritmoEuclides->SetFillColor(kBlue-10); 
	TPTAlgoritmoEuclides->SetShadowColor(kGray);
	TPTAlgoritmoEuclides->SetTextAlign(12);
	TPTAlgoritmoEuclides->SetMargin(0.03);
	TPTAlgoritmoEuclides->AddText("");
 	TPTAlgoritmoEuclides->AddText("#font[62]{#scale[1.5]{Procedure of the Euclidean Algorithm}}");
 	TPTAlgoritmoEuclides->AddText("");
 	TPTAlgoritmoEuclides->AddText("#font[62]{1.} Two numbers #font[62]{a, b} are defined such that the property #font[62]{a > b} holds.");
 	TPTAlgoritmoEuclides->AddText("#font[62]{2.} Divide #font[62]{a} by #font[62]{b} and place the result at the top of the box.");
 	TPTAlgoritmoEuclides->AddText("#font[62]{3.} The remainder is placed at the bottom of the box and is repeated in the center");
 	TPTAlgoritmoEuclides->AddText("from the following box");
 	TPTAlgoritmoEuclides->AddText("#font[62]{4.} Step 1 is repeated until the final result is the following step.");
 	TPTAlgoritmoEuclides->AddText("#font[62]{5.} If the final result is 1, it has been found that #font[62]{a} and #font[62]{b} are #font[62]{Coprime numbers}");
 	TPTAlgoritmoEuclides->AddText("If it does not reach that result, the numbers #font[62]{a} and #font[62]{b} are not coprime to each");
 	TPTAlgoritmoEuclides->AddText("other and cannot be used in #font[62]{Shor's algorithm.}");
 	TPTAlgoritmoEuclides->AddText("Coprime numbers only share a greatest common divisor, which is 1.");
 	TPTAlgoritmoEuclides->AddText("");
 	TPTAlgoritmoEuclides->Draw();
 	
 	//Texto dentro del pad2
	paso2->cd();
	TPaveText *TPTAlgebraModular = new TPaveText(0.001 ,0.009, 0.995, 0.995, "NDC"); 
 	TPTAlgebraModular->SetTextFont(42);
	TPTAlgebraModular->SetFillColor(kGreen-10); 
	TPTAlgebraModular->SetShadowColor(kGray);
	TPTAlgebraModular->SetTextAlign(12);
	TPTAlgebraModular->SetMargin(0.03);
 	TPTAlgebraModular->AddText("");
 	TPTAlgebraModular->AddText("#font[62]{#scale[1.5]{Modular Algebra in Shor's Algorithm}}");
 	TPTAlgebraModular->AddText("");
 	TPTAlgebraModular->AddText("Mathematical representation of modular algebra: #font[62]{a #equiv b mod n}");
 	TPTAlgebraModular->AddText("Characteristics of modular algebra in the #font[62]{Shor's algorithm}:");
 	TPTAlgebraModular->AddText("#font[62]{1.} The value #font[62]{b} is equal to 1 and the modulus is the number to factor #font[62]{N}.");
 	TPTAlgebraModular->AddText("#font[62]{2.} The value of #font[62]{a} must be coprime with #font[62]{N}.");
 	TPTAlgebraModular->AddText("#font[62]{3.} It must hold that: #font[62]{a #equiv 1 mod N}.");
 	TPTAlgebraModular->AddText("#font[62]{4.} To obtain the factors #font[62]{P} and #font[62]{Q}, #font[62]{X} must be a #font[62]{non-trivial square root}");
 	TPTAlgebraModular->AddText("that is, #font[62]{X^{2} #equiv 1 mod N} and must be in the range #font[62]{2 < X < N-2}");
 	TPTAlgebraModular->AddText("#font[62]{5.} If the previous condition is satisfied, it is possible to determine that");
 	TPTAlgebraModular->AddText("#font[62]{GCD(X#pm 1, N)} are the sought factors #font[62]{P} and #font[62]{Q}.");
 	TPTAlgebraModular->AddText("");
 	TPTAlgebraModular->Draw();
 	
 	//Texto dentro del pad3
 	paso3->cd();
	TPaveText *TPTFModular = new TPaveText(0.001 ,0.009, 0.995, 0.995, "NDC"); 
 	TPTFModular->SetTextFont(42);
	TPTFModular->SetFillColor(kMagenta-10); 
	TPTFModular->SetShadowColor(kGray);
	TPTFModular->SetTextAlign(12);
	TPTFModular->SetMargin(0.03);
	TPTFModular->AddText("");
 	TPTFModular->AddText("#font[62]{#scale[1.5]{Modular Function of Shor's Algorithm}}");
 	TPTFModular->AddText("");
 	TPTFModular->AddText("Shor's algorithm determines the period #font[62]{r} of an exponential function in modular");
 	TPTFModular->AddText("algebra. The function is: #font[62]{F_{a, N} = a^{r}mod N}");
 	TPTFModular->AddText("The properties of the modular function are as follows:");
 	TPTFModular->AddText("#font[62]{1.} The function is #font[62]{periodic.}");
 	TPTFModular->AddText("#font[62]{2.} If the value of the period #font[62]{r is even}, it holds that: #font[62]{(a^{#frac{r}{2}}-1)(a^{#frac{r}{2}}+1) #equiv 0 mod N }");
 	TPTFModular->AddText("#font[62]{3.} If the result of #font[62]{r is odd}, it is necessary to choose another value of #font[62]{a}.");
 	TPTFModular->AddText("");
 	TPTFModular->Draw();
 	
 	//Texto dentro del pad4
 	paso4->cd();
	TPaveText *TPTGCD = new TPaveText(0.001 ,0.009, 0.995, 0.995, "NDC"); 
 	TPTGCD->SetTextFont(42);
	TPTGCD->SetFillColor(kCyan-10); 
	TPTGCD->SetShadowColor(kGray);
	TPTGCD->SetTextAlign(12);
	TPTGCD->SetMargin(0.03);
	TPTGCD->AddText("");
 	TPTGCD->AddText("#font[62]{#scale[1.5]{Greatest Common Divisor}}");
 	TPTGCD->AddText("");
 	TPTGCD->AddText("In #font[62]{Shor's algorithm}, various results are obtained when calculating the GCD");
 	TPTGCD->AddText("of #font[62]{X#pm 1} and #font[62]{N}, such as:");
 	TPTGCD->AddText("#font[62]{1. Complete Result}: Where it is possible to determine the values of #font[62]{P} and #font[62]{Q} from");
 	TPTGCD->AddText("accurately.");
 	TPTGCD->AddText("#font[62]{2. Partial Results}: Only one of the sought factors is obtained, either");
 	TPTGCD->AddText("#font[62]{P} or #font[62]{Q}. To determine the other value, the main definition #font[62]{N = P*Q} must be used");
 	TPTGCD->AddText("and solve for the unknown.");
 	TPTGCD->AddText("#font[62]{3. Trivial Results}: The result of the entire operation is obtained as #font[62]{N = 1*N}");
 	TPTGCD->AddText("#font[62]{4. Failed Results}: It is not possible to determine either of the factors #font[62]{P} and #font[62]{Q}.");
 	TPTGCD->AddText("");
 	TPTGCD->Draw();

	ConceptosClasicos->Update();
        ConceptosClasicos->SetEditable(0);
}
/*************************************************************/
void MyMainFrame::DoConceptsQuantum(){

	TCanvas *ConceptosCuanticos = fRootEmbeddedCanvasDRAWQUANTUM->GetCanvas();
	ConceptosCuanticos->SetFixedAspectRatio();
	ConceptosCuanticos->SetFillColor(0);
	ConceptosCuanticos->SetEditable(1);
	ConceptosCuanticos->Clear();
	ConceptosCuanticos->cd();

	TPaveText *Pasos_Clasicos = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Pasos_Clasicos->SetTextFont(62);
	Pasos_Clasicos->SetFillColor(0); 
	Pasos_Clasicos->SetShadowColor(kGray);
	Pasos_Clasicos->SetMargin(0.1);
	Pasos_Clasicos->AddText("#color[2]{Qua}ntum #color[4]{Con}cepts of Shor's Algorithm");
	Pasos_Clasicos->Draw();

	//Creacion de las separaciones 
	TPad *paso1 = new TPad("pad1","This is pad1",0.01 ,0.42, 0.50, 0.83); 
	paso1->SetFillColor(0);
	paso1->Draw();
	
	TPad *paso2 = new TPad("pad2","This is pad2",0.51 ,0.42, 0.99, 0.83); 
	paso2->SetFillColor(0);
	paso2->Draw();

	TPad *paso3 = new TPad("pad3","This is pad3",0.01, 0.01, 0.50, 0.40);
	paso3->SetFillColor(0);
	paso3->Draw();
	
	TPad *paso4 = new TPad("pad3","This is pad3",0.51, 0.01, 0.99, 0.40);
	paso4->SetFillColor(0);
	paso4->Draw();
	
	//Texto dentro del pad1
	paso1->cd();
	TPaveText *TPTPaso1 = new TPaveText(0.001 ,0.009, 0.995, 0.995, "NDC"); 
 	TPTPaso1->SetTextFont(42);
	TPTPaso1->SetFillColor(kBlue-10); 
	TPTPaso1->SetShadowColor(kGray);
	TPTPaso1->SetTextAlign(12);
	TPTPaso1->SetMargin(0.03);
	TPTPaso1->AddText("");
 	TPTPaso1->AddText("#font[62]{#scale[1.4]{Notation and maximum result value #frac{jN}{r} = M}}");
 	TPTPaso1->AddText("");
 	TPTPaso1->AddText("#scale[0.9]{Due to the complexity of the #font[62]{Shor's algorithm}, many of the notations}");
 	TPTPaso1->AddText("#scale[0.9]{are confusing. To address this, the notation used is clarified:}");
 	TPTPaso1->AddText("#scale[0.9]{#font[62]{Number to factor: N = P*Q}}");
 	TPTPaso1->AddText("#scale[0.9]{#font[62]{Number of Possible States of the Quantum System: N* = 2^{n}}}");
 	TPTPaso1->AddText("#scale[0.9]{#font[62]{Quantum Fourier Transform dagger |x#GT: QFT^{+}|x#GT }}");
 	TPTPaso1->AddText("#scale[0.9]{In Shor's algorithm, the #font[62]{possible solutions} are reached when they approach}");
 	TPTPaso1->AddText("#scale[0.9]{the following mathematical expression: #font[62]{#frac{jN}{r} = M}}");
 	TPTPaso1->AddText("");
 	TPTPaso1->Draw();
 	
 	//Texto dentro del pad2
	paso2->cd();
	TPaveText *TPTPaso2 = new TPaveText(0.001 ,0.009, 0.995, 0.995, "NDC"); 
 	TPTPaso2->SetTextFont(42);
	TPTPaso2->SetFillColor(kGreen-10); 
	TPTPaso2->SetShadowColor(kGray);
	TPTPaso2->SetTextAlign(12);
	TPTPaso2->SetMargin(0.03);
	TPTPaso2->AddText("");
 	TPTPaso2->AddText("#font[62]{#scale[1.5]{Hadamard Gate}}");
 	TPTPaso2->AddText("");
 	TPTPaso2->AddText("the #font[62]{Hadamard gate} creates the #font[62]{superposition of possible states} of the");
 	TPTPaso2->AddText("system in a #font[62]{equiprobable} manner. Mathematically, the expression applied to");
 	TPTPaso2->AddText("any state of #font[62]{n qubits |x#GT^{#otimes n}} is:");
 	TPTPaso2->AddText("");
 	TPTPaso2->AddText("[ H^{#otimes n}|x#GT^{#otimes n}]  = #frac{1}{#sqrt{N*}}[#sum_{x=0}^{N*-1}|x#GT^{#otimes n}]");
 	TPTPaso2->AddText("");
 	TPTPaso2->AddText("Since the system remains in a superposition, when performing various operations");
 	TPTPaso2->AddText("interferences occur that help to #font[62]{increase the probability} of the answer and");
 	TPTPaso2->AddText("have a correct solution.");
 	TPTPaso2->AddText("");
 	TPTPaso2->Draw();
 	
 	//Texto dentro del pad3
 	paso3->cd();
	TPaveText *TPTPaso3 = new TPaveText(0.001 ,0.009, 0.995, 0.995, "NDC"); 
 	TPTPaso3->SetTextFont(42);
	TPTPaso3->SetFillColor(kMagenta-10); 
	TPTPaso3->SetShadowColor(kGray);
	TPTPaso3->SetTextAlign(12);
	TPTPaso3->SetMargin(0.03);
	TPTPaso3->AddText("");
 	TPTPaso3->AddText("#font[62]{#scale[1.5]{Modulo 2 Addition #oplus}}");
 	TPTPaso3->AddText("");
 	TPTPaso3->AddText("In the #font[62]{Shor's algorithm}, this operation is defined to find the #font[62]{value of the}");
 	TPTPaso3->AddText("#font[62]{of the modular periodicity function U_{a, N}}. Given the properties it satisfies in");
 	TPTPaso3->AddText("quantum computing, it can be defined as:");
 	TPTPaso3->AddText("");
 	TPTPaso3->AddText("#font[62]{a #otimes b = 0  if a and b are equal numbers}");
 	TPTPaso3->AddText("#font[62]{a #otimes b = 1  if a and b are different numbers}");
 	TPTPaso3->AddText("");
 	TPTPaso3->AddText("By satisfying this property, the periodicity value #font[62]{r} of the main modular function in");
 	TPTPaso3->AddText("the #font[62]{Shor's algorithm.}");
 	TPTPaso3->AddText("");
 	TPTPaso3->Draw();
 	
 	//Texto dentro del pad4
 	paso4->cd();
	TPaveText *TPTPaso4 = new TPaveText(0.001 ,0.009, 0.995, 0.995, "NDC"); 
 	TPTPaso4->SetTextFont(42);
	TPTPaso4->SetFillColor(kCyan-10); 
	TPTPaso4->SetShadowColor(kGray);
	TPTPaso4->SetTextAlign(12);
	TPTPaso4->SetMargin(0.03);
	TPTPaso4->AddText("");
 	TPTPaso4->AddText("#font[62]{#scale[1.5]{QFT^{+}}} ");
 	TPTPaso4->AddText("");
 	TPTPaso4->AddText("the #font[62]{Quantum Fourier Transform} is a tool used alongside");
 	TPTPaso4->AddText("with the #font[62]{modulo 2 addition} operation to find the value of the #font[62]{periodicity}");
 	TPTPaso4->AddText("of the function. The main characteristic is that it makes better use of the");
 	TPTPaso4->AddText("use of #font[62]{constructive and destructive interference}, leaving only possible");
 	TPTPaso4->AddText("values where to find the #font[62]{factors of N}. Mathematically, the equation is represented");
 	TPTPaso4->AddText("as:");
 	TPTPaso4->AddText("");
 	TPTPaso4->AddText("QFT^{+}|x#GT^{#otimes n} = #frac{1}{#sqrt{N*}}#sum_{y=0}^{N*-1} e^{#frac{-2#pi ixy}{N*}}|y#GT^{#otimes n}");
 	TPTPaso4->AddText("");
 	TPTPaso4->Draw();

	ConceptosCuanticos->Update();
        ConceptosCuanticos->SetEditable(0);
}
/*************************************************************/
void MyMainFrame::DoConceptsCircuit(){

TCanvas *ConceptosCircuito = fRootEmbeddedCanvasDRAWCIRCUIT->GetCanvas();
ConceptosCircuito->SetFixedAspectRatio();
ConceptosCircuito->SetFillColor(0);
ConceptosCircuito->SetEditable(1);
ConceptosCircuito->Clear();
ConceptosCircuito->cd();

TPaveText *Pasos_Clasicos = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
Pasos_Clasicos->SetTextFont(62);
Pasos_Clasicos->SetFillColor(0); 
Pasos_Clasicos->SetShadowColor(kGray);
Pasos_Clasicos->SetMargin(0.1);
Pasos_Clasicos->AddText("#color[2]{Con}cepts of the Shor's Algorithm #color[4]{Cir}cuit");
Pasos_Clasicos->Draw();

//Creacion de las separaciones 
	TPad *paso1 = new TPad("pad1","This is pad1",0.01 ,0.42, 0.50, 0.83); 
	paso1->SetFillColor(0);
	paso1->Draw();
	
	TPad *paso2 = new TPad("pad2","This is pad2",0.51 ,0.42, 0.99, 0.83); 
	paso2->SetFillColor(0);
	paso2->Draw();

	TPad *paso3 = new TPad("pad3","This is pad3",0.01, 0.01, 0.50, 0.40);
	paso3->SetFillColor(0);
	paso3->Draw();
	
	TPad *paso4 = new TPad("pad3","This is pad3",0.51, 0.01, 0.99, 0.40);
	paso4->SetFillColor(0);
	paso4->Draw();
	
//Texto dentro del pad1
	//Texto dentro del pad1
	paso1->cd();
	TPaveText *TPTPaso1 = new TPaveText(0.001 ,0.009, 0.995, 0.995, "NDC"); 
 	TPTPaso1->SetTextFont(42);
	TPTPaso1->SetFillColor(kBlue-10); 
	TPTPaso1->SetShadowColor(kGray);
	TPTPaso1->SetTextAlign(12);
	TPTPaso1->SetMargin(0.03);
	TPTPaso1->AddText("");
 	TPTPaso1->AddText("#font[62]{#scale[1.5]{Hadamard Gate}}");
 	TPTPaso1->AddText("");
 	TPTPaso1->AddText("the #font[62]{Hadamard gate} establishes the #font[62]{superposition of the input qubits},");
 	TPTPaso1->AddText("denoted as #font[62]{|x#GT}");
 	TPTPaso1->AddText("The superposition created by the Hadamard gate allows the #font[62]{phases}");
 	TPTPaso1->AddText("different quantum paths #font[62]{interfere} with each other in later stages of the");
 	TPTPaso1->AddText("#font[62]{Shor's algorithm}");
 	TPTPaso1->AddText("");
 	TPTPaso1->Draw();
 	
 	//Texto dentro del pad2
	paso2->cd();
	TPaveText *TPTPaso2 = new TPaveText(0.001 ,0.009, 0.995, 0.995, "NDC"); 
 	TPTPaso2->SetTextFont(42);
	TPTPaso2->SetFillColor(kGreen-10); 
	TPTPaso2->SetShadowColor(kGray);
	TPTPaso2->SetTextAlign(12);
	TPTPaso2->SetMargin(0.03);
	TPTPaso2->AddText("");
 	TPTPaso2->AddText("#font[62]{#scale[1.5]{Gate U_{a, N}}}");
 	TPTPaso2->AddText("");
 	TPTPaso2->AddText("the #font[62]{U_{a, N} gate} is one of the most important steps in the development of the");
 	TPTPaso2->AddText("quantum circuit, as it helps facilitate the #font[62]{period finding} of the function");
 	TPTPaso2->AddText("#font[62]{F_{a, N} = a^{r}mod N} which modifies the quantum states in such a way that");
 	TPTPaso2->AddText("the #font[62]{amplitude of each state receives a phase dependent on x} and");
 	TPTPaso2->AddText("subsequently the quantum Fourier transform is applied to make it more evident");
 	TPTPaso2->AddText("the result");
 	TPTPaso2->AddText("");
 	TPTPaso2->Draw();
 	
 	//Texto dentro del pad3
 	paso3->cd();
	TPaveText *TPTPaso3 = new TPaveText(0.001 ,0.009, 0.995, 0.995, "NDC"); 
 	TPTPaso3->SetTextFont(42);
	TPTPaso3->SetFillColor(kMagenta-10); 
	TPTPaso3->SetShadowColor(kGray);
	TPTPaso3->SetTextAlign(12);
	TPTPaso3->SetMargin(0.03);
	TPTPaso3->AddText("");
 	TPTPaso3->AddText("#font[62]{#scale[1.5]{QFT^{+}}} ");
 	TPTPaso3->AddText("");
 	TPTPaso3->AddText("the #font[62]{Quantum Fourier Transform} transforms the quantum state from");
 	TPTPaso3->AddText("the domain of the values of x to the domain of the #font[62]{frequency}, which produces a");
 	TPTPaso3->AddText("#font[62]{quantum interference} in the results. The idea is that the valuesFound");
 	TPTPaso3->AddText("correspond to multiples of the #font[62]{period r} where it is reinforced, and the other values");
 	TPTPaso3->AddText("are canceled out due to the #font[62]{destructive interference}.");
 	TPTPaso3->AddText("");
 	TPTPaso3->Draw();
 	
 	//Texto dentro del pad4
 	paso4->cd();
	TPaveText *TPTPaso4 = new TPaveText(0.001 ,0.009, 0.995, 0.995, "NDC"); 
 	TPTPaso4->SetTextFont(42);
	TPTPaso4->SetFillColor(kCyan-10); 
	TPTPaso4->SetShadowColor(kGray);
	TPTPaso4->SetTextAlign(12);
	TPTPaso4->SetMargin(0.03);
	TPTPaso4->AddText("");
 	TPTPaso4->AddText("#font[62]{#scale[1.5]{Measurement Gates}}");
 	TPTPaso4->AddText("");
 	TPTPaso4->AddText("The measurement gates work to obtain the #font[62]{results} of the operations following");
 	TPTPaso4->AddText("each quantum operation. These measurements are the resulting values, which");
 	TPTPaso4->AddText("is why they are connected in the interface so that it is the last step to be");
 	TPTPaso4->AddText("performed both #font[62]{classically} and #font[62]{quantumly}. In the operations, performing");
 	TPTPaso4->AddText("a measurement means selecting one of the resulting values from the operation,");
 	TPTPaso4->AddText("as seen in the #font[62]{QUANTUM} and #font[62]{CLASSICAL} sections after selecting");
 	TPTPaso4->AddText("the #font[62]{values NUM. FACTOR and Value a}.");
 	TPTPaso4->AddText("");
 	TPTPaso4->Draw();

	ConceptosCircuito->Update();
        ConceptosCircuito->SetEditable(0);
}
/*************************************************************/
void MyMainFrame::DoClassical(){

fTextButtonBACK->SetState(kButtonDisabled, kTRUE);
//Inicio de los paso
TCanvas *Clasico = fRootEmbeddedCanvasDRAWCLASSICAL->GetCanvas();
Clasico->SetFixedAspectRatio();
Clasico->SetFillColor(0);
Clasico->SetEditable(1);
Clasico->Clear();
Clasico->cd();

TPaveText *Pasos_Clasicos = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
Pasos_Clasicos->SetTextFont(62);
Pasos_Clasicos->SetFillColor(0); 
Pasos_Clasicos->SetShadowColor(kGray);
Pasos_Clasicos->SetMargin(0.1);
Pasos_Clasicos->AddText("Steps of Shor's Algorithm in #color[2]{Clas}sical #color[4]{For}m");
Pasos_Clasicos->Draw();

//Creacion de las separaciones 
	TPad *paso1 = new TPad("pad1","This is pad1",0.01 ,0.42, 0.50, 0.83); 
	paso1->SetFillColor(0);
	paso1->Draw();
	
	TPad *paso2 = new TPad("pad2","This is pad2",0.51 ,0.42, 0.99, 0.83); 
	paso2->SetFillColor(0);
	paso2->Draw();

	TPad *paso3 = new TPad("pad3","This is pad3",0.01, 0.01, 0.50, 0.40);
	paso3->SetFillColor(0);
	paso3->Draw();
	
	TPad *paso4 = new TPad("pad3","This is pad3",0.51, 0.01, 0.99, 0.40);
	paso4->SetFillColor(0);
	paso4->Draw();
	
//Texto dentro del pad1
	//Texto dentro del pad1
	paso1->cd();
	TPaveText *TPTPaso1 = new TPaveText(0.001 ,0.009, 0.995, 0.995, "NDC"); 
 	TPTPaso1->SetTextFont(42);
	TPTPaso1->SetFillColor(kBlue-10); 
	TPTPaso1->SetShadowColor(kGray);
	TPTPaso1->SetTextAlign(12);
	TPTPaso1->SetMargin(0.04);
	TPTPaso1->AddText("");
 	TPTPaso1->AddText("  #font[62]{#scale[1.7]{STEP #1}}");
 	TPTPaso1->AddText("");
 	TPTPaso1->AddText("The first step is to find a value that is #font[62]{coprime} with the number you");
 	TPTPaso1->AddText("want to factor using the Euclidean algorithm to find the #font[62]{GCD} between");
 	TPTPaso1->AddText("the numbers #font[62]{a} and #font[62]{N}.");
 	TPTPaso1->AddText("If their Greatest Common Divisor #font[62]{(GCD)} is 1, then the numbers are");
 	TPTPaso1->AddText("coprime with each other.");
 	TPTPaso1->AddText("");
 	TPTPaso1->Draw();
 	
 	//Texto dentro del pad2
	paso2->cd();
	TPaveText *TPTPaso2 = new TPaveText(0.001 ,0.009, 0.995, 0.995, "NDC"); 
 	TPTPaso2->SetTextFont(42);
	TPTPaso2->SetFillColor(kGreen-10); 
	TPTPaso2->SetShadowColor(kGray);
	TPTPaso2->SetTextAlign(12);
	TPTPaso2->SetMargin(0.04);
	TPTPaso2->AddText("");
 	TPTPaso2->AddText("  #font[62]{#scale[1.7]{STEP #2}}");
 	TPTPaso2->AddText("");
 	TPTPaso2->AddText("Find the order #font[62]{r} of the function #font[62]{F_{a,N}= a^{r} (mod N)}");
 	TPTPaso2->AddText("where r is the #font[62]{period of the function} and ensure that the");
 	TPTPaso2->AddText("following definition is met to choose the value of #font[62]{r}");
 	TPTPaso2->AddText("  #font[62]{ a^{r}#equiv 1(mod N) }");
 	TPTPaso2->AddText("");
 	TPTPaso2->Draw();
 	
 	//Texto dentro del pad3
 	paso3->cd();
	TPaveText *TPTPaso3 = new TPaveText(0.001 ,0.009, 0.995, 0.995, "NDC"); 
 	TPTPaso3->SetTextFont(42);
	TPTPaso3->SetFillColor(kMagenta-10); 
	TPTPaso3->SetShadowColor(kGray);
	TPTPaso3->SetTextAlign(12);
	TPTPaso3->SetMargin(0.04);
	TPTPaso3->AddText("");
 	TPTPaso3->AddText("  #font[62]{#scale[1.7]{STEP #3}}");
 	TPTPaso3->AddText("");
 	TPTPaso3->AddText("For step 3, from the previous result, r must be even for it to");
 	TPTPaso3->AddText("be satisfied.");
 	TPTPaso3->AddText("");
 	TPTPaso3->AddText("#font[62]{ X #equiv a^{#frac{r}{2}}(mod N)}");
 	TPTPaso3->AddText("");
 	TPTPaso3->AddText("In this way, it is applied that the #font[62]{factors P and Q} are at the");
 	TPTPaso3->AddText("#font[62]{Greatest} #font[62]{Common Divisor}");
 	TPTPaso3->AddText("");
 	TPTPaso3->Draw();
 	
 	//Texto dentro del pad4
 	paso4->cd();
	TPaveText *TPTPaso4 = new TPaveText(0.001 ,0.009, 0.995, 0.995, "NDC"); 
 	TPTPaso4->SetTextFont(42);
	TPTPaso4->SetFillColor(kCyan-10); 
	TPTPaso4->SetShadowColor(kGray);
	TPTPaso4->SetTextAlign(12);
	TPTPaso4->SetMargin(0.04);
 	TPTPaso4->AddText("");
 	TPTPaso4->AddText("  #font[62]{#scale[1.7]{STEP #4}}");
 	TPTPaso4->AddText("");
 	TPTPaso4->AddText("For the final step, the greatest common divisor must be");
 	TPTPaso4->AddText("calculated to find #font[62]{P} and #font[62]{Q} in such a way that");
 	TPTPaso4->AddText("#font[62]{P = GCD(X+1, N)}  and #font[62]{Q = GCD(X-1, N)}");
 	TPTPaso4->AddText("Thus, we obtain the #font[62]{result of the factorization.}");
 	TPTPaso4->AddText("");
 	TPTPaso4->Draw();

	Clasico->Update();
        Clasico->SetEditable(1);
}
/*************************************************************/
void MyMainFrame::CondClassical(){

Int_t Valueopt1 = fComboBoxNUMSFACTORS->GetSelected();
Int_t Valueopt2 = fComboBoxVALUESA->GetSelected();

TCanvas *canvas1 = fRootEmbeddedCanvasDRAWCLASSICAL->GetCanvas();
canvas1->SetFixedAspectRatio();
canvas1->Clear();
canvas1->cd();

if(Valueopt1 == 15){
  switch (Valueopt2){
     case 13:{
            ///////////////////////////////////////////// caso a=13 ///////////////////////////////////////
     	if(Breakopt == 1){
     	TPaveText *Paso1_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso1_clasico->SetTextFont(62);
	Paso1_clasico->SetFillColor(kBlue-10); 
	Paso1_clasico->SetShadowColor(kGray);
	Paso1_clasico->SetMargin(0.1);
	Paso1_clasico->AddText("Step #1");
	Paso1_clasico->Draw();
     	
     	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "Number to be factored:");
	
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.3, 0.79, "#color[4]{15} = #color[2]{P}*#color[8]{Q}");
	
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.05, 0.70, "Value of a:");
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.3, 0.71, "#color[6]{13}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.15, 0.60, "Verifying #font[62]{#color[8]{Euclid's Algorithm}}:");
	
	lineaV1 = new TLine(0.2, 0.1, 0.2, 0.5);
	lineaV2 = new TLine(0.3, 0.1, 0.3, 0.5);
	lineaV3 = new TLine(0.4, 0.1, 0.4, 0.5);
	
	lineaH1 = new TLine(0.1, 0.2, 0.5, 0.2);
	lineaH2 = new TLine(0.1, 0.4, 0.5, 0.4);
	
	//primer numero del algoritmo de euclides
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.13, 0.32, "#color[4]{15}");
	
	//segundo numero del algoritmo de euclides 
	l7->SetTextFont(42); 
	l7->SetTextColor(2); 
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.23, 0.32, "#color[6]{13}");
	
	//tercer numero del algoritmo de euclides 
	l8->SetTextFont(42); 
	l8->SetTextColor(1); 
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.24, 0.48, "1");
	
	//cuarto numero del algoritmo de euclides
	l9->SetTextFont(42); 
	l9->SetTextColor(1); 
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.24, 0.15, "2");
	
	//quinto numero del algoritmo de euclides
	l10->SetTextFont(42); 
	l10->SetTextColor(1); 
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.34, 0.32, "2");
	
	//sexto numero del algoritmo de euclides 
	l11->SetTextFont(42); 
	l11->SetTextColor(1); 
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.34, 0.48, "6");
	
	//septimo numero del algoritmo de euclides 
	l12->SetTextFont(42); 
	l12->SetTextColor(1); 
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.34, 0.15, "1");
	
	//octavo numero del algoritmo de euclides 
	l13->SetTextFont(42); 
	l13->SetTextColor(1); 
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.44, 0.32, "1");
	
	//Texto junto al algoritmo de euclides
	TPaveText *EuclidesAlgor = new TPaveText(0.65, 0.1, 0.95, 0.7, "NDC"); 
	EuclidesAlgor->SetTextFont(42);
	EuclidesAlgor->SetFillColor(kGreen-10); 
	EuclidesAlgor->SetShadowColor(kGray);
	EuclidesAlgor->SetMargin(0.1);
	EuclidesAlgor->AddText("#font[62]{#scale[1.4]{Euclid's algorithm}}");
	EuclidesAlgor->AddText("the #font[62]{Euclid's algorithm} allows determining");
	EuclidesAlgor->AddText("if the selection of the value of #font[62]{a} is");
	EuclidesAlgor->AddText("a number coprime with #font[62]{N}");
	EuclidesAlgor->AddText("which is an important condition for");
	EuclidesAlgor->AddText("moving forward with the next steps.");
	EuclidesAlgor->Draw();
	
	flecha1 = new TArrow(0.53, 0.3, 0.63, 0.3, 0.01, "<>");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	
	lineaV1->SetLineColor(kBlack);
	lineaV2->SetLineColor(kBlack);
	lineaV3->SetLineColor(kBlack);
	lineaH1->SetLineColor(kBlack);
	lineaH1->SetLineColor(kBlack);
	
	lineaV1->Draw();
	lineaV2->Draw();
	lineaV3->Draw();
	lineaH1->Draw();
	lineaH2->Draw();
     	
     	//Segundo Canvas
	TCanvas *ExpPaso1 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1->SetFixedAspectRatio();
	ExpPaso1->SetFillColor(0);
	ExpPaso1->SetEditable(1);
	ExpPaso1->Clear();
	ExpPaso1->Update();
	
	TPaveText *Paso1_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	
	Paso1_Clasico1_Exp->SetTextFont(42);
	Paso1_Clasico1_Exp->SetFillColor(0); 
	Paso1_Clasico1_Exp->SetShadowColor(kGray);
	Paso1_Clasico1_Exp->SetTextAlign(12);
	Paso1_Clasico1_Exp->SetMargin(0.01);
	Paso1_Clasico1_Exp->AddText("For #font[62]{step 1}, it is necessary to identify that the values to be found are #font[62]{P} and #font[62]{Q}");
	Paso1_Clasico1_Exp->AddText("Then, Euclid's algorithm is implemented to verify if #font[62]{a} and #font[62]{N} are coprime. The steps to solve it can be found by pressing");
	Paso1_Clasico1_Exp->AddText("the #font[62]{CLEAR} button and then #font[62]{CONCEPTS}.");
	Paso1_Clasico1_Exp->AddText("If the final result is 1, then the chosen number is coprime with the number you want to factor.");
 	Paso1_Clasico1_Exp->Draw();     	
     	
     	ExpPaso1->Update();
	ExpPaso1->SetEditable(0);   	
     }	
  
//segundo click next
     	if(Breakopt == 2){
     	
     	TPaveText *Paso2_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso2_clasico->SetTextFont(62);
	Paso2_clasico->SetFillColor(kGreen-10); 
	Paso2_clasico->SetShadowColor(kGray);
	Paso2_clasico->SetMargin(0.1);
	Paso2_clasico->AddText("Step #2");
	Paso2_clasico->Draw();
	
	TPad *Tabla_1caso = new TPad("pad2","This is pad2",0.01 ,0.01, 0.5, 0.80); 
	Tabla_1caso->SetFillColor(0);
	Tabla_1caso->Draw();

	TPad *Grafico_1caso = new TPad("pad3","This is pad3",0.5, 0.01, 0.99, 0.80);
	Grafico_1caso->SetFillColor(0);
	Grafico_1caso->Draw();
	
	//primer Tpad de la tabla
        Tabla_1caso->cd();
        l1 = new TLatex();
	
	l1->SetTextColor(4); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.3, 0.97, "#font[62]{Data Table}"); 
	
	TPaveText *table = new TPaveText(0.5, 0.1, 0.90, 0.90, "NDC");
	table->SetTextFont(42);
    	table->SetBorderSize(2);
	table->SetFillColor(kYellow-10); 
	table->SetShadowColor(kGray);
    	table->SetTextAlign(22); 
    
    //Agregar filas a la tabla
    table->AddLine(0.5, 0.99, 0.5 , 0.001);
    table->AddText("    #font[62]{#scale[1.7]{r}}         #font[62]{#scale[1.7]{F_{a,N}}}");
    table->AddLine(0, 0.90, 1, 0.90);
    table->AddText("      1                                    13");
    table->AddText("      2                                     4");
    table->AddText("      3                                     7");
    table->AddText("  #font[62]{#color[2]{4}}           #font[62]{#color[2]{1}}");
    table->AddText("      5                                    13");
    table->AddText("      6                                     4");
    table->AddText("      7                                     7");
    table->AddText("      8                                     1");
    table->AddText("      9                                    13");
    
    // Dibujar la tabla en el canvas
    table->Draw();
    //Flecha
    	flecha1 = new TArrow(0.3, 0.54, 0.48, 0.54, 0.01, "<>");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
     	
    //Texto al lado de la flecha
    	l2 = new TLatex();
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.08, 0.54, "Value of #font[62]{r}"); 		
        
    	//Segundo TPad donde se encuentra el grafico
    	Grafico_1caso->cd(); 
    	//Crear el gráfico
    	const int nPoints = 9;
    	double x[nPoints];       
    	double y[nPoints];       

    	//Definir a y N
    	const double a = 13; 
    	const int N = 15;    

    	//Llenar los arreglos con valores
    	for (int r = 1; r <= nPoints; r++) {
        x[r - 1] = r;  

        //Calcular y = (a^r) mod N
        int result = static_cast<int>(pow(a, r)) % N; 
      //Asegurarse de que el resultado es positivo
        y[r - 1] = (result + N) % N; 
    	}
	
    	//Crear un gráfico de puntos
    	TGraph *graph = new TGraph(nPoints, x, y);

    	//Establecer propiedades del gráfico
    	graph->SetTitle("#font[62]{F_{a,N}= 13^{r} (mod15)};X;Y"); 
    	graph->SetMarkerStyle(20);              
    	graph->SetMarkerColor(kRed);           
    	graph->SetLineColor(kBlue);              
    	graph->SetLineWidth(2);                 

    	//Dibujar el gráfico
    	graph->Draw();    
    
	//Segundo Canvas
	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFixedAspectRatio();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	
	TPaveText *Paso2_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Paso2_Clasico1_Exp->SetTextFont(42);
	Paso2_Clasico1_Exp->SetFillColor(0); 
	Paso2_Clasico1_Exp->SetShadowColor(kGray);
	Paso2_Clasico1_Exp->SetTextAlign(12);
	Paso2_Clasico1_Exp->SetMargin(0.01);
	Paso2_Clasico1_Exp->AddText("For #font[62]{step 2}, it is necessary to create a #font[62]{data table of the modular function} to obtain the periodicity graph shown on the right");
	Paso2_Clasico1_Exp->AddText("and determine the correct value of #font[62]{r} chosen for subsequent steps. The value of #font[62]{r} will be the first one that makes #font[62]{F_{a,N} = 1}");
	Paso2_Clasico1_Exp->AddText("The data table shows the #font[62]{periodicity of the function}, as values of #font[62]{F_{a,N}} repeat after selecting #font[62]{r}.");
	Paso2_Clasico1_Exp->AddText("Thus, it is verified that the value of #font[62]{r} is even to proceed with the next step, and if it is odd, another value of #font[62]{a} is selected.");
 	Paso2_Clasico1_Exp->Draw();     	
     	
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(0); 
     	
     	}
//tercer click next     	
     	if(Breakopt == 3){
     	
     	TPaveText *Paso3_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso3_clasico->SetTextFont(62);
	Paso3_clasico->SetFillColor(kMagenta-10); 
	Paso3_clasico->SetShadowColor(kGray);
	Paso3_clasico->SetMargin(0.1);
	Paso3_clasico->AddText("Step #3");
	Paso3_clasico->Draw();
     	
     	//Expresion
     	l1 = new TLatex(); 
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.12, 0.72, "X = a^{#frac{r}{2}} (mod N)"); 
     	
     	
	//Reemplazo
	l2 = new TLatex();
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.1, 0.44, "X = 13^{#frac{4}{2}} (mod15)"); 
	
	//Respuesta
	l3 = new TLatex();
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.07, 0.13, "X = 13^{2} (mod15) = 4"); 
	
	//Flecha 1
	flecha1 = new TArrow(0.31, 0.72, 0.5, 0.72, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
     	
     	TPaveText *Paso3_clasico_TexFlecha1 = new TPaveText(0.55, 0.62, 0.94, 0.75, "NDC"); 
	Paso3_clasico_TexFlecha1->SetTextFont(42);
	Paso3_clasico_TexFlecha1->SetFillColor(kOrange-9); 
	Paso3_clasico_TexFlecha1->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha1->SetMargin(0.1);
	Paso3_clasico_TexFlecha1->AddText("Replace the value of #font[62]{r} in this expression.");
	Paso3_clasico_TexFlecha1->Draw();
     	
     	//Flecha 2
	flecha2 = new TArrow(0.31, 0.44, 0.5, 0.44, 0.01, ">");
	flecha2->SetLineColor(kRed);
     	flecha2->SetLineWidth(1);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
     	
     	TPaveText *Paso3_clasico_TexFlecha2 = new TPaveText(0.53, 0.30, 0.96, 0.50, "NDC"); 
	Paso3_clasico_TexFlecha2->SetTextFont(42);
	Paso3_clasico_TexFlecha2->SetFillColor(kAzure-9); 
	Paso3_clasico_TexFlecha2->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha2->SetMargin(0.1);
	Paso3_clasico_TexFlecha2->AddText("");
	Paso3_clasico_TexFlecha2->AddText("Since the value is #font[62]{even}, it can be used.");
	Paso3_clasico_TexFlecha2->AddText("If it is odd, this step cannot be performed and");
	Paso3_clasico_TexFlecha2->AddText("select a new value of #font[62]{a}.");
	Paso3_clasico_TexFlecha2->AddText("");
	Paso3_clasico_TexFlecha2->Draw();
     	
     	
     	//Flecha 3
	flecha3 = new TArrow(0.31, 0.13, 0.5, 0.13, 0.01, ">");
	flecha3->SetLineColor(kRed);
     	flecha3->SetLineWidth(1);
     	flecha3->SetLineStyle(1);
     	flecha3->Draw();
     	
     	TPaveText *Paso3_clasico_TexFlecha3 = new TPaveText(0.55, 0.05, 0.94, 0.17, "NDC"); 
	Paso3_clasico_TexFlecha3->SetTextFont(42);
	Paso3_clasico_TexFlecha3->SetFillColor(kTeal-9); 
	Paso3_clasico_TexFlecha3->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha3->SetMargin(0.1);
	Paso3_clasico_TexFlecha3->AddText("Final #font[62]{result} after the operation.");
	Paso3_clasico_TexFlecha3->Draw();
	
 //Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
     	ExpPaso3->SetFixedAspectRatio();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	
	Paso3_Clasico1_Exp->SetTextFont(42);
	Paso3_Clasico1_Exp->SetFillColor(0); 
	Paso3_Clasico1_Exp->SetShadowColor(kGray);
	Paso3_Clasico1_Exp->SetTextAlign(12);
	Paso3_Clasico1_Exp->SetMargin(0.01);
	Paso3_Clasico1_Exp->AddText("For #font[62]{step 3}, once the value of #font[62]{r} that satisfies the condition is determined, the following procedure is solved to find the value of #font[62]{X} and obtain");
	Paso3_Clasico1_Exp->AddText("the values of #font[62]{P} and #font[62]{Q}.");
	Paso3_Clasico1_Exp->AddText("This operation is the same as the previous step because it is solved through #font[62]{modular algebra}.");
	Paso3_Clasico1_Exp->AddText("By finding this result of #font[62]{X}, it is possible to obtain the values of #font[62]{P} and #font[62]{Q} in the next step.");
 	Paso3_Clasico1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(0); 	
     	}
//cuarto click next
     	if(Breakopt == 4){
     	
        TPaveText *Paso4_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso4_clasico->SetTextFont(62);
	Paso4_clasico->SetFillColor(kCyan-10); 
	Paso4_clasico->SetShadowColor(kGray);
	Paso4_clasico->SetMargin(0.1);
	Paso4_clasico->AddText("Step #4");
	Paso4_clasico->Draw();
     	
     	//Linea para dividir los resultados
     	lineaV1 = new TLine(0.5, 0.8, 0.5, 0.01);
     	lineaV1->SetLineColor(kBlack);
     	lineaV1->Draw(); 
     	
     	//Cuadro de resultado 1
     	TPaveText *Resultado_1 = new TPaveText(0.1, 0.7, 0.4, 0.8, "NDC"); 
	Resultado_1->SetTextFont(42);
	Resultado_1->SetFillColor(kBlue-10); 
	Resultado_1->SetShadowColor(kGray);
	Resultado_1->SetMargin(0.1);
	Resultado_1->AddText("P");
	Resultado_1->Draw();
     	
     	
     	//Resultado 1
     	l1 = new TLatex();
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.65, "GCD(X-1, N)");

	l2 = new TLatex(); 
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.01, 0.55, "GCD(4-1, 15)");
	
	l3 = new TLatex();
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.01, 0.45, "GCD(3, 15)");
	
	l3 = new TLatex();
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.01, 0.35, "GCD(3, 15) = 3");
	
	l4 = new TLatex(); 
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.01, 0.35, "GCD(3, 15) = 3");
	
	l5 = new TLatex(); 
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.35, 0.65, "Equation");
	
	l6 = new TLatex(); 
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.35, 0.55, "Replace");
	
	l7 = new TLatex(); 
	l7->SetTextFont(42); 
	l7->SetTextColor(1); 
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.35, 0.45, "Solve");
	
	l8 = new TLatex(); 
	l8->SetTextFont(42); 
	l8->SetTextColor(1); 
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.35, 0.35, "Solution");
	
	//Cuadro donde muestro P=3
	TPaveText *Resultado_p = new TPaveText(0.08, 0.1, 0.4, 0.2, "NDC"); 
	Resultado_p->SetTextFont(42);
	Resultado_p->SetFillColor(kYellow-10); 
	Resultado_p->SetShadowColor(kGray);
	Resultado_p->SetMargin(0.1);
	Resultado_p->AddText("First result #color[2]{P} = 3");
	Resultado_p->Draw();
	
	//Flechas
	flecha1 = new TArrow(0.2, 0.65, 0.3, 0.65, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	flecha2 = new TArrow(0.2, 0.55, 0.3, 0.55, 0.01, ">");
	flecha2->SetLineColor(kRed);
     	flecha2->SetLineWidth(1);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
	
	flecha3 = new TArrow(0.2, 0.45, 0.3, 0.45, 0.01, ">");
	flecha3->SetLineColor(kRed);
     	flecha3->SetLineWidth(1);
     	flecha3->SetLineStyle(1);
     	flecha3->Draw();
	
	flecha4 = new TArrow(0.2, 0.35, 0.3, 0.35, 0.01, ">");
	flecha4->SetLineColor(kRed);
     	flecha4->SetLineWidth(1);
     	flecha4->SetLineStyle(1);
     	flecha4->Draw();
     	
     	//Cuadro de resultado 2
     	TPaveText *Resultado_2 = new TPaveText(0.6, 0.7, 0.9, 0.8, "NDC"); 
	Resultado_2->SetTextFont(42);
	Resultado_2->SetFillColor(kBlue-10); 
	Resultado_2->SetShadowColor(kGray);
	Resultado_2->SetMargin(0.1);
	Resultado_2->AddText("Q");
	Resultado_2->Draw();
	
	//Cuadro donde muestro Q=5
	TPaveText *Resultado_q = new TPaveText(0.6, 0.1, 0.9, 0.2, "NDC"); 
	Resultado_q->SetTextFont(42);
	Resultado_q->SetFillColor(kYellow-10); 
	Resultado_q->SetShadowColor(kGray);
	Resultado_q->SetMargin(0.1);
	Resultado_q->AddText("Second result #color[8]{Q} = 5");
	Resultado_q->Draw();
	
	//Resultado 2
     	l9 = new TLatex(); 
	l9->SetTextFont(42); 
	l9->SetTextColor(1); 
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.55, 0.65, "GCD(X+1, N)");

	l10 = new TLatex(); 
	l10->SetTextFont(42); 
	l10->SetTextColor(1); 
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.55, 0.55, "GCD(4+1, 15)");
	
	l11 = new TLatex(); 
	l11->SetTextFont(42); 
	l11->SetTextColor(1); 
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.55, 0.45, "GCD(5, 15)");
	
	l12 = new TLatex(); 
	l12->SetTextFont(42); 
	l12->SetTextColor(1); 
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.55, 0.35, "GCD(5, 15) = 5");
	
	l13 = new TLatex(); 
	l13->SetTextFont(42); 
	l13->SetTextColor(1); 
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.85, 0.65, "Equation");
	
	l14 = new TLatex(); 
	l14->SetTextFont(42); 
	l14->SetTextColor(1); 
	l14->SetTextAlign(12); 
	l14->DrawLatex(0.85, 0.55, "Replace");
	
	l15 = new TLatex(); 
	l15->SetTextFont(42); 
	l15->SetTextColor(1); 
	l15->SetTextAlign(12); 
	l15->DrawLatex(0.85, 0.45, "Solve");
	
	l16 = new TLatex(); 
	l16->SetTextFont(42); 
	l16->SetTextColor(1); 
	l16->SetTextAlign(12); 
	l16->DrawLatex(0.85, 0.35, "Solution");
	
	//Flechas
	flecha5 = new TArrow(0.72, 0.65, 0.82, 0.65, 0.01, ">");
	flecha5->SetLineColor(kRed);
     	flecha5->SetLineWidth(1);
     	flecha5->SetLineStyle(1);
     	flecha5->Draw();
	
	flecha6 = new TArrow(0.72, 0.55, 0.82, 0.55, 0.01, ">");
	flecha6->SetLineColor(kRed);
     	flecha6->SetLineWidth(1);
     	flecha6->SetLineStyle(1);
     	flecha6->Draw();
	
	flecha7 = new TArrow(0.72, 0.45, 0.82, 0.45, 0.01, ">");
	flecha7->SetLineColor(kRed);
     	flecha7->SetLineWidth(1);
     	flecha7->SetLineStyle(1);
     	flecha7->Draw();
	
	flecha8 = new TArrow(0.72, 0.35, 0.82, 0.35, 0.01, ">");
	flecha8->SetLineColor(kRed);
     	flecha8->SetLineWidth(1);
     	flecha8->SetLineStyle(1);
     	flecha8->Draw();
	
	//Segundo canvas    	
     	TCanvas *ExpPaso4 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
     	ExpPaso4->SetFixedAspectRatio();
	ExpPaso4->SetFillColor(0);
	ExpPaso4->SetEditable(1);
	ExpPaso4->Clear();
	ExpPaso4->Update();
	
	TPaveText *Paso4_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Paso4_Clasico1_Exp->SetTextFont(42);
	Paso4_Clasico1_Exp->SetFillColor(0);
	Paso4_Clasico1_Exp->SetShadowColor(kGray);
	Paso4_Clasico1_Exp->SetTextAlign(12);
	Paso4_Clasico1_Exp->SetMargin(0.01);
	Paso4_Clasico1_Exp->AddText("For #font[62]{step 4}, calculate the greatest common divisor of the highlighted equations, and the expected result gives the values of #font[62]{P} and #font[62]{Q}");
	Paso4_Clasico1_Exp->AddText("concluding the #font[62]{Shor's algorithm in its classical form}.");
	Paso4_Clasico1_Exp->AddText("Select the top tabs to view the #font[62]{circuit} or the #font[62]{quantum steps}.");
	Paso4_Clasico1_Exp->AddText("To return, press the #font[62]{CLEAR} button and select a #font[62]{new value to factor}.");
 	Paso4_Clasico1_Exp->Draw();     	
     	
     	ExpPaso4->Update();
	ExpPaso4->SetEditable(0); 
     	}
     	}
     	if(Breakopt == 5){
     	fTextButtonBACK->SetState(kButtonUp, kTRUE);
     	fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
     	DoClassical();
     	CambioTab(0);
     	}
	break; 
       ////////////////////////////////////////////////// Caso a=14 ////////////////////////////////////////////////////////////////	
     	case 14:{ 
      	if(Breakopt == 1){
      	TPaveText *Paso1_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso1_clasico->SetTextFont(62);
	Paso1_clasico->SetFillColor(kBlue-10); 
	Paso1_clasico->SetShadowColor(kGray);
	Paso1_clasico->SetMargin(0.1);
	Paso1_clasico->AddText("Step #1");
	Paso1_clasico->Draw();
     	
     	//Lineas
     	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	
     	//Textos 
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "Number to be factored:");
	 
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.3, 0.79, "#color[4]{15} = #color[2]{P}*#color[8]{Q}");
	 
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.05, 0.70, "Value of a:");
     	  
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.3, 0.70, "#color[6]{14}");
	 
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.15, 0.60, "Verifying #font[62]{#color[8]{Euclid's Algorithm}}:"); 
     	 
     	//Lineas del algoritmo de euclides
        lineaV1 = new TLine(0.2, 0.1, 0.2, 0.5);
	lineaV2 = new TLine(0.3, 0.1, 0.3, 0.5);
	
	lineaH1 = new TLine(0.1, 0.2, 0.4, 0.2);
	lineaH2 = new TLine(0.1, 0.4, 0.4, 0.4); 
	
	//primer numero del algoritmo de euclides
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.13, 0.31, "#color[4]{15}");
	
	//segundo numero del algoritmo de euclides 
	l7->SetTextFont(42); 
	l7->SetTextColor(1); 
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.24, 0.31, "#color[6]{14}");
	
	
	//tercer numero del algoritmo de euclides 
	l8->SetTextFont(42); 
	l8->SetTextColor(1); 
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.25, 0.48, "1");
	
	//cuarto numero del algoritmo de euclides 
	l9->SetTextFont(42); 
	l9->SetTextColor(1); 
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.25, 0.15, "2");
	
	//quinto numero del algoritmo de euclides 
	l10->SetTextFont(42); 
	l10->SetTextColor(1); 
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.35, 0.31, "1");
	
	lineaV1->SetLineColor(kBlack);
	lineaV2->SetLineColor(kBlack);
	lineaH1->SetLineColor(kBlack);
	lineaH1->SetLineColor(kBlack);
	
	lineaV1->Draw();
	lineaV2->Draw();
	lineaH1->Draw();
	lineaH2->Draw();
	
	//Texto junto al algoritmo de euclides
	TPaveText *EuclidesAlgor = new TPaveText(0.65, 0.1, 0.95, 0.7, "NDC"); 
	EuclidesAlgor->SetTextFont(42);
	EuclidesAlgor->SetFillColor(kGreen-10); 
	EuclidesAlgor->SetShadowColor(kGray);
	EuclidesAlgor->SetMargin(0.1);
	EuclidesAlgor->AddText("#font[62]{#scale[1.4]{Euclid's algorithm}}");
	EuclidesAlgor->AddText("the #font[62]{Euclid's algorithm} allows determining");
	EuclidesAlgor->AddText("if the selection of the value of #font[62]{a} is");
	EuclidesAlgor->AddText("a number coprime with #font[62]{N}");
	EuclidesAlgor->AddText("which is an important condition for");
	EuclidesAlgor->AddText("moving forward with the next steps.");
	EuclidesAlgor->Draw();
	
	flecha1 = new TArrow(0.43, 0.3, 0.63, 0.3, 0.01, "<>");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	//Segundo Canvas
	TCanvas *ExpPaso1 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1->SetFixedAspectRatio();
	ExpPaso1->SetFillColor(0);
	ExpPaso1->SetEditable(1);
	ExpPaso1->Clear();
	ExpPaso1->Update();
	
	TPaveText *Paso1_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	
	Paso1_Clasico1_Exp->SetTextFont(42);
	Paso1_Clasico1_Exp->SetFillColor(0); 
	Paso1_Clasico1_Exp->SetShadowColor(kGray);
	Paso1_Clasico1_Exp->SetTextAlign(12);
	Paso1_Clasico1_Exp->SetMargin(0.01);
	Paso1_Clasico1_Exp->AddText("For #font[62]{step 1}, it is necessary to identify that the values to be found are #font[62]{P} and #font[62]{Q}");
	Paso1_Clasico1_Exp->AddText("Then, Euclid's algorithm is implemented to verify if #font[62]{a} and #font[62]{N} are coprime. The steps to solve it can be found by pressing");
	Paso1_Clasico1_Exp->AddText("the #font[62]{CLEAR} button and then #font[62]{CONCEPTS}.");
	Paso1_Clasico1_Exp->AddText("If the final result is 1, then the chosen number is coprime with the number you want to factor.");
 	Paso1_Clasico1_Exp->Draw();     	
     	
     	ExpPaso1->Update();
	ExpPaso1->SetEditable(0); 
	}
	
//Segundo click a=14	
      if(Breakopt == 2){
     
     //Titulo
     	TPaveText *Paso2_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso2_clasico->SetTextFont(62);
	Paso2_clasico->SetFillColor(kGreen-10); 
	Paso2_clasico->SetShadowColor(kGray);
	Paso2_clasico->SetMargin(0.1);
	Paso2_clasico->AddText("Step #2");
	Paso2_clasico->Draw();
	
	TPad *Tabla_2caso = new TPad("pad2","This is pad2",0.01 ,0.01, 0.5, 0.80); 
	Tabla_2caso->SetFillColor(0);
	Tabla_2caso->Draw();

	TPad *Grafico_2caso = new TPad("pad3","This is pad3",0.5, 0.01, 0.99, 0.80);
	Grafico_2caso->SetFillColor(0);
	Grafico_2caso->Draw();
	
	
	//primer Tpad de la tabla
        Tabla_2caso->cd();
        l1 = new TLatex();
	
	l1->SetTextColor(4); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.3, 0.98, "#font[62]{Data Table}");
	
	//Tabla
     	TPaveText *table = new TPaveText(0.5, 0.1, 0.90, 0.90, "NDC");
     	table->SetTextFont(42);
    	table->SetBorderSize(2);
	table->SetFillColor(kYellow-10); 
	table->SetShadowColor(kGray);
    	table->SetTextAlign(22); 
    	
    	//Agregar filas a la tabla
    	table->AddLine(0.5, 0.99, 0.5 , 0.001);
    	table->AddText("   #font[62]{#scale[1.7]{r}}      #font[62]{#scale[1.7]{F_{a,N}}}");
    	table->AddLine(0, 0.90, 1, 0.90);
    	table->AddText("      1                         14");
    	table->AddText(" #font[62]{#color[2]{2}}        #font[62]{#color[2]{1}}");
    	table->AddText("      3                         14");
    	table->AddText("      4                          1");
    	table->AddText("      5                         14");
    	table->AddText("      6                          1");
    	table->AddText("      7                         14");
    	table->AddText("      8                          1");
    	table->AddText("      9                         14");
    
    	//Dibujar la tabla en el canvas
    	table->Draw();
    	
     	//Flecha
    	flecha1 = new TArrow(0.3, 0.70, 0.48, 0.70, 0.01, "<>");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
     	
      	//Texto al lado de la flecha
    	l2 = new TLatex(); 
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.08, 0.70, "Value of #font[62]{r}"); 
	
	//Segundo TPad donde se encuentra el grafico
    	Grafico_2caso->cd(); 
    	//Crear el gráfico
    	const int nPoints = 9;
    	double x[nPoints];
    	double y[nPoints];

    	//Definir a y N
    	const double a = 14; 
    	const int N = 15;    

    	//Llenar los arreglos con valores
    	for (int r = 1; r <= nPoints; r++) {
        x[r - 1] = r;  

        //Calcular y = (a^r) mod N
        int result = static_cast<int>(pow(a, r)) % N; 
      // Asegurarse de que el resultado es positivo
        y[r - 1] = (result + N) % N; 
    	}

    	//Crear un gráfico de puntos
    	TGraph *graph = new TGraph(nPoints, x, y);

    	//Establecer propiedades del gráfico
    	graph->SetTitle("#font[62]{F_{a,N}= 14^{r} (mod15)};X;Y"); 
    	graph->SetMarkerStyle(20);              
    	graph->SetMarkerColor(kRed);           
    	graph->SetLineColor(kBlue);              
    	graph->SetLineWidth(2);                 

    	//Dibujar el gráfico
    	graph->Draw();
	
	//Segundo Canvas
	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFixedAspectRatio();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	
	TPaveText *Paso2_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	
	Paso2_Clasico1_Exp->SetTextFont(42);
	Paso2_Clasico1_Exp->SetFillColor(0); 
	Paso2_Clasico1_Exp->SetShadowColor(kGray);
	Paso2_Clasico1_Exp->SetTextAlign(12);
	Paso2_Clasico1_Exp->SetMargin(0.01);
	Paso2_Clasico1_Exp->AddText("For #font[62]{step 2}, it is necessary to create a #font[62]{data table of the modular function} to obtain the periodicity graph shown on the right");
	Paso2_Clasico1_Exp->AddText("and determine the correct value of #font[62]{r} chosen for subsequent steps. The value of #font[62]{r} will be the first one that makes #font[62]{F_{a,N} = 1}");
	Paso2_Clasico1_Exp->AddText("The data table shows the #font[62]{periodicity of the function}, as values of #font[62]{F_{a,N}} repeat after selecting #font[62]{r}.");
	Paso2_Clasico1_Exp->AddText("Thus, it is verified that the value of #font[62]{r} is even to proceed with the next step, and if it is odd, another value of #font[62]{a} is selected.");
 	Paso2_Clasico1_Exp->Draw();     	
     	
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(0); 
	}
      
//tercer click next a=14 
	if(Breakopt == 3){
	
	TPaveText *Paso3_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso3_clasico->SetTextFont(62);
	Paso3_clasico->SetFillColor(kMagenta-10); 
	Paso3_clasico->SetShadowColor(kGray);
	Paso3_clasico->SetMargin(0.1);
	Paso3_clasico->AddText("Step #3");
	Paso3_clasico->Draw();
	
	//Expresion
     	l1 = new TLatex();
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.12, 0.72, "X = a^{#frac{r}{2}} (mod N)");
	
	//Reemplazo
	l2 = new TLatex();
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.1, 0.44, "X = 14^{#frac{2}{2}} (mod15)");
	
	//Respuesta
	l3 = new TLatex();
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.07, 0.13, "X = 14^{1} (mod15) = 14");
	
	
	//Flecha 1
	flecha1 = new TArrow(0.31, 0.70, 0.5, 0.70, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
     	
     	TPaveText *Paso3_clasico_TexFlecha1 = new TPaveText(0.55, 0.62, 0.94, 0.75, "NDC"); 
	Paso3_clasico_TexFlecha1->SetTextFont(42);
	Paso3_clasico_TexFlecha1->SetFillColor(kOrange-9); 
	Paso3_clasico_TexFlecha1->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha1->SetMargin(0.1);
	Paso3_clasico_TexFlecha1->AddText("Replace the value of #font[62]{r} in this expression.");
	Paso3_clasico_TexFlecha1->Draw();
     	
     	
     	//Flecha 2
	flecha2 = new TArrow(0.31, 0.42, 0.5, 0.42, 0.01, ">");
	flecha2->SetLineColor(kRed);
     	flecha2->SetLineWidth(1);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
     	
     	TPaveText *Paso3_clasico_TexFlecha2 = new TPaveText(0.53, 0.30, 0.96, 0.50, "NDC"); 
	Paso3_clasico_TexFlecha2->SetTextFont(42);
	Paso3_clasico_TexFlecha2->SetFillColor(kAzure-9); 
	Paso3_clasico_TexFlecha2->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha2->SetMargin(0.1);
	Paso3_clasico_TexFlecha2->AddText("");
	Paso3_clasico_TexFlecha2->AddText("Since the value is #font[62]{even}, it can be used.");
	Paso3_clasico_TexFlecha2->AddText("If it is odd, this step cannot be performed and");
	Paso3_clasico_TexFlecha2->AddText("select a new value of #font[62]{a}.");
	Paso3_clasico_TexFlecha2->AddText("");
	Paso3_clasico_TexFlecha2->Draw();
     	
     	
     	//Flecha 3
	flecha3 = new TArrow(0.31, 0.12, 0.5, 0.12, 0.01, ">");
	flecha3->SetLineColor(kRed);
     	flecha3->SetLineWidth(1);
     	flecha3->SetLineStyle(1);
     	flecha3->Draw();
     	
     	TPaveText *Paso3_clasico_TexFlecha3 = new TPaveText(0.55, 0.05, 0.94, 0.17, "NDC"); 
	Paso3_clasico_TexFlecha3->SetTextFont(42);
	
	Paso3_clasico_TexFlecha3->SetFillColor(kTeal-9); 
	Paso3_clasico_TexFlecha3->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha3->SetMargin(0.1);
	Paso3_clasico_TexFlecha3->AddText("Final #font[62]{result} after the operation.");
	Paso3_clasico_TexFlecha3->Draw();
	
	//Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
     	ExpPaso3->SetFixedAspectRatio();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	
	Paso3_Clasico1_Exp->SetTextFont(42);
	Paso3_Clasico1_Exp->SetFillColor(0); 
	Paso3_Clasico1_Exp->SetShadowColor(kGray);
	Paso3_Clasico1_Exp->SetTextAlign(12);
	Paso3_Clasico1_Exp->SetMargin(0.01);
	Paso3_Clasico1_Exp->AddText("For #font[62]{step 3}, once the value of #font[62]{r} that satisfies the condition is determined, the following procedure is solved to find the value of #font[62]{X} and obtain");
	Paso3_Clasico1_Exp->AddText("the values of #font[62]{P} and #font[62]{Q}.");
	Paso3_Clasico1_Exp->AddText("This operation is the same as the previous step because it is solved through #font[62]{modular algebra}.");
	Paso3_Clasico1_Exp->AddText("By finding this result of #font[62]{X}, it is possible to obtain the values of #font[62]{P} and #font[62]{Q} in the next step.");
 	Paso3_Clasico1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(0); 
	}
	
//Cuarto click nexto a=14
	if(Breakopt == 4){
	
	//Titulo
	TPaveText *Paso4_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso4_clasico->SetTextFont(62);
	Paso4_clasico->SetFillColor(kCyan-10); 
	Paso4_clasico->SetShadowColor(kGray);
	Paso4_clasico->SetMargin(0.1);
	Paso4_clasico->AddText("Step #4");
	Paso4_clasico->Draw();
     	
     	//Linea para dividir los resultados
     	lineaV1 = new TLine(0.5, 0.8, 0.5, 0.3);
     	lineaV1->SetLineColor(kBlack);
     	lineaV1->Draw(); 
	
	//Cuadro de resultado 1
     	TPaveText *Resultado_1 = new TPaveText(0.1, 0.7, 0.4, 0.8, "NDC"); 
	Resultado_1->SetTextFont(42);
	Resultado_1->SetFillColor(kBlue-10); 
	Resultado_1->SetShadowColor(kGray);
	Resultado_1->SetMargin(0.1);
	Resultado_1->AddText("P");
	Resultado_1->Draw();
	
	//Resultado 1
     	l1 = new TLatex();
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.65, "GCD(X-1, N)");
	
	l2 = new TLatex();
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.01, 0.55, "GCD(13, 15) = 1");
	
	l3 = new TLatex();
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.35, 0.65, "Equation");
	
	l4 = new TLatex();
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.35, 0.55, "Solution");
	
	//Cuadro donde muestro P=3
	TPaveText *Resultado_p = new TPaveText(0.09, 0.3, 0.4, 0.4, "NDC"); 
	Resultado_p->SetTextFont(42);
	Resultado_p->SetFillColor(kYellow-10); 
	Resultado_p->SetShadowColor(kGray);
	Resultado_p->SetMargin(0.1);
	Resultado_p->AddText("First result #color[2]{P} = 1");
	Resultado_p->Draw();
	
	//Flechas
	flecha1 = new TArrow(0.2, 0.65, 0.3, 0.65, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	flecha2 = new TArrow(0.2, 0.55, 0.3, 0.55, 0.01, ">");
	flecha2->SetLineColor(kRed);
     	flecha2->SetLineWidth(1);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
     	
	//Cuadro de resultado 2
     	TPaveText *Resultado_2 = new TPaveText(0.6, 0.7, 0.9, 0.8, "NDC"); 
	Resultado_2->SetTextFont(42);
	Resultado_2->SetFillColor(kBlue-10); 
	Resultado_2->SetShadowColor(kGray);
	Resultado_2->SetMargin(0.1);
	Resultado_2->AddText("Q");
	Resultado_2->Draw();
	
	//Cuadro donde muestro Q=5
	TPaveText *Resultado_q = new TPaveText(0.6, 0.3, 0.9, 0.4, "NDC"); 
	Resultado_q->SetTextFont(42);
	Resultado_q->SetFillColor(kYellow-10); 
	Resultado_q->SetShadowColor(kGray);
	Resultado_q->SetMargin(0.1);
	Resultado_q->AddText("Second result #color[8]{Q} = 15");
	Resultado_q->Draw();     	
     	
	//Resultado 2
     	l5 = new TLatex();
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.55, 0.65, "GCD(X+1, N)");
	
	
	l6 = new TLatex();
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.52, 0.55, "GCD(15, 15) = 15");
	
	//Flechas
	flecha5 = new TArrow(0.72, 0.65, 0.82, 0.65, 0.01, ">");
	flecha5->SetLineColor(kRed);
     	flecha5->SetLineWidth(1);
     	flecha5->SetLineStyle(1);
     	flecha5->Draw();
	
	flecha6 = new TArrow(0.72, 0.55, 0.82, 0.55, 0.01, ">");
	flecha6->SetLineColor(kRed);
     	flecha6->SetLineWidth(1);
     	flecha6->SetLineStyle(1);
     	flecha6->Draw();
	
	//Flechas
	l13 = new TLatex();
	l13->SetTextFont(42); 
	l13->SetTextColor(1); 
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.85, 0.65, "Equation");
	
	l14 = new TLatex();
	l14->SetTextFont(42); 
	l14->SetTextColor(1); 
	l14->SetTextAlign(12); 
	l14->DrawLatex(0.85, 0.55, "Solution");
	
	//Cuadro explicando el resultado trivial
	TPaveText *Paso4_clasico_Resul_Trivi = new TPaveText(0.01, 0.25, 0.99, 0.01, "NDC"); 
	Paso4_clasico_Resul_Trivi->SetTextFont(42);
	Paso4_clasico_Resul_Trivi->SetFillColor(kMagenta-10); 
	Paso4_clasico_Resul_Trivi->SetShadowColor(kGray);
	Paso4_clasico_Resul_Trivi->SetMargin(0.1);
	Paso4_clasico_Resul_Trivi->AddText("This result from the #font[62]{Shor's algorithm} is known as the #font[62]{#color[2]{Trivial Result}}. It occurs quite often because");
	Paso4_clasico_Resul_Trivi->AddText("there are #font[62]{coprime numbers with N} that meet all the conditions but result in this type of solutions.");
	Paso4_clasico_Resul_Trivi->AddText("These solutions #font[62]{depend on the selected value of a}, which is why different values need to be tested");
	Paso4_clasico_Resul_Trivi->AddText("when working with the #font[62]{Shor's algorithm}.");
	Paso4_clasico_Resul_Trivi->Draw();
	
	//Segundo canvas    	
     	TCanvas *ExpPaso4 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
     	ExpPaso4->SetFixedAspectRatio();
	ExpPaso4->SetFillColor(0);
	ExpPaso4->SetEditable(1);
	ExpPaso4->Clear();
	ExpPaso4->Update();
	
	TPaveText *Paso4_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Paso4_Clasico1_Exp->SetTextFont(42);
	Paso4_Clasico1_Exp->SetFillColor(0);
	Paso4_Clasico1_Exp->SetShadowColor(kGray);
	Paso4_Clasico1_Exp->SetTextAlign(12);
	Paso4_Clasico1_Exp->SetMargin(0.01);
	Paso4_Clasico1_Exp->AddText("For #font[62]{step 4}, calculate the greatest common divisor of the highlighted equations, and the expected result gives the values of #font[62]{P} and #font[62]{Q}");
	Paso4_Clasico1_Exp->AddText("concluding the #font[62]{Shor's algorithm in its classical form}.");
	Paso4_Clasico1_Exp->AddText("Select the top tabs to view the #font[62]{circuit} or the #font[62]{quantum steps}.");
	Paso4_Clasico1_Exp->AddText("To return, press the #font[62]{CLEAR} button and select a #font[62]{new value to factor}.");
 	Paso4_Clasico1_Exp->Draw();     	
     	
     	ExpPaso4->Update();
	ExpPaso4->SetEditable(0); 
	}
	if(Breakopt == 5){
     	fTextButtonBACK->SetState(kButtonUp, kTRUE);
     	fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
     	DoClassical();
     	CambioTab(0);
     	}
	break;   
  }
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(Valueopt1 == 21){
  switch (Valueopt2){
      case 2:{
      if(Breakopt == 1){
  
  	//Titulo   
   	TPaveText *Paso1_clasico2 = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso1_clasico2->SetTextFont(62);
	Paso1_clasico2->SetFillColor(kBlue-10); 
	Paso1_clasico2->SetShadowColor(kGray);
	Paso1_clasico2->SetMargin(0.1);
	Paso1_clasico2->AddText("Step #1");
	Paso1_clasico2->Draw();
	
    	//Lineas donde estaran los textos 
     	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     
     	//Numero a factorizar 
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "Number to be factored:");
	
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.3, 0.79, "#color[4]{21} = #color[2]{P}*#color[8]{Q}");
     
    	//Valor de a
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.05, 0.70, "Value of a:");
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.3, 0.70, "#color[6]{2}");
     
     	//Algoritmo de euclides
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.15, 0.60, "Verifying #font[62]{#color[8]{Euclid's Algorithm}}:");
      //Lineas del algoritmo de euclides
        lineaV1 = new TLine(0.2, 0.1, 0.2, 0.5);
	lineaV2 = new TLine(0.3, 0.1, 0.3, 0.5);
	
	lineaH1 = new TLine(0.1, 0.2, 0.4, 0.2);
	lineaH2 = new TLine(0.1, 0.4, 0.4, 0.4);
     
     	//dibuja las lineas
        lineaV1->SetLineColor(kBlack);
	lineaV2->SetLineColor(kBlack);
	lineaH1->SetLineColor(kBlack);
	lineaH1->SetLineColor(kBlack);
	
	lineaV1->Draw();
	lineaV2->Draw();
	lineaH1->Draw();
	lineaH2->Draw();
	
     	//primer numero del algoritmo de euclides
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.31, "#color[4]{21}");
      //segundo numero del algoritmo de euclides
	l7->SetTextFont(42); 
	l7->SetTextColor(2); 
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.25, 0.31, "#color[6]{2}");
      //tercer numero del algoritmo de euclides 
	l8->SetTextFont(42); 
	l8->SetTextColor(1); 
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.24, 0.48, "10");

        //cuarto numero del algoritmo de euclides
	l9->SetTextFont(42); 
	l9->SetTextColor(1); 
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.25, 0.15, "1");	
	
	//quinto numero del algoritmo de euclides
	l10->SetTextFont(42); 
	l10->SetTextColor(1); 
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.34, 0.31, "1");	
     
        //Texto junto al algoritmo de euclides
	TPaveText *EuclidesAlgor = new TPaveText(0.65, 0.1, 0.95, 0.7, "NDC"); 
	EuclidesAlgor->SetTextFont(42);
	EuclidesAlgor->SetFillColor(kGreen-10); 
	EuclidesAlgor->SetShadowColor(kGray);
	EuclidesAlgor->SetMargin(0.1);
	EuclidesAlgor->AddText("#font[62]{#scale[1.4]{Euclid's algorithm}}");
	EuclidesAlgor->AddText("the #font[62]{Euclid's algorithm} allows determining");
	EuclidesAlgor->AddText("if the selection of the value of #font[62]{a} is");
	EuclidesAlgor->AddText("a number coprime with #font[62]{N}");
	EuclidesAlgor->AddText("which is an important condition for");
	EuclidesAlgor->AddText("moving forward with the next steps.");
	EuclidesAlgor->Draw();
	
	flecha1 = new TArrow(0.43, 0.3, 0.63, 0.3, 0.01, "<>");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
     
        //Segundo Canvas
	TCanvas *ExpPaso1_21 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1_21->SetFixedAspectRatio();
	ExpPaso1_21->SetFillColor(0);
	ExpPaso1_21->SetEditable(1);
	ExpPaso1_21->Clear();
	ExpPaso1_21->Update();
	
	TPaveText *Paso1_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Paso1_Clasico1_Exp->SetTextFont(42);
	Paso1_Clasico1_Exp->SetFillColor(0); 
	Paso1_Clasico1_Exp->SetShadowColor(kGray);
	Paso1_Clasico1_Exp->SetTextAlign(12);
	Paso1_Clasico1_Exp->SetMargin(0.01);
	Paso1_Clasico1_Exp->AddText("For #font[62]{step 1}, it is necessary to identify that the values to be found are #font[62]{P} and #font[62]{Q}");
	Paso1_Clasico1_Exp->AddText("Then, Euclid's algorithm is implemented to verify if #font[62]{a} and #font[62]{N} are coprime. The steps to solve it can be found by pressing");
	Paso1_Clasico1_Exp->AddText("the #font[62]{CLEAR} button and then #font[62]{CONCEPTS}.");
	Paso1_Clasico1_Exp->AddText("If the final result is 1, then the chosen number is coprime with the number you want to factor.");
 	Paso1_Clasico1_Exp->Draw();     	
     	
     	ExpPaso1_21->Update();
	ExpPaso1_21->SetEditable(0); 	  
     }
     
//segundo click next   
      	if(Breakopt == 2){
     	//Titulo
      	TPaveText *Paso2_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso2_clasico->SetTextFont(62);
	Paso2_clasico->SetFillColor(kGreen-10); 
	Paso2_clasico->SetShadowColor(kGray);
	Paso2_clasico->SetMargin(0.1);
	Paso2_clasico->AddText("Step #2");
	Paso2_clasico->Draw();
	
	TPad *Tabla_1caso_21 = new TPad("pad2","This is pad2",0.01 ,0.01, 0.5, 0.80); 
	Tabla_1caso_21->SetFillColor(0);
	Tabla_1caso_21->Draw();

	TPad *Grafico_1caso_21 = new TPad("pad3","This is pad3",0.5, 0.01, 0.99, 0.80);
	Grafico_1caso_21->SetFillColor(0);
	Grafico_1caso_21->Draw();
      
      	//primer Tpad de la tabla
        Tabla_1caso_21->cd();
        l1 = new TLatex();
	
	l1->SetTextColor(4); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.3, 0.98, "#font[62]{Data Table}");
      
      	//Tabla 
      	TPaveText *table = new TPaveText(0.5, 0.1, 0.90, 0.90, "NDC");
      	table->SetTextFont(42);
    	table->SetBorderSize(2);
	table->SetFillColor(kYellow-10); 
	table->SetShadowColor(kGray);
    	table->SetTextAlign(22); 
    
    	//Agregar filas a la tabla
    	table->AddLine(0.5, 0.99, 0.5 , 0.001);
    	table->AddText("  #font[62]{#scale[1.7]{r}}        #font[62]{#scale[1.7]{F_{a,N}}}");
    	table->AddLine(0, 0.90, 1, 0.90);
    	table->AddText("1                               2");
    	table->AddText("2                               4");
    	table->AddText("3                               8");
    	table->AddText("4                              16");
    	table->AddText("5                              11");
    	table->AddText("#font[62]{#color[2]{6}}          #font[62]{#color[2]{1}}");
    	table->AddText("7                               2");
    	table->AddText("8                               4");
    	table->AddText("9                               8");
    
    	// Dibujar la tabla en el canvas
    	table->Draw();
    	
    	//Flecha
    	flecha1 = new TArrow(0.3, 0.38, 0.48, 0.38, 0.01, "<>");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
     	
    	//Texto al lado de la flecha
    	l2 = new TLatex(); 
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.08, 0.38, "Value of #font[62]{r}"); 	
      
      	//Segundo TPad donde se encuentra el grafico
    	Grafico_1caso_21->cd(); 
    	//Crear el gráfico
    	const int nPoints = 30;
    	double x[nPoints];
    	double y[nPoints];

    	//Definir a y N
    	const double a = 2; 
    	const int N = 21;    

    	//Llenar los arreglos con valores
    	for (int r = 1; r <= nPoints; r++) {
        x[r - 1] = r;  

        //Calcular y = (a^r) mod N
        int result = static_cast<int>(pow(a, r)) % N; 
      //Asegurarse de que el resultado es positivo
        y[r - 1] = (result + N) % N; 
    	}

    	//Crear un gráfico de puntos
    	TGraph *graph = new TGraph(nPoints, x, y);

    	//Establecer propiedades del gráfico
    	graph->SetTitle("#font[62]{F_{a,N}= 2^{r} (mod 21)};X;Y"); 
    	graph->SetMarkerStyle(20);              
    	graph->SetMarkerColor(kRed);           
    	graph->SetLineColor(kBlue);              
    	graph->SetLineWidth(2);                 

    	//Dibujar el gráfico
	graph->Draw();
      
//Segundo Canvas
	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFixedAspectRatio();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	
	TPaveText *Paso2_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Paso2_Clasico1_Exp->SetTextFont(42);
	Paso2_Clasico1_Exp->SetFillColor(0); 
	Paso2_Clasico1_Exp->SetShadowColor(kGray);
	Paso2_Clasico1_Exp->SetTextAlign(12);
	Paso2_Clasico1_Exp->SetMargin(0.01);
	Paso2_Clasico1_Exp->AddText("For #font[62]{step 2}, it is necessary to create a #font[62]{data table of the modular function} to obtain the periodicity graph shown on the right");
	Paso2_Clasico1_Exp->AddText("and determine the correct value of #font[62]{r} chosen for subsequent steps. The value of #font[62]{r} will be the first one that makes #font[62]{F_{a,N} = 1}");
	Paso2_Clasico1_Exp->AddText("The data table shows the #font[62]{periodicity of the function}, as values of #font[62]{F_{a,N}} repeat after selecting #font[62]{r}.");
	Paso2_Clasico1_Exp->AddText("Thus, it is verified that the value of #font[62]{r} is even to proceed with the next step, and if it is odd, another value of #font[62]{a} is selected.");
 	Paso2_Clasico1_Exp->Draw();     	
     	
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(0);       
      }
      
//Tercer Click Next
      if(Breakopt == 3){
      	//Titulo
      	TPaveText *Paso3_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso3_clasico->SetTextFont(62);
	Paso3_clasico->SetFillColor(kMagenta-10); 
	Paso3_clasico->SetShadowColor(kGray);
	Paso3_clasico->SetMargin(0.1);
	Paso3_clasico->AddText("Step #3");
	Paso3_clasico->Draw();
     	
     	//Expresion
     	l1 = new TLatex();
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.12, 0.72, "X = a^{#frac{r}{2}} (mod N)");
      
      	//Reemplazo
	l2 = new TLatex();
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.1, 0.44, "X = 2^{#frac{6}{2}} (mod 21)");
      
      	//Respuesta
	l3 = new TLatex();
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.07, 0.13, "X = 2^{3} (mod 21) = 8");
	
      	//Flecha 1
	flecha1 = new TArrow(0.31, 0.70, 0.5, 0.70, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
      
      	//Flecha 2
	flecha2 = new TArrow(0.31, 0.42, 0.5, 0.42, 0.01, ">");
	flecha2->SetLineColor(kRed);
     	flecha2->SetLineWidth(1);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
     
      	//Flecha 3
	flecha3 = new TArrow(0.31, 0.12, 0.5, 0.12, 0.01, ">");
	flecha3->SetLineColor(kRed);
     	flecha3->SetLineWidth(1);
     	flecha3->SetLineStyle(1);
     	flecha3->Draw();	
     	
     	//Cuadro 1	
     	TPaveText *Paso3_clasico_TexFlecha1 = new TPaveText(0.55, 0.62, 0.94, 0.75, "NDC"); 
	Paso3_clasico_TexFlecha1->SetTextFont(42);
	Paso3_clasico_TexFlecha1->SetFillColor(kOrange-9); 
	Paso3_clasico_TexFlecha1->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha1->SetMargin(0.1);
	Paso3_clasico_TexFlecha1->AddText("Replace the value of #font[62]{r} in this expression.");
	Paso3_clasico_TexFlecha1->Draw();	
      
     	//Cuadro 2
     	TPaveText *Paso3_clasico_TexFlecha2 = new TPaveText(0.53, 0.30, 0.96, 0.50, "NDC"); 
	Paso3_clasico_TexFlecha2->SetTextFont(42);
	Paso3_clasico_TexFlecha2->SetFillColor(kAzure-9); 
	Paso3_clasico_TexFlecha2->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha2->SetMargin(0.1);
	Paso3_clasico_TexFlecha2->AddText(" ");
	Paso3_clasico_TexFlecha2->AddText("Since the value is #font[62]{even}, it can be used.");
	Paso3_clasico_TexFlecha2->AddText("If it is odd, this step cannot be performed and");
	Paso3_clasico_TexFlecha2->AddText("select a new value of #font[62]{a}.");
	Paso3_clasico_TexFlecha2->AddText(" ");
	Paso3_clasico_TexFlecha2->Draw();
	
      	//Cuadro 3
      	TPaveText *Paso3_clasico_TexFlecha3 = new TPaveText(0.55, 0.05, 0.94, 0.17, "NDC"); 
	Paso3_clasico_TexFlecha3->SetTextFont(42);
	Paso3_clasico_TexFlecha3->SetFillColor(kTeal-9); 
	Paso3_clasico_TexFlecha3->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha3->SetMargin(0.1);
	Paso3_clasico_TexFlecha3->AddText("Final #font[62]{result} after the operation.");
	Paso3_clasico_TexFlecha3->Draw();	
	
      
      	//Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
     	ExpPaso3->SetFixedAspectRatio();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	
	Paso3_Clasico1_Exp->SetTextFont(42);
	Paso3_Clasico1_Exp->SetFillColor(0); 
	Paso3_Clasico1_Exp->SetShadowColor(kGray);
	Paso3_Clasico1_Exp->SetTextAlign(12);
	Paso3_Clasico1_Exp->SetMargin(0.01);
	Paso3_Clasico1_Exp->AddText("For #font[62]{step 3}, once the value of #font[62]{r} that satisfies the condition is determined, the following procedure is solved to find the value of #font[62]{X} and obtain");
	Paso3_Clasico1_Exp->AddText("the values of #font[62]{P} and #font[62]{Q}.");
	Paso3_Clasico1_Exp->AddText("This operation is the same as the previous step because it is solved through #font[62]{modular algebra}.");
	Paso3_Clasico1_Exp->AddText("By finding this result of #font[62]{X}, it is possible to obtain the values of #font[62]{P} and #font[62]{Q} in the next step.");
 	Paso3_Clasico1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(0); 
      }
      
//Cuarto Click Next
      	if(Breakopt == 4){
      
      	//Titulo
      	TPaveText *Paso4_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso4_clasico->SetTextFont(62);
	Paso4_clasico->SetFillColor(kCyan-10); 
	Paso4_clasico->SetShadowColor(kGray);
	Paso4_clasico->SetMargin(0.1);
	Paso4_clasico->AddText("Step #4");
	Paso4_clasico->Draw();
      
      	//Linea para dividir los resultados
     	lineaV1 = new TLine(0.5, 0.8, 0.5, 0.01);
     	lineaV1->SetLineColor(kBlack);
     	lineaV1->Draw(); 
     	
     	//Cuadro de resultado 1
     	TPaveText *Resultado_1 = new TPaveText(0.1, 0.7, 0.4, 0.8, "NDC"); 
	Resultado_1->SetTextFont(42);
	Resultado_1->SetFillColor(kBlue-10); 
	Resultado_1->SetShadowColor(kGray);
	Resultado_1->SetMargin(0.1);
	Resultado_1->AddText("P");
	Resultado_1->Draw();
	
	//Resultado 1
     	l1 = new TLatex();
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.65, "GCD(X-1, N)");

 	l2 = new TLatex();
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.01, 0.55, "GCD(8-1, 21)");
	
	
	l3 = new TLatex();
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.01, 0.45, "GCD(7, 21)");
	
	l4 = new TLatex();
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.01, 0.35, "GCD(7, 21) = 7");
	
	//Textos al lado
	l5 = new TLatex();
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.35, 0.65, "Equation");
	
	l6 = new TLatex();
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.35, 0.55, "Replace");
	
	l7 = new TLatex();
	l7->SetTextFont(42); 
	l7->SetTextColor(1); 
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.35, 0.45, "Solve");
	
	l8 = new TLatex();
	l8->SetTextFont(42); 
	l8->SetTextColor(1); 
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.35, 0.35, "Solution");
	
	//Cuadro donde muestro P=3
	TPaveText *Resultado_p = new TPaveText(0.08, 0.1, 0.4, 0.2, "NDC"); 
	Resultado_p->SetTextFont(42);
	Resultado_p->SetFillColor(kYellow-10); 
	Resultado_p->SetShadowColor(kGray);
	Resultado_p->SetMargin(0.1);
	Resultado_p->AddText("First result #color[2]{P} = 7");
	Resultado_p->Draw();
	
	//Flechas
	flecha1 = new TArrow(0.2, 0.65, 0.3, 0.65, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	flecha2 = new TArrow(0.2, 0.55, 0.3, 0.55, 0.01, ">");
	flecha2->SetLineColor(kRed);
     	flecha2->SetLineWidth(1);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
	
	flecha3 = new TArrow(0.2, 0.45, 0.3, 0.45, 0.01, ">");
	flecha3->SetLineColor(kRed);
     	flecha3->SetLineWidth(1);
     	flecha3->SetLineStyle(1);
     	flecha3->Draw();
	
	flecha4 = new TArrow(0.2, 0.35, 0.3, 0.35, 0.01, ">");
	flecha4->SetLineColor(kRed);
     	flecha4->SetLineWidth(1);
     	flecha4->SetLineStyle(1);
     	flecha4->Draw();
     	
     	//Cuadro de resultado 2
     	TPaveText *Resultado_2 = new TPaveText(0.6, 0.7, 0.9, 0.8, "NDC"); 
	Resultado_2->SetTextFont(42);
	Resultado_2->SetFillColor(kBlue-10); 
	Resultado_2->SetShadowColor(kGray);
	Resultado_2->SetMargin(0.1);
	Resultado_2->AddText("Q");
	Resultado_2->Draw();
	
	//Cuadro donde muestro Q=3
	TPaveText *Resultado_q = new TPaveText(0.6, 0.1, 0.9, 0.2, "NDC"); 
	Resultado_q->SetTextFont(42);
	Resultado_q->SetFillColor(kYellow-10); 
	Resultado_q->SetShadowColor(kGray);
	Resultado_q->SetMargin(0.1);
	Resultado_q->AddText("Second result #color[8]{Q} = 3");
	Resultado_q->Draw();
	
	
	//Resultado 2
     	l9 = new TLatex(); 
	l9->SetTextFont(42); 
	l9->SetTextColor(1); 
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.55, 0.65, "GCD(X+1, N)");

	l10 = new TLatex(); 
	l10->SetTextFont(42); 
	l10->SetTextColor(1); 
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.55, 0.55, "GCD(8+1, 21)");
	
	l11 = new TLatex(); 
	l11->SetTextFont(42); 
	l11->SetTextColor(1); 
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.55, 0.45, "GCD(9, 21)");
	
	l12 = new TLatex(); 
	l12->SetTextFont(42); 
	l12->SetTextColor(1); 
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.55, 0.35, "GCD(9, 21) = 3");
	
	l13 = new TLatex();
	l13->SetTextFont(42); 
	l13->SetTextColor(1); 
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.85, 0.65, "Equation");
	
	l14 = new TLatex();
	l14->SetTextFont(42); 
	l14->SetTextColor(1); 
	l14->SetTextAlign(12); 
	l14->DrawLatex(0.85, 0.55, "Replace");
	
	l15 = new TLatex(); 
	l15->SetTextFont(42); 
	l15->SetTextColor(1); 
	l15->SetTextAlign(12); 
	l15->DrawLatex(0.85, 0.45, "Solve");
	
	l16 = new TLatex();
	l16->SetTextFont(42); 
	l16->SetTextColor(1); 
	l16->SetTextAlign(12); 
	l16->DrawLatex(0.85, 0.35, "Solution");
	
	//Flechas
	flecha5 = new TArrow(0.72, 0.65, 0.82, 0.65, 0.01, ">");
	flecha5->SetLineColor(kRed);
     	flecha5->SetLineWidth(1);
     	flecha5->SetLineStyle(1);
     	flecha5->Draw();
	
	flecha6 = new TArrow(0.72, 0.55, 0.82, 0.55, 0.01, ">");
	flecha6->SetLineColor(kRed);
     	flecha6->SetLineWidth(1);
     	flecha6->SetLineStyle(1);
     	flecha6->Draw();
	
	flecha7 = new TArrow(0.72, 0.45, 0.82, 0.45, 0.01, ">");
	flecha7->SetLineColor(kRed);
     	flecha7->SetLineWidth(1);
     	flecha7->SetLineStyle(1);
     	flecha7->Draw();
	
	flecha8 = new TArrow(0.72, 0.35, 0.82, 0.35, 0.01, ">");
	flecha8->SetLineColor(kRed);
     	flecha8->SetLineWidth(1);
     	flecha8->SetLineStyle(1);
     	flecha8->Draw();
	
	//Segundo canvas    	
     	TCanvas *ExpPaso4 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
     	ExpPaso4->SetFixedAspectRatio();
	ExpPaso4->SetFillColor(0);
	ExpPaso4->SetEditable(1);
	ExpPaso4->Clear();
	ExpPaso4->Update();
	
	TPaveText *Paso4_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Paso4_Clasico1_Exp->SetTextFont(42);
	Paso4_Clasico1_Exp->SetFillColor(0);
	Paso4_Clasico1_Exp->SetShadowColor(kGray);
	Paso4_Clasico1_Exp->SetTextAlign(12);
	Paso4_Clasico1_Exp->SetMargin(0.01);
	Paso4_Clasico1_Exp->AddText("For #font[62]{step 4}, calculate the greatest common divisor of the highlighted equations, and the expected result gives the values of #font[62]{P} and #font[62]{Q}");
	Paso4_Clasico1_Exp->AddText("concluding the #font[62]{Shor's algorithm in its classical form}.");
	Paso4_Clasico1_Exp->AddText("Select the top tabs to view the #font[62]{circuit} or the #font[62]{quantum steps}.");
	Paso4_Clasico1_Exp->AddText("To return, press the #font[62]{CLEAR} button and select a #font[62]{new value to factor}.");
 	Paso4_Clasico1_Exp->Draw();     	
     	
     	ExpPaso4->Update();
	ExpPaso4->SetEditable(0); 
      }
      if(Breakopt == 5){
     	fTextButtonBACK->SetState(kButtonUp, kTRUE);
     	fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
     	DoClassical();
     	CambioTab(0);
     	}
      break;
     } 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
      case 4:{
       	if(Breakopt == 1){
     	//Titulo
       	TPaveText *Paso1_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso1_clasico->SetTextFont(62);
	Paso1_clasico->SetFillColor(kBlue-10); 
	Paso1_clasico->SetShadowColor(kGray);
	Paso1_clasico->SetMargin(0.1);
	Paso1_clasico->AddText("Step #1");
	Paso1_clasico->Draw();
     	
     	//Lineas
     	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
      
       //Textos
     	
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "Number to be factored:");
	
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.3, 0.79, "#color[4]{21} = #color[2]{P}*#color[8]{Q}");
	
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.05, 0.70, "Value of a:  ");
     	 
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.3, 0.70, "#color[6]{4}");
      
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.15, 0.60, "Verifying #font[62]{#color[8]{Euclid's Algorithm}}:"); 
      
      	//Lineas del algoritmo de euclides
        lineaV1 = new TLine(0.2, 0.1, 0.2, 0.5);
	lineaV2 = new TLine(0.3, 0.1, 0.3, 0.5);
	
	lineaH1 = new TLine(0.1, 0.2, 0.4, 0.2);
	lineaH2 = new TLine(0.1, 0.4, 0.4, 0.4); 
      
     	//primer numero del algoritmo de euclides
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.13, 0.33, "#color[4]{21}");
      
      	//segundo numero del algoritmo de euclides
	l7->SetTextFont(42); 
	l7->SetTextColor(1); 
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.24, 0.33, "#color[6]{4}");
      
       	//tercer numero del algoritmo de euclides 
	l8->SetTextFont(42); 
	l8->SetTextColor(1); 
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.24, 0.50, "5");
      
      	//cuarto numero del algoritmo de euclides
	l9->SetTextFont(42); 
	l9->SetTextColor(1); 
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.24, 0.17, "1");
	
	//quinto numero del algoritmo de euclides
	l10->SetTextFont(42); 
	l10->SetTextColor(1); 
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.34, 0.33, "1");
      
      	lineaV1->SetLineColor(kBlack);
	lineaV2->SetLineColor(kBlack);
	lineaH1->SetLineColor(kBlack);
	lineaH1->SetLineColor(kBlack);
	
	lineaV1->Draw();
	lineaV2->Draw();
	lineaH1->Draw();
	lineaH2->Draw();
	
	//Texto junto al algoritmo de euclides
	TPaveText *EuclidesAlgor = new TPaveText(0.65, 0.1, 0.95, 0.7, "NDC"); 
	EuclidesAlgor->SetTextFont(42);
	EuclidesAlgor->SetFillColor(kGreen-10); 
	EuclidesAlgor->SetShadowColor(kGray);
	EuclidesAlgor->SetMargin(0.1);
	EuclidesAlgor->AddText("#font[62]{#scale[1.4]{Euclid's algorithm}}");
	EuclidesAlgor->AddText("the #font[62]{Euclid's algorithm} allows determining");
	EuclidesAlgor->AddText("if the selection of the value of #font[62]{a} is");
	EuclidesAlgor->AddText("a number coprime with #font[62]{N}");
	EuclidesAlgor->AddText("which is an important condition for");
	EuclidesAlgor->AddText("moving forward with the next steps.");
	EuclidesAlgor->Draw();
	
	flecha1 = new TArrow(0.43, 0.3, 0.63, 0.3, 0.01, "<>");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
      	//Segundo Canvas
	TCanvas *ExpPaso1 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1->SetFixedAspectRatio();
	ExpPaso1->SetFillColor(0);
	ExpPaso1->SetEditable(1);
	ExpPaso1->Clear();
	ExpPaso1->Update();
	TPaveText *Paso1_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Paso1_Clasico1_Exp->SetTextFont(42);
	Paso1_Clasico1_Exp->SetFillColor(0); 
	Paso1_Clasico1_Exp->SetShadowColor(kGray);
	Paso1_Clasico1_Exp->SetTextAlign(12);
	Paso1_Clasico1_Exp->SetMargin(0.01);
	Paso1_Clasico1_Exp->AddText("For #font[62]{step 1}, it is necessary to identify that the values to be found are #font[62]{P} and #font[62]{Q}");
	Paso1_Clasico1_Exp->AddText("Then, Euclid's algorithm is implemented to verify if #font[62]{a} and #font[62]{N} are coprime. The steps to solve it can be found by pressing");
	Paso1_Clasico1_Exp->AddText("the #font[62]{CLEAR} button and then #font[62]{CONCEPTS}.");
	Paso1_Clasico1_Exp->AddText("If the final result is 1, then the chosen number is coprime with the number you want to factor.");
 	Paso1_Clasico1_Exp->Draw();     	
     	
     	ExpPaso1->Update();
	ExpPaso1->SetEditable(0);  
      }

//Segundo click a=4
      	if(Breakopt == 2){
      	//Titulo
     	TPaveText *Paso2_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso2_clasico->SetTextFont(62);
	Paso2_clasico->SetFillColor(kGreen-10); 
	Paso2_clasico->SetShadowColor(kGray);
	Paso2_clasico->SetMargin(0.1);
	Paso2_clasico->AddText("Step #2");
	Paso2_clasico->Draw();
	
	TPad *Tabla_2caso_4 = new TPad("pad2","This is pad2",0.01 ,0.01, 0.5, 0.80); 
	Tabla_2caso_4->SetFillColor(0);
	Tabla_2caso_4->Draw();

	TPad *Grafico_2caso_4 = new TPad("pad3","This is pad3",0.5, 0.01, 0.99, 0.80);
	Grafico_2caso_4->SetFillColor(0);
	Grafico_2caso_4->Draw();
	
	//primer Tpad de la tabla
        Tabla_2caso_4->cd();
        l1 = new TLatex();
	
	
	l1->SetTextColor(4); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.3, 0.98, "#font[62]{Data Table}");
	
	//Tabla
     	TPaveText *table = new TPaveText(0.5, 0.1, 0.90, 0.90, "NDC");
     	table->SetTextFont(42);
    	table->SetBorderSize(2);
	table->SetFillColor(kYellow-10); 
	table->SetShadowColor(kGray);
    	table->SetTextAlign(22); 
    	
    	//Agregar filas a la tabla
    	table->AddLine(0.5, 0.99, 0.5 , 0.001);
    	table->AddText("  #font[62]{#scale[1.7]{r}}         #font[62]{#scale[1.7]{F_{a,N}}}");
    	table->AddLine(0, 0.90, 1, 0.90);
    	table->AddText("1                               4");
    	table->AddText("2                               16");
    	table->AddText("#font[62]{#color[2]{3}}         #font[62]{#color[2]{1}}");
    	table->AddText("4                               4");
    	table->AddText("5                               16");
    	table->AddText("6                               1");
    	table->AddText("7                               4");
    	table->AddText("8                               16");
    	table->AddText("9                               1");
    
    	//Dibujar la tabla en el canvas
    	table->Draw();
    	
	//Flecha
    	flecha1 = new TArrow(0.3, 0.63, 0.48, 0.63, 0.01, "<>");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	//Texto al lado de la flecha
    	l2 = new TLatex();
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.08, 0.63, "Value of #font[62]{r}"); 
	
	//Segundo TPad donde se encuentra el grafico
    	Grafico_2caso_4->cd(); 
    	//Crear el gráfico
    	const int nPoints = 13;
    	double x[nPoints];
    	double y[nPoints];

    	//Definir a y N
    	const double a = 4; 
    	const int N = 21;    

    	//Llenar los arreglos con valores
    	for (int r = 1; r <= nPoints; r++) {
        x[r - 1] = r;  

        //Calcular y = (a^r) mod N
        int result = static_cast<int>(pow(a, r)) % N; 
      //Asegurarse de que el resultado es positivo
        y[r - 1] = (result + N) % N; 
    	}

    	//Crear un gráfico de puntos
    	TGraph *graph = new TGraph(nPoints, x, y);

    	//Establecer propiedades del gráfico
    	graph->SetTitle("#font[62]{F_{a,N}= 4^{r} (mod 21)};X;Y"); 
    	graph->SetMarkerStyle(20);              
    	graph->SetMarkerColor(kRed);           
    	graph->SetLineColor(kBlue);              
    	graph->SetLineWidth(2);                 

    	//Dibujar el gráfico
    	graph->Draw();
	
	//Segundo Canvas
	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFixedAspectRatio();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	
	TPaveText *Paso2_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Paso2_Clasico1_Exp->SetTextFont(42);
	Paso2_Clasico1_Exp->SetFillColor(0); 
	Paso2_Clasico1_Exp->SetShadowColor(kGray);
	Paso2_Clasico1_Exp->SetTextAlign(12);
	Paso2_Clasico1_Exp->SetMargin(0.01);
	Paso2_Clasico1_Exp->AddText("For #font[62]{step 2}, it is necessary to create a #font[62]{data table of the modular function} to obtain the periodicity graph shown on the right");
	Paso2_Clasico1_Exp->AddText("and determine the correct value of #font[62]{r} chosen for subsequent steps. The value of #font[62]{r} will be the first one that makes #font[62]{F_{a,N} = 1}");
	Paso2_Clasico1_Exp->AddText("The data table shows the #font[62]{periodicity of the function}, as values of #font[62]{F_{a,N}} repeat after selecting #font[62]{r}.");
	Paso2_Clasico1_Exp->AddText("Thus, it is verified that the value of #font[62]{r} is even to proceed with the next step, and if it is odd, another value of #font[62]{a} is selected.");
 	Paso2_Clasico1_Exp->Draw();     	
     	
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(0); 
      }

//tercer click next a=4 
      	if(Breakopt == 3){
      
      	//Titulo
      	TPaveText *Paso3_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso3_clasico->SetTextFont(62);
	Paso3_clasico->SetFillColor(kMagenta-10); 
	Paso3_clasico->SetShadowColor(kGray);
	Paso3_clasico->SetMargin(0.1);
	Paso3_clasico->AddText("Step #3");
	Paso3_clasico->Draw();
      
      	//Expresion
     	l1 = new TLatex();
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.12, 0.72, "X = a^{#frac{r}{2}} (mod N)");
	
	//Reemplazo
	l2 = new TLatex();
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.1, 0.44, "X = 4^{#frac{3}{2}} (mod 21)");
	
	//Respuesta
	l3 = new TLatex();
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.07, 0.13, "X = 4^{#frac{3}{2}} (mod 21) = ? ");
	
      	//Flecha 1
	flecha1 = new TArrow(0.31, 0.70, 0.5, 0.70, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
     	
     	TPaveText *Paso3_clasico_TexFlecha1 = new TPaveText(0.55, 0.62, 0.94, 0.75, "NDC"); 
	Paso3_clasico_TexFlecha1->SetTextFont(42);
	Paso3_clasico_TexFlecha1->SetFillColor(kOrange-9); 
	Paso3_clasico_TexFlecha1->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha1->SetMargin(0.1);
	Paso3_clasico_TexFlecha1->AddText("Replace the value of #font[62]{r} in this expression.");
	Paso3_clasico_TexFlecha1->Draw();
      
      	//Flecha 2
	flecha2 = new TArrow(0.31, 0.42, 0.45, 0.42, 0.01, ">");
	flecha2->SetLineColor(kRed);
     	flecha2->SetLineWidth(1);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
     	
     	TPaveText *Paso3_clasico_TexFlecha2 = new TPaveText(0.51, 0.30, 0.98, 0.50, "NDC"); 
	Paso3_clasico_TexFlecha2->SetTextFont(42);
	Paso3_clasico_TexFlecha2->SetFillColor(kAzure-9); 
	Paso3_clasico_TexFlecha2->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha2->SetMargin(0.1);
	Paso3_clasico_TexFlecha2->AddText("The found value of #font[62]{r} is #font[62]{odd}, therefore");
	Paso3_clasico_TexFlecha2->AddText("when performing the operation, no result will be found.");
	Paso3_clasico_TexFlecha2->AddText("It is necessary to #font[62]{choose another value of a} to proceed.");
	Paso3_clasico_TexFlecha2->AddText("with the #font[62]{Shor's algorithm}.");
	Paso3_clasico_TexFlecha2->Draw();
      
      	//Flecha 3
	flecha3 = new TArrow(0.31, 0.12, 0.5, 0.12, 0.01, ">");
	flecha3->SetLineColor(kRed);
     	flecha3->SetLineWidth(1);
     	flecha3->SetLineStyle(1);
     	flecha3->Draw();
     	
     	TPaveText *Paso3_clasico_TexFlecha3 = new TPaveText(0.55, 0.05, 0.94, 0.17, "NDC"); 
	Paso3_clasico_TexFlecha3->SetTextFont(42);
	Paso3_clasico_TexFlecha3->SetFillColor(kTeal-9); 
	Paso3_clasico_TexFlecha3->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha3->SetMargin(0.1);
	Paso3_clasico_TexFlecha3->AddText("Result not found because #font[62]{r is odd}.");
	Paso3_clasico_TexFlecha3->Draw();
      
      	//Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
     	ExpPaso3->SetFixedAspectRatio();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Paso3_Clasico1_Exp->SetTextFont(42);
	Paso3_Clasico1_Exp->SetFillColor(0); 
	Paso3_Clasico1_Exp->SetShadowColor(kGray);
	Paso3_Clasico1_Exp->SetTextAlign(12);
	Paso3_Clasico1_Exp->SetMargin(0.01);
	Paso3_Clasico1_Exp->AddText("For #font[62]{step 3}, once the value of #font[62]{r} that satisfies the condition is determined, the following procedure is solved to find the value of #font[62]{X} and obtain");
	Paso3_Clasico1_Exp->AddText("the values of #font[62]{P} and #font[62]{Q}.");
	Paso3_Clasico1_Exp->AddText("This operation is the same as the previous step because it is solved through #font[62]{modular algebra}.");
	Paso3_Clasico1_Exp->AddText("By finding this result of #font[62]{X}, it is possible to obtain the values of #font[62]{P} and #font[62]{Q} in the next step.");
 	Paso3_Clasico1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(0); 
      
      	fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
      	}
      break;
      }     	
///////////////////////////////////////////////////////////////////      
      case 5:{
     	if(Breakopt == 1){
      	//Titulo
       	TPaveText *Paso1_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso1_clasico->SetTextFont(62);
	Paso1_clasico->SetFillColor(kBlue-10); 
	Paso1_clasico->SetShadowColor(kGray);
	Paso1_clasico->SetMargin(0.1);
	Paso1_clasico->AddText("Step #1");
	Paso1_clasico->Draw();
     	
     	//Lineas
     	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
      
      	//Textos
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "Number to be factored: ");
	
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.3, 0.79, "#color[4]{21} = #color[2]{P}*#color[8]{Q}");
	
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.05, 0.70, "Value of a:  ");
     	 
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.3, 0.70, "#color[6]{5}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.15, 0.60, "Verifying #font[62]{#color[8]{Euclid's Algorithm}}:"); 
      
      	//Lineas del algoritmo de euclides
        lineaV1 = new TLine(0.2, 0.1, 0.2, 0.5);
	lineaV2 = new TLine(0.3, 0.1, 0.3, 0.5);
	
	lineaH1 = new TLine(0.1, 0.2, 0.4, 0.2);
	lineaH2 = new TLine(0.1, 0.4, 0.4, 0.4); 
      
     	//primer numero del algoritmo de euclides
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.32, "#color[4]{21}"); 
      
      	//segundo numero del algoritmo de euclides
	l7->SetTextFont(42); 
	l7->SetTextColor(1); 
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.25, 0.32, "#color[6]{5}");
	
      	//tercer numero del algoritmo de euclides 
	l8->SetTextFont(42); 
	l8->SetTextColor(1); 
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.25, 0.47, "4");
      
      	//cuarto numero del algoritmo de euclides
	l9->SetTextFont(42); 
	l9->SetTextColor(1); 
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.25, 0.14, "1");
	
	//quinto numero del algoritmo de euclides
	l10->SetTextFont(42); 
	l10->SetTextColor(1); 
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.33, 0.32, "1");
	
	lineaV1->SetLineColor(kBlack);
	lineaV2->SetLineColor(kBlack);
	lineaH1->SetLineColor(kBlack);
	lineaH1->SetLineColor(kBlack);
	
	lineaV1->Draw();
	lineaV2->Draw();
	lineaH1->Draw();
	lineaH2->Draw();
	
	//Texto junto al algoritmo de euclides
	TPaveText *EuclidesAlgor = new TPaveText(0.65, 0.1, 0.95, 0.7, "NDC"); 
	EuclidesAlgor->SetTextFont(42);
	EuclidesAlgor->SetFillColor(kGreen-10); 
	EuclidesAlgor->SetShadowColor(kGray);
	EuclidesAlgor->SetMargin(0.1);
	EuclidesAlgor->AddText("#font[62]{#scale[1.4]{Euclid's algorithm}}");
	EuclidesAlgor->AddText("the #font[62]{Euclid's algorithm} allows determining");
	EuclidesAlgor->AddText("if the selection of the value of #font[62]{a} is");
	EuclidesAlgor->AddText("a number coprime with #font[62]{N}");
	EuclidesAlgor->AddText("which is an important condition for");
	EuclidesAlgor->AddText("moving forward with the next steps.");
	EuclidesAlgor->Draw();
	
	flecha1 = new TArrow(0.43, 0.3, 0.63, 0.3, 0.01, "<>");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
      	//Segundo Canvas
	TCanvas *ExpPaso1 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1->SetFixedAspectRatio();
	ExpPaso1->SetFillColor(0);
	ExpPaso1->SetEditable(1);
	ExpPaso1->Clear();
	ExpPaso1->Update();
	
	TPaveText *Paso1_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Paso1_Clasico1_Exp->SetTextFont(42);
	Paso1_Clasico1_Exp->SetFillColor(0); 
	Paso1_Clasico1_Exp->SetShadowColor(kGray);
	Paso1_Clasico1_Exp->SetTextAlign(12);
	Paso1_Clasico1_Exp->SetMargin(0.01);
	Paso1_Clasico1_Exp->AddText("For #font[62]{step 1}, it is necessary to identify that the values to be found are #font[62]{P} and #font[62]{Q}");
	Paso1_Clasico1_Exp->AddText("Then, Euclid's algorithm is implemented to verify if #font[62]{a} and #font[62]{N} are coprime. The steps to solve it can be found by pressing");
	Paso1_Clasico1_Exp->AddText("the #font[62]{CLEAR} button and then #font[62]{CONCEPTS}.");
	Paso1_Clasico1_Exp->AddText("If the final result is 1, then the chosen number is coprime with the number you want to factor.");
 	Paso1_Clasico1_Exp->Draw();     	
     	
     	ExpPaso1->Update();
	ExpPaso1->SetEditable(0);
      }
//Segundo click a=5
      if(Breakopt == 2){     
       	//Titulo
     	TPaveText *Paso2_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso2_clasico->SetTextFont(62);
	Paso2_clasico->SetFillColor(kGreen-10); 
	Paso2_clasico->SetShadowColor(kGray);
	Paso2_clasico->SetMargin(0.1);
	Paso2_clasico->AddText("Step #2");
	Paso2_clasico->Draw();
	
	TPad *Tabla_2caso_5 = new TPad("pad2","This is pad2",0.01 ,0.01, 0.5, 0.80); 
	Tabla_2caso_5->SetFillColor(0);
	Tabla_2caso_5->Draw();

	TPad *Grafico_2caso_5 = new TPad("pad3","This is pad3",0.5, 0.01, 0.99, 0.80);
	Grafico_2caso_5->SetFillColor(0);
	Grafico_2caso_5->Draw();
      
      
	//primer Tpad de la tabla
        Tabla_2caso_5->cd();
        l1 = new TLatex();
	
	l1->SetTextColor(4); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.3, 0.98, "#font[62]{Data Table}");
      
      	//Tabla
     	TPaveText *table = new TPaveText(0.5, 0.1, 0.90, 0.90, "NDC");
    	table->SetBorderSize(2);
    	table->SetTextFont(42); 
	table->SetFillColor(kYellow-10); 
	table->SetShadowColor(kGray);
    	table->SetTextAlign(22); 
    	
    	//Agregar filas a la tabla
    	table->AddLine(0.5, 0.99, 0.5 , 0.001);
    	table->AddText("#font[62]{#scale[1.7]{r}}      #font[62]{#scale[1.7]{F_{a,N}}}");
    	table->AddLine(0, 0.90, 1, 0.90);
    	table->AddText("  1                             5");
    	table->AddText("  2                             4");
    	table->AddText("  3                             20");
    	table->AddText("  4                             16");
    	table->AddText("  5                             17");
    	table->AddText("#font[62]{#color[2]{6}}        #font[62]{#color[2]{1}}");
    	table->AddText("  7                             5");
    	table->AddText("  8                             4");
    	table->AddText("  9                             20");
    
    	//Dibujar la tabla en el canvas
    	table->Draw();
    	
     	//Flecha
    	flecha1 = new TArrow(0.3, 0.38, 0.48, 0.38, 0.01, "<>");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
     	
     	//Texto al lado de la flecha
    	l2 = new TLatex(); 
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.08, 0.38, "Value of #font[62]{r}"); 
     	
     	//Segundo TPad donde se encuentra el grafico
    	Grafico_2caso_5->cd(); 
    	//Crear el gráfico
    	const int nPoints = 13;
    	double x[nPoints];
    	double y[nPoints];

    	//Definir a y N
    	const double a = 5; 
    	const int N = 21;    

    	//Llenar los arreglos con valores
    	for (int r = 1; r <= nPoints; r++) {
        x[r - 1] = r;  

        //Calcular y = (a^r) mod N
        int result = static_cast<int>(pow(a, r)) % N; 
      //Asegurarse de que el resultado es positivo
        y[r - 1] = (result + N) % N; 
    	}

    	//Crear un gráfico de puntos
    	TGraph *graph = new TGraph(nPoints, x, y);

    	//Establecer propiedades del gráfico
    	graph->SetTitle("#font[62]{F_{a,N}= 5^{r} (mod 21)};X;Y"); 
    	graph->SetMarkerStyle(20);              
    	graph->SetMarkerColor(kRed);           
    	graph->SetLineColor(kBlue);              
    	graph->SetLineWidth(2);                 

    	//Dibujar el gráfico
    	graph->Draw();
     	
      	//Segundo Canvas
	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFixedAspectRatio();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	
	TPaveText *Paso2_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Paso2_Clasico1_Exp->SetTextFont(42);
	Paso2_Clasico1_Exp->SetFillColor(0); 
	Paso2_Clasico1_Exp->SetShadowColor(kGray);
	Paso2_Clasico1_Exp->SetTextAlign(12);
	Paso2_Clasico1_Exp->SetMargin(0.01);
	Paso2_Clasico1_Exp->AddText("For #font[62]{step 2}, it is necessary to create a #font[62]{data table of the modular function} to obtain the periodicity graph shown on the right");
	Paso2_Clasico1_Exp->AddText("and determine the correct value of #font[62]{r} chosen for subsequent steps. The value of #font[62]{r} will be the first one that makes #font[62]{F_{a,N} = 1}");
	Paso2_Clasico1_Exp->AddText("The data table shows the #font[62]{periodicity of the function}, as values of #font[62]{F_{a,N}} repeat after selecting #font[62]{r}.");
	Paso2_Clasico1_Exp->AddText("Thus, it is verified that the value of #font[62]{r} is even to proceed with the next step, and if it is odd, another value of #font[62]{a} is selected.");
 	Paso2_Clasico1_Exp->Draw();     	
     	
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(0); 
      }
//tercer click next a=5 
      	if(Breakopt == 3){
      	//Titulo
      	TPaveText *Paso3_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso3_clasico->SetTextFont(62);
	Paso3_clasico->SetFillColor(kMagenta-10); 
	Paso3_clasico->SetShadowColor(kGray);
	Paso3_clasico->SetMargin(0.1);
	Paso3_clasico->AddText("Step #3");
	Paso3_clasico->Draw();
	
	//Expresion
     	l1 = new TLatex();
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.12, 0.72, "X = a^{#frac{r}{2}} (mod N)");
	
	//Reemplazo
	l2 = new TLatex();
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.1, 0.44, "X = 5^{#frac{6}{2}} (mod 21)");
	
	//Respuesta
	l3 = new TLatex();
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.07, 0.13, "X = 5^{3} (mod 21) = 20");
	
	//Flecha 1
	flecha1 = new TArrow(0.31, 0.70, 0.5, 0.70, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
     	
     	TPaveText *Paso3_clasico_TexFlecha1 = new TPaveText(0.55, 0.62, 0.94, 0.75, "NDC"); 
	Paso3_clasico_TexFlecha1->SetTextFont(42);
	Paso3_clasico_TexFlecha1->SetFillColor(kOrange-9); 
	Paso3_clasico_TexFlecha1->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha1->SetMargin(0.1);
	Paso3_clasico_TexFlecha1->AddText("Replace the value of #font[62]{r} in this expression.");
	Paso3_clasico_TexFlecha1->Draw();
     	
     	//Flecha 2
	flecha2 = new TArrow(0.31, 0.42, 0.5, 0.42, 0.01, ">");
	flecha2->SetLineColor(kRed);
     	flecha2->SetLineWidth(1);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
     	
     	TPaveText *Paso3_clasico_TexFlecha2 = new TPaveText(0.53, 0.30, 0.96, 0.50, "NDC"); 
	Paso3_clasico_TexFlecha2->SetTextFont(42);
	Paso3_clasico_TexFlecha2->SetFillColor(kAzure-9); 
	Paso3_clasico_TexFlecha2->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha2->SetMargin(0.1);
	Paso3_clasico_TexFlecha2->AddText("Since the value is #font[62]{even}, it can be used.");
	Paso3_clasico_TexFlecha2->AddText("If it is odd, this step cannot be performed and");
	Paso3_clasico_TexFlecha2->AddText("select a new value of #font[62]{a}.");
	Paso3_clasico_TexFlecha2->Draw();
     	
     	//Flecha 3
	flecha3 = new TArrow(0.31, 0.12, 0.5, 0.12, 0.01, ">");
	flecha3->SetLineColor(kRed);
     	flecha3->SetLineWidth(1);
     	flecha3->SetLineStyle(1);
     	flecha3->Draw();
     	
     	TPaveText *Paso3_clasico_TexFlecha3 = new TPaveText(0.55, 0.05, 0.94, 0.17, "NDC"); 
	Paso3_clasico_TexFlecha3->SetTextFont(42);
	Paso3_clasico_TexFlecha3->SetFillColor(kTeal-9); 
	Paso3_clasico_TexFlecha3->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha3->SetMargin(0.1);
	Paso3_clasico_TexFlecha3->AddText("Final #font[62]{result} after the operation.");
	Paso3_clasico_TexFlecha3->Draw();
      
      	//Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
     	ExpPaso3->SetFixedAspectRatio();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Paso3_Clasico1_Exp->SetTextFont(42);
	Paso3_Clasico1_Exp->SetFillColor(0); 
	Paso3_Clasico1_Exp->SetShadowColor(kGray);
	Paso3_Clasico1_Exp->SetTextAlign(12);
	Paso3_Clasico1_Exp->SetMargin(0.01);
	Paso3_Clasico1_Exp->AddText("For #font[62]{step 3}, once the value of #font[62]{r} that satisfies the condition is determined, the following procedure is solved to find the value of #font[62]{X} and obtain");
	Paso3_Clasico1_Exp->AddText("the values of #font[62]{P} and #font[62]{Q}.");
	Paso3_Clasico1_Exp->AddText("This operation is the same as the previous step because it is solved through #font[62]{modular algebra}.");
	Paso3_Clasico1_Exp->AddText("By finding this result of #font[62]{X}, it is possible to obtain the values of #font[62]{P} and #font[62]{Q} in the next step.");
 	Paso3_Clasico1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(0); 
      }

//Cuarto click nexto a=5
      	if(Breakopt == 4){
      	//Titulo
	TPaveText *Paso4_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso4_clasico->SetTextFont(62);
	Paso4_clasico->SetFillColor(kCyan-10); 
	Paso4_clasico->SetShadowColor(kGray);
	Paso4_clasico->SetMargin(0.1);
	Paso4_clasico->AddText("Step #4");
	Paso4_clasico->Draw();
     	
     	//Linea para dividir los resultados
     	lineaV1 = new TLine(0.5, 0.8, 0.5, 0.3);
     	lineaV1->SetLineColor(kBlack);
     	lineaV1->Draw(); 
	
	//Cuadro de resultado 1
     	TPaveText *Resultado_1 = new TPaveText(0.1, 0.7, 0.4, 0.8, "NDC"); 
	Resultado_1->SetTextFont(42);
	Resultado_1->SetFillColor(kBlue-10); 
	Resultado_1->SetShadowColor(kGray);
	Resultado_1->SetMargin(0.1);
	Resultado_1->AddText("P");
	Resultado_1->Draw();
	
	//Resultado 1
     	l1 = new TLatex();
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.65, "GCD(X-1, N)");
	
	l2 = new TLatex();
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.01, 0.55, "GCD(19, 21) = 1");
	
	l3 = new TLatex();
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.35, 0.65, "Equation");
	
	l4 = new TLatex();
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.35, 0.55, "Solution");
	
	//Cuadro donde muestro P=3
	TPaveText *Resultado_p = new TPaveText(0.09, 0.3, 0.4, 0.4, "NDC"); 
	Resultado_p->SetTextFont(42);
	Resultado_p->SetFillColor(kYellow-10); 
	Resultado_p->SetShadowColor(kGray);
	Resultado_p->SetMargin(0.1);
	Resultado_p->AddText("First result #color[2]{P} = 1");
	Resultado_p->Draw();
	
	//Flechas
	flecha1 = new TArrow(0.2, 0.65, 0.3, 0.65, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	flecha2 = new TArrow(0.2, 0.55, 0.3, 0.55, 0.01, ">");
	flecha2->SetLineColor(kRed);
     	flecha2->SetLineWidth(1);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
     	
	//Cuadro de resultado 2
     	TPaveText *Resultado_2 = new TPaveText(0.6, 0.7, 0.9, 0.8, "NDC"); 
	Resultado_2->SetTextFont(42);
	Resultado_2->SetFillColor(kBlue-10); 
	Resultado_2->SetShadowColor(kGray);
	Resultado_2->SetMargin(0.1);
	Resultado_2->AddText("Q");
	Resultado_2->Draw();
	
	//Cuadro donde muestro Q=5
	TPaveText *Resultado_q = new TPaveText(0.6, 0.3, 0.9, 0.4, "NDC"); 
	Resultado_q->SetTextFont(42);
	Resultado_q->SetFillColor(kYellow-10); 
	Resultado_q->SetShadowColor(kGray);
	Resultado_q->SetMargin(0.1);
	Resultado_q->AddText("Second result #color[8]{Q} = 21");
	Resultado_q->Draw();     	
     	
	//Resultado 2
     	l5 = new TLatex();
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.55, 0.65, "GCD(X+1, N)");
	
	l6 = new TLatex();
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.52, 0.55, "GCD(21, 21) = 21");
	
	//Flechas
	flecha5 = new TArrow(0.72, 0.65, 0.82, 0.65, 0.01, ">");
	flecha5->SetLineColor(kRed);
     	flecha5->SetLineWidth(1);
     	flecha5->SetLineStyle(1);
     	flecha5->Draw();
	
	flecha6 = new TArrow(0.72, 0.55, 0.82, 0.55, 0.01, ">");
	flecha6->SetLineColor(kRed);
     	flecha6->SetLineWidth(1);
     	flecha6->SetLineStyle(1);
     	flecha6->Draw();
	
	//Flechas
	l13 = new TLatex();
	l13->SetTextFont(42); 
	l13->SetTextColor(1); 
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.85, 0.65, "Equation");
	
	l14 = new TLatex();
	l14->SetTextFont(42); 
	l14->SetTextColor(1); 
	l14->SetTextAlign(12); 
	l14->DrawLatex(0.85, 0.55, "Solution");
	
	//Cuadro explicando el resultado trivial
	//Titulo
	TPaveText *Paso4_clasico_Resul_Trivi = new TPaveText(0.01, 0.25, 0.99, 0.01, "NDC"); 
	Paso4_clasico_Resul_Trivi->SetTextFont(42);
	Paso4_clasico_Resul_Trivi->SetFillColor(kMagenta-10); 
	Paso4_clasico_Resul_Trivi->SetShadowColor(kGray);
	Paso4_clasico_Resul_Trivi->SetMargin(0.1);
	Paso4_clasico_Resul_Trivi->AddText("This result from the #font[62]{Shor's algorithm} is known as the #font[62]{#color[2]{Trivial Result}}. It occurs quite often because");
	Paso4_clasico_Resul_Trivi->AddText("there are #font[62]{coprime numbers with N} that meet all the conditions but result in this type of solutions.");
	Paso4_clasico_Resul_Trivi->AddText("These solutions #font[62]{depend on the selected value of a}, which is why different values need to be tested");
	Paso4_clasico_Resul_Trivi->AddText("when working with the #font[62]{Shor's algorithm}.");
	Paso4_clasico_Resul_Trivi->Draw();
	
	//Segundo canvas    	
     	TCanvas *ExpPaso4 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
     	ExpPaso4->SetFixedAspectRatio();
	ExpPaso4->SetFillColor(0);
	ExpPaso4->SetEditable(1);
	ExpPaso4->Clear();
	ExpPaso4->Update();
	
	TPaveText *Paso4_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Paso4_Clasico1_Exp->SetTextFont(42);
	Paso4_Clasico1_Exp->SetFillColor(0);
	Paso4_Clasico1_Exp->SetShadowColor(kGray);
	Paso4_Clasico1_Exp->SetTextAlign(12);
	Paso4_Clasico1_Exp->SetMargin(0.01);
	Paso4_Clasico1_Exp->AddText("For #font[62]{step 4}, calculate the greatest common divisor of the highlighted equations, and the expected result gives the values of #font[62]{P} and #font[62]{Q}");
	Paso4_Clasico1_Exp->AddText("concluding the #font[62]{Shor's algorithm in its classical form}.");
	Paso4_Clasico1_Exp->AddText("Select the top tabs to view the #font[62]{circuit} or the #font[62]{quantum steps}.");
	Paso4_Clasico1_Exp->AddText("To return, press the #font[62]{CLEAR} button and select a #font[62]{new value to factor}.");
 	Paso4_Clasico1_Exp->Draw();     	
     	
     	ExpPaso4->Update();
	ExpPaso4->SetEditable(0); 
      	}
      	if(Breakopt == 5){
     	fTextButtonBACK->SetState(kButtonUp, kTRUE);
     	fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
     	DoClassical();
     	CambioTab(0);
     	}
      break;
      	} 
      	}
/*******************************************************************/   
}
if(Valueopt1 == 35){
  switch(Valueopt2){
     	case 1:{
     	if(Breakopt == 1){
     	//Titulo   
   	TPaveText *Paso1_clasico3 = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso1_clasico3->SetTextFont(62);
	Paso1_clasico3->SetFillColor(kBlue-10); 
	Paso1_clasico3->SetShadowColor(kGray);
	Paso1_clasico3->SetMargin(0.1);
	Paso1_clasico3->AddText("Step #1");
	Paso1_clasico3->Draw();
     	
     	//Lineas donde estaran los textos 
     	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	
     	//Numero a factorizar 
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "Number to be factored:");
	
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.3, 0.79, "#color[4]{35} = #color[2]{P}*#color[8]{Q}");
	
	//Valor de a
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.05, 0.70, "Value of a:");
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.3, 0.70, "#color[6]{2}");
     
      	//Algoritmo de euclides
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.15, 0.60, "Verifying #font[62]{#color[8]{Euclid's Algorithm}}:");
     
     	//Lineas del algoritmo de euclides
        lineaV1 = new TLine(0.2, 0.1, 0.2, 0.5);
	lineaV2 = new TLine(0.3, 0.1, 0.3, 0.5);
	
	lineaH1 = new TLine(0.1, 0.2, 0.4, 0.2);
	lineaH2 = new TLine(0.1, 0.4, 0.4, 0.4);
     
      	//dibuja las lineas
        lineaV1->SetLineColor(kBlack);
	lineaV2->SetLineColor(kBlack);
	
	lineaH1->SetLineColor(kBlack);
	lineaH1->SetLineColor(kBlack);
	
	lineaV1->Draw();
	lineaV2->Draw();
	
	lineaH1->Draw();
	lineaH2->Draw();
     
      	//primer numero del algoritmo de euclides
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.13, 0.31, "#color[4]{35}");
	
      	//segundo numero del algoritmo de euclides
	l7->SetTextFont(42); 
	l7->SetTextColor(2); 
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.24, 0.31, "#color[6]{2}");
	
       	//tercer numero del algoritmo de euclides
	l8->SetTextFont(42); 
	l8->SetTextColor(1); 
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.23, 0.48, "17");
	
       	//cuarto numero del algoritmo de euclides
	l9->SetTextFont(42); 
	l9->SetTextColor(1); 
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.24, 0.15, "1");	
     
       	//quinto numero del algoritmo de euclides
	l10->SetTextFont(42); 
	l10->SetTextColor(1); 
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.34, 0.31, "1");	
	
	//Texto junto al algoritmo de euclides
	TPaveText *EuclidesAlgor = new TPaveText(0.65, 0.1, 0.95, 0.7, "NDC"); 
	EuclidesAlgor->SetTextFont(42);
	
	EuclidesAlgor->SetFillColor(kGreen-10); 
	EuclidesAlgor->SetShadowColor(kGray);
	EuclidesAlgor->SetMargin(0.1);
	EuclidesAlgor->AddText("#font[62]{#scale[1.4]{Euclid's algorithm}}");
	EuclidesAlgor->AddText("the #font[62]{Euclid's algorithm} allows determining");
	EuclidesAlgor->AddText("if the selection of the value of #font[62]{a} is");
	EuclidesAlgor->AddText("a number coprime with #font[62]{N}");
	EuclidesAlgor->AddText("which is an important condition for");
	EuclidesAlgor->AddText("moving forward with the next steps.");
	EuclidesAlgor->Draw();
	
	flecha1 = new TArrow(0.43, 0.3, 0.63, 0.3, 0.01, "<>");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
     	
     	//Segundo Canvas
	TCanvas *ExpPaso1_35 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1_35->SetFixedAspectRatio();
	ExpPaso1_35->SetFillColor(0);
	ExpPaso1_35->SetEditable(1);
	ExpPaso1_35->Clear();
	ExpPaso1_35->Update();
	
	TPaveText *Paso1_Clasico1_Exp_35 = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Paso1_Clasico1_Exp_35->SetTextFont(42);
	Paso1_Clasico1_Exp_35->SetFillColor(0); 
	Paso1_Clasico1_Exp_35->SetShadowColor(kGray);
	Paso1_Clasico1_Exp_35->SetTextAlign(12);
	Paso1_Clasico1_Exp_35->SetMargin(0.01);
	Paso1_Clasico1_Exp_35->AddText("For #font[62]{step 1}, it is necessary to identify that the values to be found are #font[62]{P} and #font[62]{Q}");
	Paso1_Clasico1_Exp_35->AddText("Then, Euclid's algorithm is implemented to verify if #font[62]{a} and #font[62]{N} are coprime. The steps to solve it can be found by pressing");
	Paso1_Clasico1_Exp_35->AddText("the #font[62]{CLEAR} button and then #font[62]{CONCEPTS}.");
	Paso1_Clasico1_Exp_35->AddText("If the final result is 1, then the chosen number is coprime with the number you want to factor. ");
 	Paso1_Clasico1_Exp_35->Draw();     	
     	
     	ExpPaso1_35->Update();
	ExpPaso1_35->SetEditable(0);   
      }

//Segundo click next
      	if(Breakopt == 2){
       	//Titulo
      	TPaveText *Paso2_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso2_clasico->SetTextFont(62);
	Paso2_clasico->SetFillColor(kGreen-10); 
	Paso2_clasico->SetShadowColor(kGray);
	Paso2_clasico->SetMargin(0.1);
	Paso2_clasico->AddText("Step #2");
	Paso2_clasico->Draw();
	
	TPad *Tabla_1caso_35 = new TPad("pad2","This is pad2",0.01 ,0.01, 0.5, 0.80); 
	Tabla_1caso_35->SetFillColor(0);
	Tabla_1caso_35->Draw();

	TPad *Grafico_1caso_35 = new TPad("pad3","This is pad3",0.5, 0.01, 0.99, 0.80);
	Grafico_1caso_35->SetFillColor(0);
	Grafico_1caso_35->Draw();
      
       	//primer Tpad de la tabla
        Tabla_1caso_35->cd();
        l1 = new TLatex();
	
	l1->SetTextColor(4); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.3, 0.98, "#font[62]{Data Table}");
      
      	//Tabla 
      	TPaveText *table = new TPaveText(0.5, 0.1, 0.90, 0.90, "NDC");
      	table->SetTextFont(42);
    	table->SetBorderSize(2);
	table->SetFillColor(kYellow-10); 
	table->SetShadowColor(kGray);
    	table->SetTextAlign(22); 
    
    	//Agregar filas a la tabla
    	table->AddLine(0.5, 0.99, 0.5 , 0.001);
    	table->AddText("");
    	table->AddText("   #font[62]{#scale[1.7]{r}}      #font[62]{#scale[1.7]{F_{a,N}}}");
    	table->AddLine(0, 0.85, 1, 0.85);
    	table->AddText("");
    	table->AddText("1                               2");
    	table->AddText("2                               4");
    	table->AddText("3                               8");
    	table->AddText("4                              16");
    	table->AddText("5                              32");
    	table->AddText("6                              29");
    	table->AddText("7                              23");
    	table->AddText("8                              11");
    	table->AddText("9                              22");
    	table->AddText("10                              9");
    	table->AddText("11                             18");
    	table->AddText("#font[62]{#color[2]{12}}         #font[62]{#color[2]{1}}");
    	table->AddText("13                              2");
    	//Dibujar la tabla en el canvas
    	table->Draw();
      
      	//linea de separacion de datos
    	lineaV1 = new TLine(0.7, 0.90, 0.7, 0.1);
     	lineaV1->SetLineColor(kBlack);
     	lineaV1->Draw();
      
      	//Flecha
    	flecha1 = new TArrow(0.3, 0.17, 0.48, 0.17, 0.01, "<>");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw(); 
      
       	//Texto al lado de la flecha
    	l2 = new TLatex(); 
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.08, 0.18, "Value of #font[62]{r}"); 	
      
       	//Segundo TPad donde se encuentra el grafico
    	Grafico_1caso_35->cd(); 
    	//Crear el gráfico
    	const int nPoints = 30;
    	double x[nPoints];
    	double y[nPoints];

    	//Definir a y N
    	const double a = 2; 
    	const int N = 35;    
    	
    	//Llenar los arreglos con valores
    	for (int r = 1; r <= nPoints; r++) {
        x[r - 1] = r;  

        //Calcular y = (a^r) mod N
        int result = static_cast<int>(pow(a, r)) % N; 
      //Asegurarse de que el resultado es positivo
        y[r - 1] = (result + N) % N; 
    	}
    	//Crear un gráfico de puntos
    	TGraph *graph = new TGraph(nPoints, x, y);

    	//Establecer propiedades del gráfico
    	graph->SetTitle("#font[62]{F_{a,N}= 2^{r} (mod 35)};X;Y"); 
    	graph->SetMarkerStyle(20);              
    	graph->SetMarkerColor(kRed);           
    	graph->SetLineColor(kBlue);              
    	graph->SetLineWidth(2);                 

    	//Dibujar el gráfico
    	graph->Draw();
      
      	//Segundo Canvas
	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFixedAspectRatio();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	
	TPaveText *Paso2_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Paso2_Clasico1_Exp->SetTextFont(42);
	Paso2_Clasico1_Exp->SetFillColor(0); 
	Paso2_Clasico1_Exp->SetShadowColor(kGray);
	Paso2_Clasico1_Exp->SetTextAlign(12);
	Paso2_Clasico1_Exp->SetMargin(0.01);
	Paso2_Clasico1_Exp->AddText("For #font[62]{step 2}, it is necessary to create a #font[62]{data table of the modular function} to obtain the periodicity graph shown on the right");
	Paso2_Clasico1_Exp->AddText("and determine the correct value of #font[62]{r} chosen for subsequent steps. The value of #font[62]{r} will be the first one that makes #font[62]{F_{a,N} = 1}");
	Paso2_Clasico1_Exp->AddText("The data table shows the #font[62]{periodicity of the function}, as values of #font[62]{F_{a,N}} repeat after selecting #font[62]{r}.");
	Paso2_Clasico1_Exp->AddText("Thus, it is verified that the value of #font[62]{r} is even to proceed with the next step, and if it is odd, another value of #font[62]{a} is selected.");
 	Paso2_Clasico1_Exp->Draw();     	
     	
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(0);       
      }
      
//Tercwer Click next 
     	if(Breakopt == 3){
       	//Titulo
      	TPaveText *Paso3_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso3_clasico->SetTextFont(62);
	Paso3_clasico->SetFillColor(kMagenta-10); 
	Paso3_clasico->SetShadowColor(kGray);
	Paso3_clasico->SetMargin(0.1);
	Paso3_clasico->AddText("Step #3");
	Paso3_clasico->Draw();
      
      	//Expresion
     	l1 = new TLatex();
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.12, 0.72, "X = a^{#frac{r}{2}} (mod N)");
      
      	//Reemplazo
	l2 = new TLatex();
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.1, 0.44, "X = 2^{#frac{12}{2}} (mod 35)");
	
	//Respuesta
	l3 = new TLatex();
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.07, 0.13, "X = 2^{6} (mod 35) = 29");
	
	//Flecha 1
	flecha1 = new TArrow(0.31, 0.70, 0.5, 0.70, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
      
      	//Flecha 2
	flecha2 = new TArrow(0.31, 0.42, 0.5, 0.42, 0.01, ">");
	flecha2->SetLineColor(kRed);
     	flecha2->SetLineWidth(1);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
     
      	//Flecha 3
	flecha3 = new TArrow(0.31, 0.12, 0.5, 0.12, 0.01, ">");
	flecha3->SetLineColor(kRed);
     	flecha3->SetLineWidth(1);
     	flecha3->SetLineStyle(1);
     	flecha3->Draw();	
	
	//Cuadro 1	
     	TPaveText *Paso3_clasico_TexFlecha1 = new TPaveText(0.55, 0.62, 0.94, 0.75, "NDC"); 
	Paso3_clasico_TexFlecha1->SetTextFont(42);
	Paso3_clasico_TexFlecha1->SetFillColor(kOrange-9); 
	Paso3_clasico_TexFlecha1->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha1->SetMargin(0.1);
	Paso3_clasico_TexFlecha1->AddText("Replace the value of #font[62]{r} in this expression.");
	Paso3_clasico_TexFlecha1->Draw();	
      
     	//Cuadro 2
     	TPaveText *Paso3_clasico_TexFlecha2 = new TPaveText(0.53, 0.30, 0.96, 0.50, "NDC"); 
	Paso3_clasico_TexFlecha2->SetTextFont(42);
	Paso3_clasico_TexFlecha2->SetFillColor(kAzure-9); 
	Paso3_clasico_TexFlecha2->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha2->SetMargin(0.1);
	Paso3_clasico_TexFlecha2->AddText("Since the value is #font[62]{even}, it can be used.");
	Paso3_clasico_TexFlecha2->AddText("If it is odd, this step cannot be performed and");
	Paso3_clasico_TexFlecha2->AddText("select a new value of #font[62]{a}.");
	Paso3_clasico_TexFlecha2->Draw();
	
      	//Cuadro 3
      	TPaveText *Paso3_clasico_TexFlecha3 = new TPaveText(0.55, 0.05, 0.94, 0.17, "NDC"); 
	Paso3_clasico_TexFlecha3->SetTextFont(42);
	Paso3_clasico_TexFlecha3->SetFillColor(kTeal-9); 
	Paso3_clasico_TexFlecha3->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha3->SetMargin(0.1);
	Paso3_clasico_TexFlecha3->AddText("Final #font[62]{result} after the operation.");
	Paso3_clasico_TexFlecha3->Draw();
	
	//Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
     	ExpPaso3->SetFixedAspectRatio();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Paso3_Clasico1_Exp->SetTextFont(42);
	Paso3_Clasico1_Exp->SetFillColor(0); 
	Paso3_Clasico1_Exp->SetShadowColor(kGray);
	Paso3_Clasico1_Exp->SetTextAlign(12);
	Paso3_Clasico1_Exp->SetMargin(0.01);
	Paso3_Clasico1_Exp->AddText("For #font[62]{step 3}, once the value of #font[62]{r} that satisfies the condition is determined, the following procedure is solved to find the value of #font[62]{X} and obtain ");
	Paso3_Clasico1_Exp->AddText("the values of #font[62]{P} and #font[62]{Q}.");
	Paso3_Clasico1_Exp->AddText("This operation is the same as the previous step because it is solved through #font[62]{modular algebra}.");
	Paso3_Clasico1_Exp->AddText("By finding this result of #font[62]{X}, it is possible to obtain the values of #font[62]{P} and #font[62]{Q} in the next step.");
 	Paso3_Clasico1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(0); 
      }
      
//Cuarto click next  
     	if(Breakopt == 4){
     	//Titulo
      	TPaveText *Paso4_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso4_clasico->SetTextFont(62);
	Paso4_clasico->SetFillColor(kCyan-10); 
	Paso4_clasico->SetShadowColor(kGray);
	Paso4_clasico->SetMargin(0.1);
	Paso4_clasico->AddText("Step #4");
	Paso4_clasico->Draw();
      
      	//Linea para dividir los resultados
     	lineaV1 = new TLine(0.5, 0.8, 0.5, 0.01);
     	lineaV1->SetLineColor(kBlack);
     	lineaV1->Draw(); 
     
      	//Cuadro de resultado 1
     	TPaveText *Resultado_1 = new TPaveText(0.1, 0.7, 0.4, 0.8, "NDC"); 
	Resultado_1->SetTextFont(42);
	Resultado_1->SetFillColor(kBlue-10); 
	Resultado_1->SetShadowColor(kGray);
	Resultado_1->SetMargin(0.1);
	Resultado_1->AddText("P");
	Resultado_1->Draw();
	
	//Resultado 1
     	l1 = new TLatex();
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.65, "GCD(X-1, N)");

	l2 = new TLatex();
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.01, 0.55, "GCD(29-1, 35)");

	l3 = new TLatex();
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.01, 0.45, "GCD(28, 35)");
	
	l4 = new TLatex();
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.01, 0.35, "GCD(28, 35) = 7");
	
	//Textos al lado
	l5 = new TLatex();
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.35, 0.65, "Equation");
	
	l6 = new TLatex();
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.35, 0.55, "Replace");
	
	l7 = new TLatex();
	l7->SetTextFont(42); 
	l7->SetTextColor(1); 
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.35, 0.45, "Solve");
	
	l8 = new TLatex();
	l8->SetTextFont(42); 
	l8->SetTextColor(1); 
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.35, 0.35, "Solution");
	
	//Cuadro donde muestro P=3
	TPaveText *Resultado_p = new TPaveText(0.08, 0.1, 0.4, 0.2, "NDC"); 
	Resultado_p->SetTextFont(42);
	Resultado_p->SetFillColor(kYellow-10); 
	Resultado_p->SetShadowColor(kGray);
	Resultado_p->SetMargin(0.1);
	Resultado_p->AddText("First result #color[2]{P} = 7");
	Resultado_p->Draw();
	
	//Flechas
	flecha1 = new TArrow(0.2, 0.65, 0.3, 0.65, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	flecha2 = new TArrow(0.2, 0.55, 0.3, 0.55, 0.01, ">");
	flecha2->SetLineColor(kRed);
     	flecha2->SetLineWidth(1);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
	
	flecha3 = new TArrow(0.2, 0.45, 0.3, 0.45, 0.01, ">");
	flecha3->SetLineColor(kRed);
     	flecha3->SetLineWidth(1);
     	flecha3->SetLineStyle(1);
     	flecha3->Draw();
	
	flecha4 = new TArrow(0.2, 0.35, 0.3, 0.35, 0.01, ">");
	flecha4->SetLineColor(kRed);
     	flecha4->SetLineWidth(1);
     	flecha4->SetLineStyle(1);
     	flecha4->Draw();
      //Cuadro de resultado 2
     	TPaveText *Resultado_2 = new TPaveText(0.6, 0.7, 0.9, 0.8, "NDC"); 
	Resultado_2->SetTextFont(42);
	Resultado_2->SetFillColor(kBlue-10); 
	Resultado_2->SetShadowColor(kGray);
	Resultado_2->SetMargin(0.1);
	Resultado_2->AddText("Q");
	Resultado_2->Draw();
	
	//Cuadro donde muestro Q=3
	TPaveText *Resultado_q = new TPaveText(0.6, 0.1, 0.9, 0.2, "NDC"); 
	Resultado_q->SetTextFont(42);
	Resultado_q->SetFillColor(kYellow-10); 
	Resultado_q->SetShadowColor(kGray);
	Resultado_q->SetMargin(0.1);
	Resultado_q->AddText("Second result #color[8]{Q} = 5");
	Resultado_q->Draw();
      //Resultado 2
     	l9 = new TLatex();
	l9->SetTextFont(42); 
	l9->SetTextColor(1); 
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.55, 0.65, "GCD(X+1, N)");

	l10 = new TLatex();
	l10->SetTextFont(42); 
	l10->SetTextColor(1); 
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.55, 0.55, "GCD(29+1, 35)");
      l11 = new TLatex();
	l11->SetTextFont(42); 
	l11->SetTextColor(1); 
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.55, 0.45, "GCD(30, 35)");
      l12 = new TLatex();
	l12->SetTextFont(42); 
	l12->SetTextColor(1); 
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.55, 0.35, "GCD(30, 35) = 5");
      l13 = new TLatex();
	l13->SetTextFont(42); 
	l13->SetTextColor(1); 
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.85, 0.65, "Equation");
	
	l14 = new TLatex();
	l14->SetTextFont(42); 
	l14->SetTextColor(1); 
	l14->SetTextAlign(12); 
	l14->DrawLatex(0.85, 0.55, "Replace");
	
	l15 = new TLatex();
	l15->SetTextFont(42); 
	l15->SetTextColor(1); 
	l15->SetTextAlign(12); 
	l15->DrawLatex(0.85, 0.45, "Solve");
	
	l16 = new TLatex();
	l16->SetTextFont(42); 
	l16->SetTextColor(1); 
	l16->SetTextAlign(12); 
	l16->DrawLatex(0.85, 0.35, "Solution");
	
	//Flechas
	flecha5 = new TArrow(0.72, 0.65, 0.82, 0.65, 0.01, ">");
	flecha5->SetLineColor(kRed);
     	flecha5->SetLineWidth(1);
     	flecha5->SetLineStyle(1);
     	flecha5->Draw();
	
	flecha6 = new TArrow(0.72, 0.55, 0.82, 0.55, 0.01, ">");
	flecha6->SetLineColor(kRed);
     	flecha6->SetLineWidth(1);
     	flecha6->SetLineStyle(1);
     	flecha6->Draw();
	
	flecha7 = new TArrow(0.72, 0.45, 0.82, 0.45, 0.01, ">");
	flecha7->SetLineColor(kRed);
     	flecha7->SetLineWidth(1);
     	flecha7->SetLineStyle(1);
     	flecha7->Draw();
	
	flecha8 = new TArrow(0.74, 0.35, 0.82, 0.35, 0.01, ">");
	flecha8->SetLineColor(kRed);
     	flecha8->SetLineWidth(1);
     	flecha8->SetLineStyle(1);
     	flecha8->Draw();
     	
     	
     	//Segundo canvas    	
     	TCanvas *ExpPaso4 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
     	ExpPaso4->SetFixedAspectRatio();
	ExpPaso4->SetFillColor(0);
	ExpPaso4->SetEditable(1);
	ExpPaso4->Clear();
	ExpPaso4->Update();
	
	TPaveText *Paso4_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Paso4_Clasico1_Exp->SetTextFont(42);
	Paso4_Clasico1_Exp->SetFillColor(0);
	Paso4_Clasico1_Exp->SetShadowColor(kGray);
	Paso4_Clasico1_Exp->SetTextAlign(12);
	Paso4_Clasico1_Exp->SetMargin(0.01);
	Paso4_Clasico1_Exp->AddText("For #font[62]{step 4}, calculate the greatest common divisor of the highlighted equations, and the expected result gives the values of #font[62]{P} and #font[62]{Q}");
	Paso4_Clasico1_Exp->AddText("concluding the #font[62]{Shor's algorithm in its classical form}.");
	Paso4_Clasico1_Exp->AddText("Select the top tabs to view the #font[62]{circuit} or the #font[62]{quantum steps}.");
	Paso4_Clasico1_Exp->AddText("To return, press the #font[62]{CLEAR} button and select a #font[62]{new value to factor}.");
 	Paso4_Clasico1_Exp->Draw();     	
     	
     	ExpPaso4->Update();
	ExpPaso4->SetEditable(0); 
      	}
      	if(Breakopt == 5){
     	fTextButtonBACK->SetState(kButtonUp, kTRUE);
     	fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
     	DoClassical();
     	CambioTab(0);
     	} 
     	break;
     	}
//primer click next a=11 
     	case 11:{
     	if(Breakopt == 1){
 
        //Titulo
       	TPaveText *Paso1_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso1_clasico->SetTextFont(62);
	Paso1_clasico->SetFillColor(kBlue-10); 
	Paso1_clasico->SetShadowColor(kGray);
	Paso1_clasico->SetMargin(0.1);
	Paso1_clasico->AddText("Step #1");
	Paso1_clasico->Draw();
     	
     	//Lineas
     	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
      
       	//Textos
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "Number to be factored: ");
	
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.3, 0.79, "#color[4]{35} = #color[2]{P}*#color[8]{Q}");
	
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.05, 0.70, "Value of a:");
     	 
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.3, 0.70, "#color[6]{11}");
     
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.15, 0.60, "Verifying #font[62]{#color[8]{Euclid's Algorithm}}:"); 
     
     	//lineas
        lineaV1 = new TLine(0.2, 0.1, 0.2, 0.5);
        lineaV2 = new TLine(0.3, 0.1, 0.3, 0.5);
	lineaV3 = new TLine(0.4, 0.1, 0.4, 0.5);
	
	lineaH1 = new TLine(0.1, 0.2, 0.5, 0.2);
	lineaH2 = new TLine(0.1, 0.4, 0.5, 0.4);
     
     	//primer numero del algoritmo de euclides
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.13, 0.31, "#color[4]{35}");
	
	//segundo numero del algoritmo de euclides
	l7->SetTextFont(42); 
	l7->SetTextColor(2); 
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.23, 0.31, "#color[6]{11}");
     
     	//tercer numero del algoritmo de euclides 
	l8->SetTextFont(42); 
	l8->SetTextColor(1); 
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.24, 0.48, "3");
     
     	//cuarto numero del algoritmo de euclides
	l9->SetTextFont(42); 
	l9->SetTextColor(1); 
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.24, 0.15, "2");
	
	//quinto numero del algoritmo de euclides
	l10->SetTextFont(42); 
	l10->SetTextColor(1); 
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.34, 0.31, "2");
	
	//sexto numero del algoritmo de euclides 
	l11->SetTextFont(42); 
	l11->SetTextColor(1); 
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.34, 0.48, "5");
	
	//septimo numero del algoritmo de euclides 
	l12->SetTextFont(42); 
	l12->SetTextColor(1); 
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.34, 0.15, "1");
	
	//octavo numero del algoritmo de euclides 
	l13->SetTextFont(42); 
	l13->SetTextColor(1); 
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.44, 0.31, "1");
	
     	//Texto junto al algoritmo de euclides
	TPaveText *EuclidesAlgor = new TPaveText(0.65, 0.1, 0.95, 0.7, "NDC"); 
	EuclidesAlgor->SetTextFont(42);
	EuclidesAlgor->SetFillColor(kGreen-10); 
	EuclidesAlgor->SetShadowColor(kGray);
	EuclidesAlgor->SetMargin(0.1);
	EuclidesAlgor->AddText("#font[62]{#scale[1.4]{Euclid's algorithm}}");
	EuclidesAlgor->AddText("the #font[62]{Euclid's algorithm} allows determining");
	EuclidesAlgor->AddText("if the selection of the value of #font[62]{a} is");
	EuclidesAlgor->AddText("a number coprime with #font[62]{N}");
	EuclidesAlgor->AddText("which is an important condition for");
	EuclidesAlgor->AddText("moving forward with the next steps.");
	EuclidesAlgor->Draw();
	
	flecha1 = new TArrow(0.53, 0.3, 0.63, 0.3, 0.01, "<>");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	lineaV1->SetLineColor(kBlack);
	lineaV2->SetLineColor(kBlack);
	lineaV3->SetLineColor(kBlack);
	lineaH1->SetLineColor(kBlack);
	lineaH1->SetLineColor(kBlack);
	
	lineaV1->Draw();
	lineaV2->Draw();
	lineaV3->Draw();
	lineaH1->Draw();
	lineaH2->Draw();
     
     	//Segundo Canvas
	TCanvas *ExpPaso1 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1->SetFixedAspectRatio();
	ExpPaso1->SetFillColor(0);
	ExpPaso1->SetEditable(1);
	ExpPaso1->Clear();
	ExpPaso1->Update();
	
	TPaveText *Paso1_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Paso1_Clasico1_Exp->SetTextFont(42);
	Paso1_Clasico1_Exp->SetFillColor(0); 
	Paso1_Clasico1_Exp->SetShadowColor(kGray);
	Paso1_Clasico1_Exp->SetTextAlign(12);
	Paso1_Clasico1_Exp->SetMargin(0.01);
	Paso1_Clasico1_Exp->AddText("For #font[62]{step 1}, it is necessary to identify that the values to be found are #font[62]{P} and #font[62]{Q}");
	Paso1_Clasico1_Exp->AddText("Then, Euclid's algorithm is implemented to verify if #font[62]{a} and #font[62]{N} are coprime. The steps to solve it can be found by pressing");
	Paso1_Clasico1_Exp->AddText("the #font[62]{CLEAR} button and then #font[62]{CONCEPTS}.");
	Paso1_Clasico1_Exp->AddText("If the final result is 1, then the chosen number is coprime with the number you want to factor.");
 	Paso1_Clasico1_Exp->Draw();     	
     	
     	ExpPaso1->Update();
	ExpPaso1->SetEditable(0); 
     }
//segundo click next a=11 
     	if(Breakopt == 2){
     
      	//Titulo
     	TPaveText *Paso2_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso2_clasico->SetTextFont(62);
	Paso2_clasico->SetFillColor(kGreen-10); 
	Paso2_clasico->SetShadowColor(kGray);
	Paso2_clasico->SetMargin(0.1);
	Paso2_clasico->AddText("Step #2");
	Paso2_clasico->Draw();
	
	TPad *Tabla_2caso_11 = new TPad("pad2","This is pad2",0.01 ,0.01, 0.5, 0.80); 
	Tabla_2caso_11->SetFillColor(0);
	Tabla_2caso_11->Draw();

	TPad *Grafico_2caso_11 = new TPad("pad3","This is pad3",0.5, 0.01, 0.99, 0.80);
	Grafico_2caso_11->SetFillColor(0);
	Grafico_2caso_11->Draw();
     
     	//primer Tpad de la tabla
        Tabla_2caso_11->cd();
        l1 = new TLatex();
	
	l1->SetTextColor(4); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.3, 0.98, "#font[62]{Data Table}");
	
	//Tabla
     	TPaveText *table = new TPaveText(0.5, 0.1, 0.90, 0.90, "NDC");
     	table->SetTextFont(42);
    	table->SetBorderSize(2);
	table->SetFillColor(kYellow-10); 
	table->SetShadowColor(kGray);
    	table->SetTextAlign(22); 
    	
    	//Agregar filas a la tabla
    	table->AddLine(0.5, 0.99, 0.5 , 0.001);
    	table->AddText(" #font[62]{#scale[1.7]{r}}        #font[62]{#scale[1.7]{F_{a,N}}}");
    	table->AddLine(0, 0.90, 1, 0.90);
    	table->AddText("1                               11");
    	table->AddText("2                               16");
    	table->AddText("#font[62]{#color[2]{3}}        #font[62]{#color[2]{1}}");
    	table->AddText("4                               11");
    	table->AddText("5                               16");
    	table->AddText("6                               1");
    	table->AddText("7                               11");
    	table->AddText("8                               16");
    	table->AddText("9                               1");
    
    	//Dibujar la tabla en el canvas
    	table->Draw();

	//Flecha
    	flecha1 = new TArrow(0.3, 0.63, 0.48, 0.63, 0.01, "<>");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	//Texto al lado de la flecha
    	l2 = new TLatex();
	 
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.08, 0.63, "Value of #font[62]{r}"); 
    	
    	//Segundo TPad donde se encuentra el grafico
    	Grafico_2caso_11->cd(); 
    	//Crear el gráfico
    	const int nPoints = 9;
    	double x[nPoints];
    	double y[nPoints];

    	//Definir a y N
    	const double a = 11; 
    	const int N = 35;    
    	
    	//Llenar los arreglos con valores
    	for (int r = 1; r <= nPoints; r++) {
        x[r - 1] = r;  

        // Calcular y = (a^r) mod N
        int result = static_cast<int>(pow(a, r)) % N; 
      // Asegurarse de que el resultado es positivo
        y[r - 1] = (result + N) % N; 
    	}
	//Crear un gráfico de puntos
    	TGraph *graph = new TGraph(nPoints, x, y);

    	//Establecer propiedades del gráfico
    	graph->SetTitle("#font[62]{F_{a,N}= 11^{r} (mod 35)};X;Y"); 
    	graph->SetMarkerStyle(20);              
    	graph->SetMarkerColor(kRed);           
    	graph->SetLineColor(kBlue);              
    	graph->SetLineWidth(2);                 

    	//Dibujar el gráfico
    	graph->Draw();
    	
    	//Segundo Canvas
	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFixedAspectRatio();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	
	TPaveText *Paso2_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Paso2_Clasico1_Exp->SetTextFont(42);
	Paso2_Clasico1_Exp->SetFillColor(0); 
	Paso2_Clasico1_Exp->SetShadowColor(kGray);
	Paso2_Clasico1_Exp->SetTextAlign(12);
	Paso2_Clasico1_Exp->SetMargin(0.01);
	Paso2_Clasico1_Exp->AddText("For #font[62]{step 2}, it is necessary to create a #font[62]{data table of the modular function} to obtain the periodicity graph shown on the right");
	Paso2_Clasico1_Exp->AddText("and determine the correct value of #font[62]{r} chosen for subsequent steps. The value of #font[62]{r} will be the first one that makes #font[62]{F_{a,N} = 1}");
	Paso2_Clasico1_Exp->AddText("The data table shows the #font[62]{periodicity of the function}, as values of #font[62]{F_{a,N}} repeat after selecting #font[62]{r}.");
	Paso2_Clasico1_Exp->AddText("Thus, it is verified that the value of #font[62]{r} is even to proceed with the next step, and if it is odd, another value of #font[62]{a} is selected.");
 	Paso2_Clasico1_Exp->Draw();     	
     	
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(0); 
     	}
//tercer click next a=11 
     	if(Breakopt == 3){
     	//Titulo
      	TPaveText *Paso3_clasico = new TPaveText(0.01, 0.85, 0.99, 0.99, "NDC"); 
	Paso3_clasico->SetTextFont(62);
	Paso3_clasico->SetFillColor(kMagenta-10); 
	Paso3_clasico->SetShadowColor(kGray);
	Paso3_clasico->SetMargin(0.1);
	Paso3_clasico->AddText("Step #3");
	Paso3_clasico->Draw();
      
      	//Expresion
     	l1 = new TLatex();
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.12, 0.72, "X = a^{#frac{r}{2}} (mod N)");
	
	//Reemplazo
	l2 = new TLatex();
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.1, 0.44, "X = 11^{#frac{3}{2}} (mod 35)");
	
	//Respuesta
	l3 = new TLatex();
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.07, 0.13, "X = 11^{#frac{3}{2}} (mod 35) = ? ");
	
      	//Flecha 1
	flecha1 = new TArrow(0.31, 0.70, 0.5, 0.70, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
     	
     	TPaveText *Paso3_clasico_TexFlecha1 = new TPaveText(0.55, 0.62, 0.94, 0.75, "NDC"); 
	Paso3_clasico_TexFlecha1->SetTextFont(42);
	Paso3_clasico_TexFlecha1->SetFillColor(kOrange-9); 
	Paso3_clasico_TexFlecha1->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha1->SetMargin(0.1);
	Paso3_clasico_TexFlecha1->AddText("Replace the value of #font[62]{r} in this expression.");
	Paso3_clasico_TexFlecha1->Draw();
      
      	//Flecha 2
	flecha2 = new TArrow(0.31, 0.42, 0.5, 0.42, 0.01, ">");
	flecha2->SetLineColor(kRed);
     	flecha2->SetLineWidth(1);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
     	
     	TPaveText *Paso3_clasico_TexFlecha2 = new TPaveText(0.51, 0.30, 0.98, 0.50, "NDC"); 
	Paso3_clasico_TexFlecha2->SetTextFont(42);
	
	Paso3_clasico_TexFlecha2->SetFillColor(kAzure-9); 
	Paso3_clasico_TexFlecha2->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha2->SetMargin(0.1);
	Paso3_clasico_TexFlecha2->AddText("The found value of #font[62]{r} is #font[62]{odd}, therefore");
	Paso3_clasico_TexFlecha2->AddText("when performing the operation, no result will be found.");
	Paso3_clasico_TexFlecha2->AddText("It is necessary to #font[62]{choose another value of a} to proceed.");
	Paso3_clasico_TexFlecha2->AddText("with the #font[62]{Shor's algorithm}.");
	Paso3_clasico_TexFlecha2->Draw();
      
      	//Flecha 3
	flecha3 = new TArrow(0.31, 0.12, 0.5, 0.12, 0.01, ">");
	flecha3->SetLineColor(kRed);
     	flecha3->SetLineWidth(1);
     	flecha3->SetLineStyle(1);
     	flecha3->Draw();
     	
     	TPaveText *Paso3_clasico_TexFlecha3 = new TPaveText(0.55, 0.05, 0.94, 0.17, "NDC"); 
	Paso3_clasico_TexFlecha3->SetTextFont(42);
	Paso3_clasico_TexFlecha3->SetFillColor(kTeal-9); 
	Paso3_clasico_TexFlecha3->SetShadowColor(kGray);
	Paso3_clasico_TexFlecha3->SetMargin(0.1);
	Paso3_clasico_TexFlecha3->AddText("Result not found because #font[62]{r is odd}.");
	Paso3_clasico_TexFlecha3->Draw();
     
      	//Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
     	ExpPaso3->SetFixedAspectRatio();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Clasico1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Paso3_Clasico1_Exp->SetTextFont(42);
	Paso3_Clasico1_Exp->SetFillColor(0); 
	Paso3_Clasico1_Exp->SetShadowColor(kGray);
	Paso3_Clasico1_Exp->SetTextAlign(12);
	Paso3_Clasico1_Exp->SetMargin(0.01);
	Paso3_Clasico1_Exp->AddText("For #font[62]{step 3}, once the value of #font[62]{r} that satisfies the condition is determined, the following procedure is solved to find the value of #font[62]{X} and obtain");
	Paso3_Clasico1_Exp->AddText("the values of #font[62]{P} and #font[62]{Q}.");
	Paso3_Clasico1_Exp->AddText("This operation is the same as the previous step because it is solved through #font[62]{modular algebra}.");
	Paso3_Clasico1_Exp->AddText("By finding this result of #font[62]{X}, it is possible to obtain the values of #font[62]{P} and #font[62]{Q} in the next step.");
 	Paso3_Clasico1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(0); 
      
      	fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
     	}
     	}
     	break;
	}
	}
	canvas1->Update();
}
/*************************************************************/
void MyMainFrame::DoCircuit(){

fTextButtonBACK->SetState(kButtonDisabled, kTRUE);
//Inicio de los paso
TCanvas *Circuit = fRootEmbeddedCanvasDRAWCIRCUIT->GetCanvas();
Circuit->SetFillColor(0);
Circuit->SetEditable(1);
Circuit->Clear();
Circuit->cd();  

//Titulo
TPaveText *Pasos_Circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
Pasos_Circuit->SetTextFont(62);
Pasos_Circuit->SetFillColor(0); 
Pasos_Circuit->SetShadowColor(kGray);
Pasos_Circuit->SetMargin(0);
Pasos_Circuit->AddText("StepsFor the #color[2]{Qua}ntum #color[4]{Circ}uit of Shor's Algorithm.");
Pasos_Circuit->Draw();

//Separaciones
	TPad *paso1 = new TPad("pad1","This is pad1",0.01 ,0.42, 0.50, 0.83); 
	paso1->SetFillColor(0);
	paso1->Draw();
	
	TPad *paso2 = new TPad("pad2","This is pad2",0.51 ,0.42, 0.99, 0.83); 
	paso2->SetFillColor(0);
	paso2->Draw();

	TPad *paso3 = new TPad("pad3","This is pad3",0.01, 0.01, 0.50, 0.40);
	paso3->SetFillColor(0);
	paso3->Draw();
	
	TPad *paso4 = new TPad("pad3","This is pad3",0.51, 0.01, 0.99, 0.40);
	paso4->SetFillColor(0);
	paso4->Draw();

//Texto dentro del pad1
	//Texto dentro del pad1
	paso1->cd();
	TPaveText *TPTPaso1 = new TPaveText(0.001 ,0.009, 0.995, 0.995); 
 	TPTPaso1->SetTextFont(42);
	TPTPaso1->SetFillColor(kBlue-10); 
	TPTPaso1->SetShadowColor(kGray);
	TPTPaso1->SetTextAlign(12);
	TPTPaso1->SetMargin(0.04);
	TPTPaso1->AddText("");
 	TPTPaso1->AddText("#font[62]{#scale[1.7]{STEP #1}}");
 	TPTPaso1->AddText("The first step is to determine the number of #font[62]{qbits} #font[62]{n} and the #font[62]{kets} #font[62]{|x#GT}");
 	TPTPaso1->AddText("and #font[62]{|w#GT} and initialize them in the states #font[62]{|x#GT} -> #font[62]{|0#GT} and #font[62]{|w#GT} -> #font[62]{|0#GT}");
 	TPTPaso1->AddText("");
 	TPTPaso1->AddText("Apply the #font[62]{Hadamard gate} to the #font[62]{kets} #font[62]{|x#GT}");
 	TPTPaso1->AddText("");
 	TPTPaso1->Draw();

//Texto dentro del pad2
	paso2->cd();
	TPaveText *TPTPaso2 = new TPaveText(0.001 ,0.009, 0.995, 0.995); 
 	TPTPaso2->SetTextFont(42);
	TPTPaso2->SetFillColor(kGreen-10); 
	TPTPaso2->SetShadowColor(kGray);
	TPTPaso2->SetTextAlign(12);
	TPTPaso2->SetMargin(0.04);
	TPTPaso2->AddText("");
 	TPTPaso2->AddText("#font[62]{#scale[1.7]{STEP #2}}");
 	TPTPaso2->AddText("");
 	TPTPaso2->AddText("Apply the #font[62]{U_{a,N}} gate on #font[62]{all the kets}.");
 	TPTPaso2->AddText("This gate is treated as a #font[62]{black box}, but it is clarified that");
 	TPTPaso2->AddText("it performs #font[62]{2 operations:}");
 	TPTPaso2->AddText("#font[62]{1.} Applies the function #font[62]{F_{a,N} = a^{r}(mod N)}");
 	TPTPaso2->AddText("#font[62]{2.} Introduces the #font[62]{XOR} gate, also defined as #font[62]{Modulo Sum 2}");
 	TPTPaso2->AddText("represented with the mathematical symbol #font[62]{#oplus}.");
 	TPTPaso2->AddText("");
 	TPTPaso2->Draw();

//Texto dentro del pad3
 	paso3->cd();
	TPaveText *TPTPaso3 = new TPaveText(0.001 ,0.009, 0.995, 0.995); 
 	TPTPaso3->SetTextFont(42);
	TPTPaso3->SetFillColor(kMagenta-10); 
	TPTPaso3->SetShadowColor(kGray);
	TPTPaso3->SetTextAlign(12);
	TPTPaso3->SetMargin(0.04);
	TPTPaso3->AddText("");
 	TPTPaso3->AddText("#font[62]{#scale[1.7]{STEP #3}}");
 	TPTPaso3->AddText("");
 	TPTPaso3->AddText("For step 3, the measurements resulting from the kets #font[62]{|w#GT}.");
 	TPTPaso3->AddText("Then, the #font[62]{Quantum Fourier Transform dagger} is applied over the kets #font[62]{|x#GT}.");
 	TPTPaso3->AddText("Mathematically, it is #font[62]{QFT^{+}}");
 	TPTPaso3->AddText("");
 	TPTPaso3->Draw();

//Texto dentro del pad4
 	paso4->cd();
	TPaveText *TPTPaso4 = new TPaveText(0.001 ,0.009, 0.995, 0.995); 
 	TPTPaso4->SetTextFont(42);
	TPTPaso4->SetFillColor(kCyan-10); 
	TPTPaso4->SetShadowColor(kGray);
	TPTPaso4->SetTextAlign(12);
	TPTPaso4->SetMargin(0.04);
	TPTPaso4->AddText("");
 	TPTPaso4->AddText("#font[62]{#scale[1.7]{STEP #4}}");
 	TPTPaso4->AddText("");
 	TPTPaso4->AddText("For step 4, the measurements of the #font[62]{kets} #font[62]{|x#GT} are denoted");
 	TPTPaso4->AddText("as #font[62]{M}, and each result is evaluated in the following expression #font[62]{#frac{jN}{r} = M }");
 	TPTPaso4->AddText("Here the #font[62]{quantum circuit of Shor's algorithm} concludes.");
	TPTPaso4->AddText("");
 	TPTPaso4->Draw();
 	
Circuit->Update();
Circuit->SetEditable(1);

}
/*************************************************************/
void MyMainFrame::CondCircuit(){

Int_t Valueopt1 = fComboBoxNUMSFACTORS->GetSelected();
Int_t Valueopt2 = fComboBoxVALUESA->GetSelected();

TCanvas *canvas2 = fRootEmbeddedCanvasDRAWCIRCUIT->GetCanvas();
canvas2->Clear();
canvas2->cd();

//Casos
if(Valueopt1 == 15){
  switch (Valueopt2){
     case 13:{
     	if(Breakopt==1){
	
	//Titulo
	TPaveText *Paso1_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso1_circuit->SetTextFont(62);
	Paso1_circuit->SetFillColor(kBlue-10); 
	Paso1_circuit->SetShadowColor(kGray);
	Paso1_circuit->SetMargin(0);
	Paso1_circuit->AddText("Step #1");
	Paso1_circuit->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();

	//Texto 1
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 16 therefore #color[9]{n} = 4");
	
	//Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	//Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q= 15");
	
	//Qbit|x>
	//Texto 2
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
	
	//Qbit|w>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
	
	//Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
	
	//Dibujo de los estados de los qbits 
	//Qbit|x>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.70, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.62, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.54, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.46, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.68, 0.50, 0.68);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.60, 0.50, 0.60);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.52, 0.50, 0.52);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.44, 0.50, 0.44);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
	
	//Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.30, 0.40, 0.40, 0.75); 
	Hadamard1->SetTextFont(42);
	Hadamard1->SetFillColor(kOrange-9); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#color[2]{H}");
	Hadamard1->Draw();
	
	
	//Dibujo de los estados de los qbits 
	//Qbit|w>
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.34, "#font[62]{|0#GT}");
	
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.26, "#font[62]{|0#GT}");
	
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.18, "#font[62]{|0#GT}");
	
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.10, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH9 = new TLine(0.17, 0.32, 0.50, 0.32);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
	
	lineaH10 = new TLine(0.17, 0.24, 0.50, 0.24);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	lineaH11 = new TLine(0.17, 0.16, 0.50, 0.16);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.08, 0.50, 0.08);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	//Detalles del circuito
	TPaveText *Circuit1= new TPaveText(0.60, 0.05, 0.90, 0.75); 
	Circuit1->SetTextFont(42);
	Circuit1->SetFillColor(kRed-10); 
	Circuit1->SetShadowColor(kGray);
	Circuit1->SetTextAlign(22);
	Circuit1->SetMargin(0);
	Circuit1->AddText("Due to the #font[62]{Shor's algorithm}, the kets #font[62]{|x#GT}");
	Circuit1->AddText("are defined as the number of #font[62]{n qubits}");
	Circuit1->AddText("and the kets #font[62]{|w#GT} are known as");
	Circuit1->AddText("#font[62]{auxiliary kets} and are used for");
	Circuit1->AddText("#font[62]{achieving greater precision} in the");
	Circuit1->AddText("#font[62]{result} of the #font[62]{factorization}");
	Circuit1->Draw();
	
		
        //Segundo canvas    	
     	TCanvas *ExpPaso1 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1->SetFillColor(0);
	ExpPaso1->SetEditable(1);
	ExpPaso1->Clear();
	ExpPaso1->Update();
	
	TPaveText *Paso1_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	
	Paso1_Circuito1_Exp->SetTextFont(42);
	Paso1_Circuito1_Exp->SetFillColor(0); 
	Paso1_Circuito1_Exp->SetShadowColor(kGray);
	Paso1_Circuito1_Exp->SetTextAlign(12);
	Paso1_Circuito1_Exp->SetMargin(0.01);
	Paso1_Circuito1_Exp->AddText("For #font[62]{step 1}, it is necessary to define the number of #font[62]{n qubits} to use, which should be #font[62]{the nearest and greater number than the one to be factored}.");
	Paso1_Circuito1_Exp->AddText("After obtaining #font[62]{n}, the #font[62]{kets} #font[62]{|x#GT} and #font[62]{|w#GT} are separated, note that double #font[62]{n} is taken due to #font[62]{Shor's algorithm}.");
	Paso1_Circuito1_Exp->AddText("Then, the #font[62]{Hadamard gate} is applied only to the #font[62]{kets} #font[62]{|x#GT} to create the #font[62]{equiprobable superposition states}.");
 	Paso1_Circuito1_Exp->Draw();     	
     	
     	ExpPaso1->Update();
	ExpPaso1->SetEditable(1); 
	   	
	}
	if(Breakopt==2){
      //Titulo
        TPaveText *Paso2_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso2_circuit->SetTextFont(62);
	Paso2_circuit->SetFillColor(kGreen-10); 
	Paso2_circuit->SetShadowColor(kGray);
	Paso2_circuit->SetMargin(0);
	Paso2_circuit->AddText("Step #2");
	Paso2_circuit->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
	
	//Texto 1
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 16 therefore #color[9]{n} = 4");
	
	//Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	//Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q= 15");
	
	//Qbit|x>
	//Texto 2
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
	
	//Qbit|w>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
	
	//Dibujando las lineas para definir cada ket
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
	
	//Dibujo de los estados de los qbits 
	//Qbit|x>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.70, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.62, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.54, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.46, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.68, 0.60, 0.68);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.60, 0.60, 0.60);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.52, 0.60, 0.52);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.44, 0.60, 0.44);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
	
	//Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{H}");
	Hadamard1->Draw();
	
	//Dibujo de los estados de los qbits 
	//Qbit|w>
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.34, "#font[62]{|0#GT}");
	
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.26, "#font[62]{|0#GT}");
	
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.18, "#font[62]{|0#GT}");
	
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.10, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH9 = new TLine(0.17, 0.32, 0.60, 0.32);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
	
	lineaH10 = new TLine(0.17, 0.24, 0.60, 0.24);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	lineaH11 = new TLine(0.17, 0.16, 0.60, 0.16);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.08, 0.60, 0.08);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	//Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.05, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	CompuertaU->SetFillColor(kOrange-9); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[2]{U_{a,N}}}");
	CompuertaU->Draw();
		
        //Segundo canvas    	
     	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	
	TPaveText *Paso2_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso2_Circuito1_Exp->SetTextFont(42);
	Paso2_Circuito1_Exp->SetFillColor(0); 
	Paso2_Circuito1_Exp->SetShadowColor(kGray);
	Paso2_Circuito1_Exp->SetTextAlign(12);
	Paso2_Circuito1_Exp->SetMargin(0.01);
	Paso2_Circuito1_Exp->AddText("For #font[62]{step 2}, the gate #font[62]{U_{a,N}} is applied, which affects and performs operations on all the kets to determine possible periodicity values,");
	Paso2_Circuito1_Exp->AddText("denoted as #font[62]{r}, from the function #font[62]{F = a^{r}(mod N)} in Shor's #font[62]{algorithm}. Due to the complexity of the gate #font[62]{U_{a,N}} in many cases");
	Paso2_Circuito1_Exp->AddText("it is treated as a #font[62]{black box}, and its explanations are often unclear. It is recommended to review #font[62]{modular algebra} and the operations performed in the");
	Paso2_Circuito1_Exp->AddText("tabs #font[62]{CLASSICAL} and #font[62]{QUANTUM} to compare the procedures that the gate performs on the #font[62]{qubits}.");
 	Paso2_Circuito1_Exp->Draw();     	
     	
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(1); 
   
	}
	if(Breakopt==3){
	
	//Titulo
        TPaveText *Paso3_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_circuit->SetTextFont(62);
	Paso3_circuit->SetFillColor(kMagenta-10); 
	Paso3_circuit->SetShadowColor(kGray);
	Paso3_circuit->SetMargin(0);
	Paso3_circuit->AddText("Step #3");
	Paso3_circuit->Draw();
	
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
	
	//Texto 1
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 16 therefore #color[9]{n} = 4");
	
	//Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	//Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q= 15");
	
	//Qbit|x>
	//Texto 2
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
	
	//Qbit|w>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
	
	//Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
	
	//Dibujo de los estados de los qbits 
	//Qbit|x>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.70, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.62, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.54, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.46, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.68, 0.80, 0.68);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.60, 0.80, 0.60);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.52, 0.80, 0.52);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.44, 0.80, 0.44);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
	
	//Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{H}");
	Hadamard1->Draw();
	
	
	//Dibujo de los estados de los qbits 
	//Qbit|w>
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.34, "#font[62]{|0#GT}");
	
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.26, "#font[62]{|0#GT}");
	
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.18, "#font[62]{|0#GT}");
	
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.10, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH9 = new TLine(0.17, 0.32, 0.60, 0.32);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
	
	lineaH10 = new TLine(0.17, 0.24, 0.60, 0.24);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	lineaH11 = new TLine(0.17, 0.16, 0.60, 0.16);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.08, 0.60, 0.08);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	//Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.05, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	CompuertaU->SetFillColor(kGray); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[1]{U_{a,N}}}");
	CompuertaU->Draw();
	
	//Compuerta de medida de|w>
	TPaveText *Medidaw= new TPaveText(0.52, 0.05, 0.62, 0.38); 
	Medidaw->SetTextFont(42);
	Medidaw->SetFillColor(kOrange-9); 
	Medidaw->SetShadowColor(1);
	Medidaw->SetMargin(0);
	Medidaw->AddText("");
	Medidaw->Draw();
	
	//Para el simbolo de medida
        Double_t xCenter = 0.57;  
        Double_t yCenter = 0.21;  
        Double_t radius = 0.04;   
    
        //Dibujar el circulo 
 	TEllipse *circle = new TEllipse(xCenter, yCenter, 0.03, 0.06, 0, 360);  
        circle->SetLineColor(2);  
        circle->SetLineWidth(2);
        circle->SetFillColor(kOrange-9);  
        circle->Draw();
	
	//Flechas
	flecha2 = new TArrow(0.57, 0.21, 0.59, 0.29, 0.01, ">");
	flecha2->SetLineColor(2);
     	flecha2->SetLineWidth(2);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
	
	//Cuadro para ocultar la mitad del circulo
	TPaveText *ocultar1= new TPaveText(0.5299999, 0.05, 0.62, 0.21); 
	ocultar1->SetTextFont(42);
	ocultar1->SetLineWidth(0);  
	ocultar1->SetFillColor(kOrange-9); 
	ocultar1->SetShadowColor(1);
	ocultar1->SetMargin(0);
	ocultar1->AddText("");
	ocultar1->Draw();
	
	
	//Cuadro para QFT+
	TPaveText *QFT= new TPaveText(0.64, 0.40, 0.73, 0.75); 
	QFT->SetTextFont(42);
	QFT->SetFillColor(kOrange-9); 
	QFT->SetShadowColor(1);
	QFT->SetMargin(0);
	QFT->AddText("#font[62]{#color[2]{QFT^{+}}}");
	QFT->Draw();
		
        //Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso3_Circuito1_Exp->SetTextFont(42);
	Paso3_Circuito1_Exp->SetFillColor(0); 
	Paso3_Circuito1_Exp->SetShadowColor(kGray);
	Paso3_Circuito1_Exp->SetTextAlign(12);
	Paso3_Circuito1_Exp->SetMargin(0.01);
	Paso3_Circuito1_Exp->AddText("For #font[62]{step 3}, the measurements of the kets #font[62]{|w#GT} are first obtained, and then the #font[62]{Conjugate Transposed Quantum Fourier Transform} is performed");
	Paso3_Circuito1_Exp->AddText("or denoted as #font[62]{QFT^{+}} on the kets #font[62]{|x#GT}");
	Paso3_Circuito1_Exp->AddText("For the explanation of the #font[62]{QFT}, it is recommended to study another interface focused on its teaching, called #font[62]{QFTSoftEdu}, which belongs to");
	Paso3_Circuito1_Exp->AddText("#font[62]{FISINFOR} and developed by #font[62]{Ingrid Daiana Cuevas Ruiz}, a physics graduate from the #font[62]{Universidad Distrital}");
 	Paso3_Circuito1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1);   	
	
	}
	if(Breakopt==4){
	//Titulo
	TPaveText *Paso4_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso4_circuit->SetTextFont(62);
	Paso4_circuit->SetFillColor(kCyan-10); 
	Paso4_circuit->SetShadowColor(kGray);
	Paso4_circuit->SetMargin(0);
	Paso4_circuit->AddText("Step #4");
	Paso4_circuit->Draw();
		
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
	
	//Texto 1
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 16 therefore #color[9]{n} = 4");
	
	//Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	//Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q= 15");
	
	//Qbit|x>
	//Texto 2
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
	
	//Qbit|w>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
	
	//Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
	
	//Dibujo de los estados de los qbits 
	//Qbit|x>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.70, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.62, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.54, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.46, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.68, 0.80, 0.68);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.60, 0.80, 0.60);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.52, 0.80, 0.52);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.44, 0.80, 0.44);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
	
	//Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{H}");
	Hadamard1->Draw();
	
	
	//Dibujo de los estados de los qbits 
	//Qbit|w>
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.34, "#font[62]{|0#GT}");
	
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.26, "#font[62]{|0#GT}");
	
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.18, "#font[62]{|0#GT}");
	
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.10, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH9 = new TLine(0.17, 0.32, 0.60, 0.32);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
	
	lineaH10 = new TLine(0.17, 0.24, 0.60, 0.24);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	lineaH11 = new TLine(0.17, 0.16, 0.60, 0.16);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.08, 0.60, 0.08);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	//Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.05, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	
	CompuertaU->SetFillColor(kGray); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[1]{U_{a,N}}}");
	CompuertaU->Draw();
	
	//Compuerta de medida de|w>
	TPaveText *Medidaw= new TPaveText(0.52, 0.05, 0.62, 0.38); 
	Medidaw->SetTextFont(42);
	
	Medidaw->SetFillColor(kGray); 
	Medidaw->SetShadowColor(1);
	Medidaw->SetMargin(0);
	Medidaw->AddText("");
	Medidaw->Draw();
      //Dibujar el circulo 
 	TEllipse *circle = new TEllipse(0.57, 0.21, 0.03, 0.06, 0, 360);  
        circle->SetLineColor(1);  
        circle->SetLineWidth(2);
        circle->SetFillColor(kGray);  
        circle->Draw();
	
	//Flechas
	flecha2 = new TArrow(0.57, 0.21, 0.59, 0.29, 0.01, ">");
	flecha2->SetLineColor(1);
     	flecha2->SetLineWidth(2);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
	
	//Cuadro para ocultar la mitad del circulo
	TPaveText *ocultar1= new TPaveText(0.5299999, 0.05, 0.62, 0.21); 
	ocultar1->SetTextFont(42);
	
	ocultar1->SetLineWidth(0);  
	ocultar1->SetFillColor(kGray); 
	ocultar1->SetShadowColor(1);
	ocultar1->SetMargin(0);
	ocultar1->AddText("");
	ocultar1->Draw();
	
	
	//Cuadro para QFT+
	TPaveText *QFT= new TPaveText(0.64, 0.40, 0.73, 0.75); 
	QFT->SetTextFont(42);
	QFT->SetFillColor(kGray); 
	QFT->SetShadowColor(1);
	QFT->SetMargin(0);
	QFT->AddText("#font[62]{QFT^{+}}");
	QFT->Draw();
	
	//medida|x>
	TPaveText *medidax= new TPaveText(0.77, 0.40, 0.87, 0.75); 
	medidax->SetTextFont(42);
	 
	medidax->SetFillColor(kOrange-9); 
	medidax->SetShadowColor(1);
	medidax->SetMargin(0);
	medidax->AddText("");
	medidax->Draw();
	
	//Diagrama de medida de x
	// Dibujar el circulo 
        circle1 = new TEllipse(0.82, 0.59, 0.03, 0.06, 0, 360);  
        circle1->SetLineColor(2);  
        circle1->SetLineWidth(2);
        circle1->SetFillColor(kOrange-9);  
        circle1->Draw();
	
	//Flechas
	flecha3 = new TArrow(0.82, 0.59, 0.85, 0.67, 0.01, ">");
	flecha3->SetLineColor(2);
     	flecha3->SetLineWidth(2);
     	flecha3->SetLineStyle(1);
     	flecha3->Draw();
	
	//Cuadro para ocultar la mitad del circulo 2
	TPaveText *ocultar2= new TPaveText(0.78, 0.40, 0.87, 0.59); 
	ocultar2->SetTextFont(42);
	ocultar2->SetLineWidth(0);  
	ocultar2->SetFillColor(kOrange-9); 
	ocultar2->SetShadowColor(1);
	ocultar2->SetMargin(0);
	ocultar2->AddText("");
	ocultar2->Draw();
		
        //Segundo canvas    	
     	TCanvas *ExpPaso4 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso4->SetFillColor(0);
	ExpPaso4->SetEditable(1);
	ExpPaso4->Clear();
	ExpPaso4->Update();
	
	TPaveText *Paso4_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	
	Paso4_Circuito1_Exp->SetTextFont(42);
	Paso4_Circuito1_Exp->SetFillColor(0); 
	Paso4_Circuito1_Exp->SetShadowColor(kGray);
	Paso4_Circuito1_Exp->SetTextAlign(12);
	Paso4_Circuito1_Exp->SetMargin(0.01);
	Paso4_Circuito1_Exp->AddText("For #font[62]{step 4}, the measurement of the kets #font[62]{|x#GT} is performed, and at this point, the circuit is complete. To resolve any questions about the procedures");
	Paso4_Circuito1_Exp->AddText("for each gate, you can study the different cases, and if the doubt persists, then go to the #font[62]{CLEAR} button and then #font[62]{CONCEPTS}");
	Paso4_Circuito1_Exp->AddText("where you will find definitions of the concepts used in the #font[62]{Shor's algorithm} in a more basic and detailed manner for better understanding.");
 	Paso4_Circuito1_Exp->Draw();     	
     	
     	ExpPaso4->Update();
	ExpPaso4->SetEditable(1); 
	  
	}
	}
	if(Breakopt == 5){
     	fTextButtonBACK->SetState(kButtonUp, kTRUE);
     	fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
     	DoCircuit();
     	CambioTab(1);
     	}
	break; 
	
     case 14:{
        if(Breakopt==1){

//Titulo
	TPaveText *Paso1_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso1_circuit->SetTextFont(62);
	Paso1_circuit->SetFillColor(kBlue-10); 
	Paso1_circuit->SetShadowColor(kGray);
	Paso1_circuit->SetMargin(0);
	Paso1_circuit->AddText("Step #1");
	Paso1_circuit->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();

	//Texto 1
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 16 therefore #color[9]{n} = 4");
	
	//Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	//Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q= 15");
	
	//Qbit|x>
	//Texto 2
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
	
	//Qbit|w>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
	
	//Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
	
	//Dibujo de los estados de los qbits 
	//Qbit|x>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.70, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.62, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.54, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.46, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.68, 0.50, 0.68);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.60, 0.50, 0.60);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.52, 0.50, 0.52);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.44, 0.50, 0.44);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
	
	//Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.30, 0.40, 0.40, 0.75); 
	Hadamard1->SetTextFont(42);
	
	Hadamard1->SetFillColor(kOrange-9); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#color[2]{H}");
	Hadamard1->Draw();
	
	
	//Dibujo de los estados de los qbits 
	//Qbit|w>
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.34, "#font[62]{|0#GT}");
	
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.26, "#font[62]{|0#GT}");
	
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.18, "#font[62]{|0#GT}");
	
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.10, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH9 = new TLine(0.17, 0.32, 0.50, 0.32);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
	
	lineaH10 = new TLine(0.17, 0.24, 0.50, 0.24);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	lineaH11 = new TLine(0.17, 0.16, 0.50, 0.16);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.08, 0.50, 0.08);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	//Detalles del circuito
	TPaveText *Circuit1= new TPaveText(0.60, 0.05, 0.90, 0.75); 
	Circuit1->SetTextFont(42);
	Circuit1->SetFillColor(kRed-10); 
	Circuit1->SetShadowColor(kGray);
	Circuit1->SetTextAlign(22);
	Circuit1->SetMargin(0);
	Circuit1->AddText("Due to the #font[62]{Shor's algorithm}, the kets #font[62]{|x#GT}");
	Circuit1->AddText("are defined as the number of #font[62]{n qubits}");
	Circuit1->AddText("and the kets #font[62]{|w#GT} are known as");
	Circuit1->AddText("#font[62]{auxiliary kets} and are used for");
	Circuit1->AddText("#font[62]{achieving greater precision} in the");
	Circuit1->AddText("#font[62]{result} of the #font[62]{factorization}");
	Circuit1->Draw();
		
        //Segundo canvas    	
     	TCanvas *ExpPaso1 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1->SetFillColor(0);
	ExpPaso1->SetEditable(1);
	ExpPaso1->Clear();
	ExpPaso1->Update();
	
	TPaveText *Paso1_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso1_Circuito1_Exp->SetTextFont(42);
	Paso1_Circuito1_Exp->SetFillColor(0); 
	Paso1_Circuito1_Exp->SetShadowColor(kGray);
	Paso1_Circuito1_Exp->SetTextAlign(12);
	Paso1_Circuito1_Exp->SetMargin(0.01);
	Paso1_Circuito1_Exp->AddText("For #font[62]{step 1}, it is necessary to define the number of #font[62]{n qubits} to use, which should be #font[62]{the nearest and greater number than the one to be factored}.");
	Paso1_Circuito1_Exp->AddText("After obtaining #font[62]{n}, the #font[62]{kets} #font[62]{|x#GT} and #font[62]{|w#GT} are separated, note that double #font[62]{n} is taken due to #font[62]{Shor's algorithm}.");
	Paso1_Circuito1_Exp->AddText("Then, the #font[62]{Hadamard gate} is applied only to the #font[62]{kets} #font[62]{|x#GT} to create the #font[62]{equiprobable superposition states}.");
 	Paso1_Circuito1_Exp->Draw();     	
     	
     	ExpPaso1->Update();
	ExpPaso1->SetEditable(1);        

        }
     	if(Breakopt==2){
	        
	//Titulo
        TPaveText *Paso2_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso2_circuit->SetTextFont(62);
	Paso2_circuit->SetFillColor(kGreen-10); 
	Paso2_circuit->SetShadowColor(kGray);
	Paso2_circuit->SetMargin(0);
	Paso2_circuit->AddText("Step #2");
	Paso2_circuit->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
	
	//Texto 1
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 16 therefore #color[9]{n} = 4");
	
	//Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	//Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q= 15");
	
	//Qbit|x>
	//Texto 2
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
	
	//Qbit|w>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
	
	//Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
	
	//Dibujo de los estados de los qbits 
	//Qbit|x>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.70, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.62, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.54, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.46, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.68, 0.60, 0.68);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.60, 0.60, 0.60);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.52, 0.60, 0.52);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.44, 0.60, 0.44);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
	
	//Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{H}");
	Hadamard1->Draw();
	
	
	//Dibujo de los estados de los qbits 
	//Qbit|w>
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.34, "#font[62]{|0#GT}");
	
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.26, "#font[62]{|0#GT}");
	
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.18, "#font[62]{|0#GT}");
	
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.10, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH9 = new TLine(0.17, 0.32, 0.60, 0.32);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
	
	lineaH10 = new TLine(0.17, 0.24, 0.60, 0.24);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	lineaH11 = new TLine(0.17, 0.16, 0.60, 0.16);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.08, 0.60, 0.08);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	//Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.05, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	CompuertaU->SetFillColor(kOrange-9); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[2]{U_{a,N}}}");
	CompuertaU->Draw();
		
        //Segundo canvas    	
     	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	TPaveText *Paso2_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso2_Circuito1_Exp->SetTextFont(42);
	Paso2_Circuito1_Exp->SetFillColor(0); 
	Paso2_Circuito1_Exp->SetShadowColor(kGray);
	Paso2_Circuito1_Exp->SetTextAlign(12);
	Paso2_Circuito1_Exp->SetMargin(0.01);
	Paso2_Circuito1_Exp->AddText("For #font[62]{step 2}, the gate #font[62]{U_{a,N}} is applied, which affects and performs operations on all the kets to determine possible periodicity values,");
	Paso2_Circuito1_Exp->AddText("denoted as #font[62]{r}, from the function #font[62]{F = a^{r}(mod N)} in Shor's #font[62]{algorithm}. Due to the complexity of the gate #font[62]{U_{a,N}} in many cases");
	Paso2_Circuito1_Exp->AddText("it is treated as a #font[62]{black box}, and its explanations are often unclear. It is recommended to review #font[62]{modular algebra} and the operations performed in the");
	Paso2_Circuito1_Exp->AddText("tabs #font[62]{CLASSICAL} and #font[62]{QUANTUM} to compare the procedures that the gate performs on the #font[62]{qubits}.");
 	Paso2_Circuito1_Exp->Draw();     	
     	
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(1);        
      }
     	if(Breakopt==3){
      //Titulo
        TPaveText *Paso3_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_circuit->SetTextFont(62);
	Paso3_circuit->SetFillColor(kMagenta-10); 
	Paso3_circuit->SetShadowColor(kGray);
	Paso3_circuit->SetMargin(0);
	Paso3_circuit->AddText("Step #3");
	Paso3_circuit->Draw();
	
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
	
	//Texto 1
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 16 therefore #color[9]{n} = 4");
	
	//Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	//Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q= 15");
	
	//Qbit|x>
	//Texto 2
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
	
	//Qbit|w>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
	
	//Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
	
	//Dibujo de los estados de los qbits 
	//Qbit|x>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.70, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.62, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.54, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.46, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.68, 0.80, 0.68);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.60, 0.80, 0.60);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.52, 0.80, 0.52);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.44, 0.80, 0.44);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
	
	//Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{H}");
	Hadamard1->Draw();
	
	//Dibujo de los estados de los qbits 
	//Qbit|w>
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.34, "#font[62]{|0#GT}");
	
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.26, "#font[62]{|0#GT}");
	
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.18, "#font[62]{|0#GT}");
	
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.10, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH9 = new TLine(0.17, 0.32, 0.60, 0.32);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
	
	lineaH10 = new TLine(0.17, 0.24, 0.60, 0.24);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	lineaH11 = new TLine(0.17, 0.16, 0.60, 0.16);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.08, 0.60, 0.08);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	//Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.05, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	CompuertaU->SetFillColor(kGray); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[1]{U_{a,N}}}");
	CompuertaU->Draw();
	
	//Compuerta de medida de|w>
	TPaveText *Medidaw= new TPaveText(0.52, 0.05, 0.62, 0.38); 
	Medidaw->SetTextFont(42);
	Medidaw->SetFillColor(kOrange-9); 
	Medidaw->SetShadowColor(1);
	Medidaw->SetMargin(0);
	Medidaw->AddText("");
	Medidaw->Draw();
	
	//Para el simbolo de medida
        Double_t xCenter = 0.57;  
        Double_t yCenter = 0.21;  
        Double_t radius = 0.04;   
    
        //Dibujar el circulo 
 	TEllipse *circle = new TEllipse(xCenter, yCenter, 0.03, 0.06, 0, 360);  
        circle->SetLineColor(2);  
        circle->SetLineWidth(2);
        circle->SetFillColor(kOrange-9);  
        circle->Draw();
	
	//Flechas
	flecha2 = new TArrow(0.57, 0.21, 0.59, 0.29, 0.01, ">");
	flecha2->SetLineColor(2);
     	flecha2->SetLineWidth(2);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
	
	//Cuadro para ocultar la mitad del circulo
	TPaveText *ocultar1= new TPaveText(0.5299999, 0.05, 0.62, 0.21); 
	ocultar1->SetTextFont(42);
	ocultar1->SetLineWidth(0);  
	ocultar1->SetFillColor(kOrange-9); 
	ocultar1->SetShadowColor(1);
	ocultar1->SetMargin(0);
	ocultar1->AddText("");
	ocultar1->Draw();
	
	//Cuadro para QFT+
	TPaveText *QFT= new TPaveText(0.64, 0.40, 0.73, 0.75); 
	QFT->SetTextFont(42);
	QFT->SetFillColor(kOrange-9); 
	QFT->SetShadowColor(1);
	QFT->SetMargin(0);
	QFT->AddText("#font[62]{#color[2]{QFT^{+}}}");
	QFT->Draw();
		
        //Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	TPaveText *Paso3_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso3_Circuito1_Exp->SetTextFont(42);
	Paso3_Circuito1_Exp->SetFillColor(0); 
	Paso3_Circuito1_Exp->SetShadowColor(kGray);
	Paso3_Circuito1_Exp->SetTextAlign(12);
	Paso3_Circuito1_Exp->SetMargin(0.01);
	Paso3_Circuito1_Exp->AddText("For #font[62]{step 3}, the measurements of the kets #font[62]{|w#GT} are first obtained, and then the #font[62]{Conjugate Transposed Quantum Fourier Transform} is performed");
	Paso3_Circuito1_Exp->AddText("or denoted as #font[62]{QFT^{+}} on the kets #font[62]{|x#GT}");
	Paso3_Circuito1_Exp->AddText("For the explanation of the #font[62]{QFT}, it is recommended to study another interface focused on its teaching, called #font[62]{QFTSoftEdu}, which belongs to");
	Paso3_Circuito1_Exp->AddText("#font[62]{FISINFOR} and developed by #font[62]{Ingrid Daiana Cuevas Ruiz}, a physics graduate from the #font[62]{Universidad Distrital}");
	Paso3_Circuito1_Exp->Draw();     	
    
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1); 
      }
        if(Breakopt==4){
      //Titulo
	TPaveText *Paso4_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso4_circuit->SetTextFont(62);
	Paso4_circuit->SetFillColor(kCyan-10); 
	Paso4_circuit->SetShadowColor(kGray);
	Paso4_circuit->SetMargin(0);
	Paso4_circuit->AddText("Step #4");
	Paso4_circuit->Draw();
	
		
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
	
	//Texto 1
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 16 therefore #color[9]{n} = 4");
	
	//Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	//Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q= 15");
	
	//Qbit|x>
	//Texto 2
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
	
	//Qbit|w>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
	
	//Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
	
	//Dibujo de los estados de los qbits 
	//Qbit|x>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.70, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.62, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.54, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.46, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.68, 0.80, 0.68);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.60, 0.80, 0.60);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.52, 0.80, 0.52);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.44, 0.80, 0.44);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
	
	//Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{H}");
	Hadamard1->Draw();
	
	
	//Dibujo de los estados de los qbits 
	//Qbit|w>
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.34, "#font[62]{|0#GT}");
	
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.26, "#font[62]{|0#GT}");
	
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.18, "#font[62]{|0#GT}");
	
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.10, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH9 = new TLine(0.17, 0.32, 0.60, 0.32);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
	
	lineaH10 = new TLine(0.17, 0.24, 0.60, 0.24);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	lineaH11 = new TLine(0.17, 0.16, 0.60, 0.16);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.08, 0.60, 0.08);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	//Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.05, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	CompuertaU->SetFillColor(kGray); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[1]{U_{a,N}}}");
	CompuertaU->Draw();
	
	//Compuerta de medida de|w>
	TPaveText *Medidaw= new TPaveText(0.52, 0.05, 0.62, 0.38); 
	Medidaw->SetTextFont(42);
	Medidaw->SetFillColor(kGray); 
	Medidaw->SetShadowColor(1);
	Medidaw->SetMargin(0);
	Medidaw->AddText("");
	Medidaw->Draw();
 
        //Dibujar el circulo 
 	TEllipse *circle = new TEllipse(0.57, 0.21, 0.03, 0.06, 0, 360);  
        circle->SetLineColor(1);  
        circle->SetLineWidth(2);
        circle->SetFillColor(kGray);  
        circle->Draw();
	
	//Flechas
	flecha2 = new TArrow(0.57, 0.21, 0.59, 0.29, 0.01, ">");
	flecha2->SetLineColor(1);
     	flecha2->SetLineWidth(2);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
	
	//Cuadro para ocultar la mitad del circulo
	TPaveText *ocultar1= new TPaveText(0.5299999, 0.05, 0.62, 0.21); 
	ocultar1->SetTextFont(42);
	ocultar1->SetLineWidth(0);  
	ocultar1->SetFillColor(kGray); 
	ocultar1->SetShadowColor(1);
	ocultar1->SetMargin(0);
	ocultar1->AddText("");
	ocultar1->Draw();
	
	
	//Cuadro para QFT+
	TPaveText *QFT= new TPaveText(0.64, 0.40, 0.73, 0.75); 
	QFT->SetTextFont(42);
	QFT->SetFillColor(kGray); 
	QFT->SetShadowColor(1);
	QFT->SetMargin(0);
	QFT->AddText("#font[62]{QFT^{+}}");
	QFT->Draw();
	
	//medida|x>
	TPaveText *medidax= new TPaveText(0.77, 0.40, 0.87, 0.75); 
	medidax->SetTextFont(42);
	 
	medidax->SetFillColor(kOrange-9); 
	medidax->SetShadowColor(1);
	medidax->SetMargin(0);
	medidax->AddText("");
	medidax->Draw();
	
	//Diagrama de medida de x
	// Dibujar el circulo 
        circle1 = new TEllipse(0.82, 0.59, 0.03, 0.06, 0, 360);  
        circle1->SetLineColor(2);  
        circle1->SetLineWidth(2);
        circle1->SetFillColor(kOrange-9);  
        circle1->Draw();
	
	//Flechas
	flecha3 = new TArrow(0.82, 0.59, 0.85, 0.67, 0.01, ">");
	flecha3->SetLineColor(2);
     	flecha3->SetLineWidth(2);
     	flecha3->SetLineStyle(1);
     	flecha3->Draw();
	
	//Cuadro para ocultar la mitad del circulo 2
	TPaveText *ocultar2= new TPaveText(0.78, 0.40, 0.87, 0.59); 
	ocultar2->SetTextFont(42);
	ocultar2->SetLineWidth(0);  
	ocultar2->SetFillColor(kOrange-9); 
	ocultar2->SetShadowColor(1);
	ocultar2->SetMargin(0);
	ocultar2->AddText("");
	ocultar2->Draw();
		
        //Segundo canvas    	
     	TCanvas *ExpPaso4 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso4->SetFillColor(0);
	ExpPaso4->SetEditable(1);
	ExpPaso4->Clear();
	ExpPaso4->Update();
	TPaveText *Paso4_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso4_Circuito1_Exp->SetTextFont(42);
	Paso4_Circuito1_Exp->SetFillColor(0); 
	Paso4_Circuito1_Exp->SetShadowColor(kGray);
	Paso4_Circuito1_Exp->SetTextAlign(12);
	Paso4_Circuito1_Exp->SetMargin(0.01);
	Paso4_Circuito1_Exp->AddText("For #font[62]{step 4}, the measurement of the kets #font[62]{|x#GT} is performed, and at this point, the circuit is complete. To resolve any questions about the procedures");
	Paso4_Circuito1_Exp->AddText("for each gate, you can study the different cases, and if the doubt persists, then go to the #font[62]{CLEAR} button and then #font[62]{CONCEPTS}");
	Paso4_Circuito1_Exp->AddText("where you will find definitions of the concepts used in the #font[62]{Shor's algorithm} in a more basic and detailed manner for better understanding.");
 	Paso4_Circuito1_Exp->Draw();     	
     	
     	ExpPaso4->Update();
	ExpPaso4->SetEditable(1); 
      }
     }
     	if(Breakopt == 5){
     	fTextButtonBACK->SetState(kButtonUp, kTRUE);
     	fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
     	DoCircuit();
     	CambioTab(1);
     	} 
     break;        
  }
}

if(Valueopt1 == 21){
  switch (Valueopt2){
      case 2:{
       if(Breakopt==1){
      //Titulo
	TPaveText *Paso1_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso1_circuit->SetTextFont(62);
	Paso1_circuit->SetFillColor(kBlue-10); 
	Paso1_circuit->SetShadowColor(kGray);
	Paso1_circuit->SetMargin(0);
	Paso1_circuit->AddText("Step #1");
	Paso1_circuit->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();

        //Texto 1
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 21 therefore #color[9]{n} = 5");
      //Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
     	
     	//Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q = 21");
     	
        //Qbit|x>
	//Texto 2
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
	
	//Qbit|w>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
      //Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|x>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.72, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.66, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.59, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.52, "#font[62]{|0#GT}");
        
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.45, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.70, 0.50, 0.70);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.64, 0.50, 0.64);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.57, 0.50, 0.57);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.50, 0.50, 0.50);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
      lineaH9 = new TLine(0.17, 0.43, 0.50, 0.43);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
      //Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.30, 0.40, 0.40, 0.75); 
	Hadamard1->SetTextFont(42);
	Hadamard1->SetFillColor(kOrange-9); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#color[2]{H}");
	Hadamard1->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|w>
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.36, "#font[62]{|0#GT}");
        
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.29, "#font[62]{|0#GT}");
	
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.22, "#font[62]{|0#GT}");
        
	l12->SetTextFont(42); 
	l12->SetTextColor(1);
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.14, 0.14, "#font[62]{|0#GT}");
        
	l13->SetTextFont(42); 
	l13->SetTextColor(1);
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.14, 0.07, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH10 = new TLine(0.17, 0.34, 0.50, 0.34);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	lineaH11 = new TLine(0.17, 0.27, 0.50, 0.27);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.20, 0.50, 0.20);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	lineaH13 = new TLine(0.17, 0.12, 0.50, 0.12);
	lineaH13->SetLineColor(kBlack);
	lineaH13->Draw();
	
	lineaH14 = new TLine(0.17, 0.05, 0.50, 0.05);
	lineaH14->SetLineColor(kBlack);
	lineaH14->Draw();
	
	//Detalles del circuito
	TPaveText *Circuit1= new TPaveText(0.60, 0.05, 0.90, 0.75); 
	Circuit1->SetTextFont(42);
	Circuit1->SetFillColor(kRed-10); 
	Circuit1->SetShadowColor(kGray);
	Circuit1->SetTextAlign(22);
	Circuit1->SetMargin(0);
	Circuit1->AddText("Due to the #font[62]{Shor's algorithm}, the kets #font[62]{|x#GT}");
	Circuit1->AddText("are defined as the number of #font[62]{n qubits}");
	Circuit1->AddText("and the kets #font[62]{|w#GT} are known as");
	Circuit1->AddText("#font[62]{auxiliary kets} and are used for");
	Circuit1->AddText("#font[62]{achieving greater precision} in the");
	Circuit1->AddText("#font[62]{result} of the #font[62]{factorization}");
	Circuit1->Draw();
	
	//Segundo canvas    	
     	TCanvas *ExpPaso1 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1->SetFillColor(0);
	ExpPaso1->SetEditable(1);
	ExpPaso1->Clear();
	ExpPaso1->Update();
	
	TPaveText *Paso1_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso1_Circuito1_Exp->SetTextFont(42);
	Paso1_Circuito1_Exp->SetFillColor(0); 
	Paso1_Circuito1_Exp->SetShadowColor(kGray);
	Paso1_Circuito1_Exp->SetTextAlign(12);
	Paso1_Circuito1_Exp->SetMargin(0.01);
	Paso1_Circuito1_Exp->AddText("For #font[62]{step 1}, it is necessary to define the number of #font[62]{n qubits} to use, which should be #font[62]{the nearest and greater number than the one to be factored}.");
	Paso1_Circuito1_Exp->AddText("After obtaining #font[62]{n}, the #font[62]{kets} #font[62]{|x#GT} and #font[62]{|w#GT} are separated, note that double #font[62]{n} is taken due to #font[62]{Shor's algorithm}.");
	Paso1_Circuito1_Exp->AddText("Then, the #font[62]{Hadamard gate} is applied only to the #font[62]{kets} #font[62]{|x#GT} to create the #font[62]{equiprobable superposition states}.");
 	Paso1_Circuito1_Exp->Draw();     	
     	
     	ExpPaso1->Update();
	ExpPaso1->SetEditable(1); 
      } 
       if(Breakopt==2){
        //Titulo
        TPaveText *Paso2_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso2_circuit->SetTextFont(62);
	Paso2_circuit->SetFillColor(kGreen-10); 
	Paso2_circuit->SetShadowColor(kGray);
	Paso2_circuit->SetMargin(0);
	Paso2_circuit->AddText("Step #2");
	Paso2_circuit->Draw();
      //Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
      //Texto 1
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 21 therefore #color[9]{n} = 5");
      //Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
      //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q = 21");
      //Qbit|x>
	//Texto 2
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
      //Qbit|w>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
       //Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|x>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.72, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.66, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.59, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.52, "#font[62]{|0#GT}");
       
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.45, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.70, 0.50, 0.70);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.64, 0.50, 0.64);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.57, 0.50, 0.57);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.50, 0.50, 0.50);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
      lineaH9 = new TLine(0.17, 0.43, 0.50, 0.43);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
      //Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{#color[1]{H}}");
	Hadamard1->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|w>
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.36, "#font[62]{|0#GT}");
        
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.29, "#font[62]{|0#GT}");
	
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.22, "#font[62]{|0#GT}");
       
	l12->SetTextFont(42); 
	l12->SetTextColor(1);
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.14, 0.14, "#font[62]{|0#GT}");
         
	l13->SetTextFont(42); 
	l13->SetTextColor(1);
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.14, 0.07, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH10 = new TLine(0.17, 0.34, 0.50, 0.34);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	lineaH11 = new TLine(0.17, 0.27, 0.50, 0.27);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.20, 0.50, 0.20);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	lineaH13 = new TLine(0.17, 0.12, 0.50, 0.12);
	lineaH13->SetLineColor(kBlack);
	lineaH13->Draw();
	
	lineaH14 = new TLine(0.17, 0.05, 0.50, 0.05);
	lineaH14->SetLineColor(kBlack);
	lineaH14->Draw();
      //Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.03, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	CompuertaU->SetFillColor(kOrange-9); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[2]{U_{a,N}}}");
	CompuertaU->Draw();
		
        //Segundo canvas    	
     	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	TPaveText *Paso2_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso2_Circuito1_Exp->SetTextFont(42);
	Paso2_Circuito1_Exp->SetFillColor(0); 
	Paso2_Circuito1_Exp->SetShadowColor(kGray);
	Paso2_Circuito1_Exp->SetTextAlign(12);
	Paso2_Circuito1_Exp->SetMargin(0.01);
	Paso2_Circuito1_Exp->AddText("For #font[62]{step 2}, the gate #font[62]{U_{a,N}} is applied, which affects and performs operations on all the kets to determine possible periodicity values,");
	Paso2_Circuito1_Exp->AddText("denoted as #font[62]{r}, from the function #font[62]{F = a^{r}(mod N)} in Shor's #font[62]{algorithm}. Due to the complexity of the gate #font[62]{U_{a,N}} in many cases");
	Paso2_Circuito1_Exp->AddText("it is treated as a #font[62]{black box}, and its explanations are often unclear. It is recommended to review #font[62]{modular algebra} and the operations performed in the");
	Paso2_Circuito1_Exp->AddText("tabs #font[62]{CLASSICAL} and #font[62]{QUANTUM} to compare the procedures that the gate performs on the #font[62]{qubits}.");
 	Paso2_Circuito1_Exp->Draw();     	
     	
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(1);   
       
        } 
        if(Breakopt==3){
 
        //Titulo
        TPaveText *Paso3_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_circuit->SetTextFont(62);
	Paso3_circuit->SetFillColor(kMagenta-10); 
	Paso3_circuit->SetShadowColor(kGray);
	Paso3_circuit->SetMargin(0);
	Paso3_circuit->AddText("Step #3");
	Paso3_circuit->Draw();
      //Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
      //Texto 1
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 21 therefore #color[9]{n} = 5");
      //Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
      //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q = 21");
      //Qbit|x>
	//Texto 2
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
      //Qbit|w>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
      //Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
      
        //Dibujo de los estados de los qbits 
	//Qbit|x>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.72, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.66, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.59, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.52, "#font[62]{|0#GT}");
       
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.45, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.70, 0.80, 0.70);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.64, 0.80, 0.64);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.57, 0.80, 0.57);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.50, 0.80, 0.50);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
      lineaH9 = new TLine(0.17, 0.43, 0.80, 0.43);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
      //Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{#color[1]{H}}");
	Hadamard1->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|w>
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.36, "#font[62]{|0#GT}");
        
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.29, "#font[62]{|0#GT}");
	
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.22, "#font[62]{|0#GT}");
	
	l12->SetTextFont(42); 
	l12->SetTextColor(1);
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.14, 0.14, "#font[62]{|0#GT}");
        
	l13->SetTextFont(42); 
	l13->SetTextColor(1);
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.14, 0.07, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH10 = new TLine(0.17, 0.34, 0.60, 0.34);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	lineaH11 = new TLine(0.17, 0.27, 0.60, 0.27);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.20, 0.60, 0.20);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	lineaH13 = new TLine(0.17, 0.12, 0.60, 0.12);
	lineaH13->SetLineColor(kBlack);
	lineaH13->Draw();
	
	lineaH14 = new TLine(0.17, 0.05, 0.60, 0.05);
	lineaH14->SetLineColor(kBlack);
	lineaH14->Draw();
      //Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.03, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	CompuertaU->SetFillColor(kGray); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[1]{U_{a,N}}}");
	CompuertaU->Draw();
      //Compuerta de medida de|w>
	TPaveText *Medidaw= new TPaveText(0.52, 0.05, 0.62, 0.38); 
	Medidaw->SetTextFont(42);
	Medidaw->SetFillColor(kOrange-9); 
	Medidaw->SetShadowColor(1);
	Medidaw->SetMargin(0);
	Medidaw->AddText("");
	Medidaw->Draw();
	
	//Para el simbolo de medida
        Double_t xCenter = 0.57;  
        Double_t yCenter = 0.21;  
        Double_t radius = 0.04;   
    
        // Dibujar el circulo 
        TEllipse *circle = new TEllipse(xCenter, yCenter, 0.03, 0.06, 0, 360);  
        circle->SetLineColor(2);  
        circle->SetLineWidth(2);
        circle->SetFillColor(kOrange-9);  
        circle->Draw();
	
	//Flechas
	flecha2 = new TArrow(0.57, 0.21, 0.59, 0.29, 0.01, ">");
	flecha2->SetLineColor(2);
     	flecha2->SetLineWidth(2);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
	
	//Cuadro para ocultar la mitad del circulo
	TPaveText *ocultar1= new TPaveText(0.5299999, 0.05, 0.62, 0.21); 
	ocultar1->SetTextFont(42);
	ocultar1->SetLineWidth(0);  
	ocultar1->SetFillColor(kOrange-9); 
	ocultar1->SetShadowColor(1);
	ocultar1->SetMargin(0);
	ocultar1->AddText("");
	ocultar1->Draw();
	
	
	//Cuadro para QFT+
	TPaveText *QFT= new TPaveText(0.64, 0.40, 0.73, 0.75); 
	QFT->SetTextFont(42);
	QFT->SetFillColor(kOrange-9); 
	QFT->SetShadowColor(1);
	QFT->SetMargin(0);
	QFT->AddText("#font[62]{#color[2]{QFT^{+}}}");
	QFT->Draw();
      //Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso3_Circuito1_Exp->SetTextFont(42);
	Paso3_Circuito1_Exp->SetFillColor(0); 
	Paso3_Circuito1_Exp->SetShadowColor(kGray);
	Paso3_Circuito1_Exp->SetTextAlign(12);
	Paso3_Circuito1_Exp->SetMargin(0.01);
	Paso3_Circuito1_Exp->AddText("For #font[62]{step 3}, the measurements of the kets #font[62]{|w#GT} are first obtained, and then the #font[62]{Conjugate Transposed Quantum Fourier Transform} is performed");
	Paso3_Circuito1_Exp->AddText("or denoted as #font[62]{QFT^{+}} on the kets #font[62]{|x#GT}");
	Paso3_Circuito1_Exp->AddText("For the explanation of the #font[62]{QFT}, it is recommended to study another interface focused on its teaching, called #font[62]{QFTSoftEdu}, which belongs to");
	Paso3_Circuito1_Exp->AddText("#font[62]{FISINFOR} and developed by #font[62]{Ingrid Daiana Cuevas Ruiz}, a physics graduate from the #font[62]{Universidad Distrital}");
 	Paso3_Circuito1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1); 
       
        }
        if(Breakopt==4){

	//Titulo
	TPaveText *Paso4_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso4_circuit->SetTextFont(62);
	Paso4_circuit->SetFillColor(kCyan-10); 
	Paso4_circuit->SetShadowColor(kGray);
	Paso4_circuit->SetMargin(0);
	Paso4_circuit->AddText("Step #4");
	Paso4_circuit->Draw();
      //Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
      //Texto 1
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 21 therefore #color[9]{n} = 5");
      //Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
      //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q = 21");
      //Qbit|x>
	//Texto 2
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
      //Qbit|w>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
       //Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
      
        //Dibujo de los estados de los qbits 
	//Qbit|x>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.72, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.66, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.59, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.52, "#font[62]{|0#GT}");
        
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.45, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.70, 0.80, 0.70);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.64, 0.80, 0.64);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.57, 0.80, 0.57);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.50, 0.80, 0.50);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
      lineaH9 = new TLine(0.17, 0.43, 0.80, 0.43);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
      //Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{#color[1]{H}}");
	Hadamard1->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|w>
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.36, "#font[62]{|0#GT}");
        
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.29, "#font[62]{|0#GT}");

	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.22, "#font[62]{|0#GT}");
	
	l12->SetTextFont(42); 
	l12->SetTextColor(1);
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.14, 0.14, "#font[62]{|0#GT}");
        
	l13->SetTextFont(42); 
	l13->SetTextColor(1);
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.14, 0.07, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH10 = new TLine(0.17, 0.34, 0.60, 0.34);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	lineaH11 = new TLine(0.17, 0.27, 0.60, 0.27);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.20, 0.60, 0.20);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	lineaH13 = new TLine(0.17, 0.12, 0.60, 0.12);
	lineaH13->SetLineColor(kBlack);
	lineaH13->Draw();
	
	lineaH14 = new TLine(0.17, 0.05, 0.60, 0.05);
	lineaH14->SetLineColor(kBlack);
	lineaH14->Draw();
      //Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.03, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	CompuertaU->SetFillColor(kGray); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[1]{U_{a,N}}}");
	CompuertaU->Draw();
      //Compuerta de medida de|w>
	TPaveText *Medidaw= new TPaveText(0.52, 0.05, 0.62, 0.38); 
	Medidaw->SetTextFont(42);
	Medidaw->SetFillColor(kGray); 
	Medidaw->SetShadowColor(1);
	Medidaw->SetMargin(0);
	Medidaw->AddText("");
	Medidaw->Draw();
	
	//Para el simbolo de medida
        Double_t xCenter = 0.57;  
        Double_t yCenter = 0.21;  
        Double_t radius = 0.04;   
    
        // Dibujar el circulo 
        TEllipse *circle = new TEllipse(xCenter, yCenter, 0.03, 0.06, 0, 360);  
        circle->SetLineColor(1);  
        circle->SetLineWidth(2);
        circle->SetFillColor(kGray);  
        circle->Draw();
	
	//Flechas
	flecha2 = new TArrow(0.57, 0.21, 0.59, 0.29, 0.01, ">");
	flecha2->SetLineColor(1);
     	flecha2->SetLineWidth(2);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
	
	//Cuadro para ocultar la mitad del circulo
	TPaveText *ocultar1= new TPaveText(0.5299999, 0.05, 0.62, 0.21); 
	ocultar1->SetTextFont(42);
	ocultar1->SetLineWidth(0);  
	ocultar1->SetFillColor(kGray); 
	ocultar1->SetShadowColor(1);
	ocultar1->SetMargin(0);
	ocultar1->AddText("");
	ocultar1->Draw();
	
	//Cuadro para QFT+
	TPaveText *QFT= new TPaveText(0.64, 0.40, 0.73, 0.75); 
	QFT->SetTextFont(42);
	QFT->SetFillColor(kGray); 
	QFT->SetShadowColor(1);
	QFT->SetMargin(0);
	QFT->AddText("#font[62]{#color[1]{QFT^{+}}}");
	QFT->Draw();
      //medida|x>
	TPaveText *medidax= new TPaveText(0.77, 0.40, 0.87, 0.75); 
	medidax->SetTextFont(42); 
	medidax->SetFillColor(kOrange-9); 
	medidax->SetShadowColor(1);
	medidax->SetMargin(0);
	medidax->AddText("");
	medidax->Draw();
	
	//Diagrama de medida de x
	// Dibujar el circulo 
        circle1 = new TEllipse(0.82, 0.59, 0.03, 0.06, 0, 360);  
        circle1->SetLineColor(2);  
        circle1->SetLineWidth(2);
        circle1->SetFillColor(kOrange-9);  
        circle1->Draw();
	
	//Flechas
	flecha3 = new TArrow(0.82, 0.59, 0.85, 0.67, 0.01, ">");
	flecha3->SetLineColor(2);
     	flecha3->SetLineWidth(2);
     	flecha3->SetLineStyle(1);
     	flecha3->Draw();
	
	//Cuadro para ocultar la mitad del circulo 2
	TPaveText *ocultar2= new TPaveText(0.78, 0.40, 0.87, 0.59); 
	ocultar2->SetTextFont(42);
	ocultar2->SetLineWidth(0);  
	ocultar2->SetFillColor(kOrange-9); 
	ocultar2->SetShadowColor(1);
	ocultar2->SetMargin(0);
	ocultar2->AddText("");
	ocultar2->Draw();
      //Segundo canvas    	
     	TCanvas *ExpPaso4 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso4->SetFillColor(0);
	ExpPaso4->SetEditable(1);
	ExpPaso4->Clear();
	ExpPaso4->Update();
	TPaveText *Paso4_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso4_Circuito1_Exp->SetTextFont(42);
	Paso4_Circuito1_Exp->SetFillColor(0); 
	Paso4_Circuito1_Exp->SetShadowColor(kGray);
	Paso4_Circuito1_Exp->SetTextAlign(12);
	Paso4_Circuito1_Exp->SetMargin(0.01);
	Paso4_Circuito1_Exp->AddText("For #font[62]{step 4}, the measurement of the kets #font[62]{|x#GT} is performed, and at this point, the circuit is complete. To resolve any questions about the procedures");
	Paso4_Circuito1_Exp->AddText("for each gate, you can study the different cases, and if the doubt persists, then go to the #font[62]{CLEAR} button and then #font[62]{CONCEPTS}");
	Paso4_Circuito1_Exp->AddText("where you will find definitions of the concepts used in the #font[62]{Shor's algorithm} in a more basic and detailed manner for better understanding.");
 	Paso4_Circuito1_Exp->Draw();     	
     	
     	ExpPaso4->Update();
	ExpPaso4->SetEditable(1); 
          
        } 
      }
      	if(Breakopt == 5){
     	fTextButtonBACK->SetState(kButtonUp, kTRUE);
     	fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
     	DoCircuit();
     	CambioTab(1);
     	}  
      break;
      case 4:{
        if(Breakopt==1){
        //Titulo
	TPaveText *Paso1_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso1_circuit->SetTextFont(62);
	Paso1_circuit->SetFillColor(kBlue-10); 
	Paso1_circuit->SetShadowColor(kGray);
	Paso1_circuit->SetMargin(0);
	Paso1_circuit->AddText("Step #1");
	Paso1_circuit->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();

        //Texto 1
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 21 therefore #color[9]{n} = 5");
      //Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
     	
     	//Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q = 21");
     	
        //Qbit|x>
	//Texto 2
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
	
	//Qbit|w>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
      //Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|x>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.72, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.66, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.59, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.52, "#font[62]{|0#GT}");
        
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.45, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.70, 0.50, 0.70);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.64, 0.50, 0.64);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.57, 0.50, 0.57);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.50, 0.50, 0.50);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
      lineaH9 = new TLine(0.17, 0.43, 0.50, 0.43);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
      //Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.30, 0.40, 0.40, 0.75); 
	Hadamard1->SetTextFont(42);
	
	Hadamard1->SetFillColor(kOrange-9); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#color[2]{H}");
	Hadamard1->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|w>
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.36, "#font[62]{|0#GT}");
        
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.29, "#font[62]{|0#GT}");
	
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.22, "#font[62]{|0#GT}");
        
	l12->SetTextFont(42); 
	l12->SetTextColor(1);
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.14, 0.14, "#font[62]{|0#GT}");
        
	l13->SetTextFont(42); 
	l13->SetTextColor(1);
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.14, 0.07, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH10 = new TLine(0.17, 0.34, 0.50, 0.34);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	lineaH11 = new TLine(0.17, 0.27, 0.50, 0.27);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.20, 0.50, 0.20);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	lineaH13 = new TLine(0.17, 0.12, 0.50, 0.12);
	lineaH13->SetLineColor(kBlack);
	lineaH13->Draw();
	
	lineaH14 = new TLine(0.17, 0.05, 0.50, 0.05);
	lineaH14->SetLineColor(kBlack);
	lineaH14->Draw();
	
	//Detalles del circuito
	TPaveText *Circuit1= new TPaveText(0.60, 0.05, 0.90, 0.75); 
	Circuit1->SetTextFont(42);
	Circuit1->SetFillColor(kRed-10); 
	Circuit1->SetShadowColor(kGray);
	Circuit1->SetTextAlign(22);
	Circuit1->SetMargin(0);
	Circuit1->AddText("Due to the #font[62]{Shor's algorithm}, the kets #font[62]{|x#GT}");
	Circuit1->AddText("are defined as the number of #font[62]{n qubits}");
	Circuit1->AddText("and the kets #font[62]{|w#GT} are known as");
	Circuit1->AddText("#font[62]{auxiliary kets} and are used for");
	Circuit1->AddText("#font[62]{achieving greater precision} in the");
	Circuit1->AddText("#font[62]{result} of the #font[62]{factorization}");
	Circuit1->Draw();
	
	//Segundo canvas    	
     	TCanvas *ExpPaso1 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1->SetFillColor(0);
	ExpPaso1->SetEditable(1);
	ExpPaso1->Clear();
	ExpPaso1->Update();
	TPaveText *Paso1_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso1_Circuito1_Exp->SetTextFont(42);
	Paso1_Circuito1_Exp->SetFillColor(0); 
	Paso1_Circuito1_Exp->SetShadowColor(kGray);
	Paso1_Circuito1_Exp->SetTextAlign(12);
	Paso1_Circuito1_Exp->SetMargin(0.01);
	Paso1_Circuito1_Exp->AddText("For #font[62]{step 1}, it is necessary to define the number of #font[62]{n qubits} to use, which should be #font[62]{the nearest and greater number than the one to be factored}.");
	Paso1_Circuito1_Exp->AddText("After obtaining #font[62]{n}, the #font[62]{kets} #font[62]{|x#GT} and #font[62]{|w#GT} are separated, note that double #font[62]{n} is taken due to #font[62]{Shor's algorithm}.");
	Paso1_Circuito1_Exp->AddText("Then, the #font[62]{Hadamard gate} is applied only to the #font[62]{kets} #font[62]{|x#GT} to create the #font[62]{equiprobable superposition states}.");
 	Paso1_Circuito1_Exp->Draw();     	
     	
     	ExpPaso1->Update();
	ExpPaso1->SetEditable(1); 
        }
        if(Breakopt==2){
        //Titulo
        TPaveText *Paso2_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso2_circuit->SetTextFont(62);
	Paso2_circuit->SetFillColor(kGreen-10); 
	Paso2_circuit->SetShadowColor(kGray);
	Paso2_circuit->SetMargin(0);
	Paso2_circuit->AddText("Step #2");
	Paso2_circuit->Draw();
      //Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
       //Texto 1
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 21 therefore #color[9]{n} = 5");
      //Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
      //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q = 21");
      //Qbit|x>
	//Texto 2
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
      //Qbit|w>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
       //Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|x>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.72, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.66, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.59, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.52, "#font[62]{|0#GT}");
        
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.45, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.70, 0.50, 0.70);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.64, 0.50, 0.64);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.57, 0.50, 0.57);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.50, 0.50, 0.50);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
      lineaH9 = new TLine(0.17, 0.43, 0.50, 0.43);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
      //Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{#color[1]{H}}");
	Hadamard1->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|w>
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.36, "#font[62]{|0#GT}");
        
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.29, "#font[62]{|0#GT}");

	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.22, "#font[62]{|0#GT}");
        
	l12->SetTextFont(42); 
	l12->SetTextColor(1);
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.14, 0.14, "#font[62]{|0#GT}");
        
	l13->SetTextFont(42); 
	l13->SetTextColor(1);
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.14, 0.07, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH10 = new TLine(0.17, 0.34, 0.50, 0.34);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	lineaH11 = new TLine(0.17, 0.27, 0.50, 0.27);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.20, 0.50, 0.20);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	lineaH13 = new TLine(0.17, 0.12, 0.50, 0.12);
	lineaH13->SetLineColor(kBlack);
	lineaH13->Draw();
	
	lineaH14 = new TLine(0.17, 0.05, 0.50, 0.05);
	lineaH14->SetLineColor(kBlack);
	lineaH14->Draw();
      //Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.03, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	CompuertaU->SetFillColor(kOrange-9); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[2]{U_{a,N}}}");
	CompuertaU->Draw();
		
      //Segundo canvas    	
     	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	TPaveText *Paso2_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso2_Circuito1_Exp->SetTextFont(42);
	Paso2_Circuito1_Exp->SetFillColor(0); 
	Paso2_Circuito1_Exp->SetShadowColor(kGray);
	Paso2_Circuito1_Exp->SetTextAlign(12);
	Paso2_Circuito1_Exp->SetMargin(0.01);
	Paso2_Circuito1_Exp->AddText("For #font[62]{step 2}, the gate #font[62]{U_{a,N}} is applied, which affects and performs operations on all the kets to determine possible periodicity values,");
	Paso2_Circuito1_Exp->AddText("denoted as #font[62]{r}, from the function #font[62]{F = a^{r}(mod N)} in Shor's #font[62]{algorithm}. Due to the complexity of the gate #font[62]{U_{a,N}} in many cases");
	Paso2_Circuito1_Exp->AddText("it is treated as a #font[62]{black box}, and its explanations are often unclear. It is recommended to review #font[62]{modular algebra} and the operations performed in the");
	Paso2_Circuito1_Exp->AddText("tabs #font[62]{CLASSICAL} and #font[62]{QUANTUM} to compare the procedures that the gate performs on the #font[62]{qubits}.");
 	Paso2_Circuito1_Exp->Draw();     	
     	
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(1);   
      } 
        if(Breakopt==3){
      //Titulo
        TPaveText *Paso3_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_circuit->SetTextFont(62);
	Paso3_circuit->SetFillColor(kMagenta-10); 
	Paso3_circuit->SetShadowColor(kGray);
	Paso3_circuit->SetMargin(0);
	Paso3_circuit->AddText("Step #3");
	Paso3_circuit->Draw();
        
        //Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
      //Texto 1
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 21 therefore #color[9]{n} = 5");
      //Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
      //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q = 21");
      //Qbit|x>
	//Texto 2
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
      //Qbit|w>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
        //Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
      
        //Dibujo de los estados de los qbits 
	//Qbit|x>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.72, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.66, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.59, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.52, "#font[62]{|0#GT}");
       
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.45, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.70, 0.80, 0.70);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.64, 0.80, 0.64);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.57, 0.80, 0.57);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.50, 0.80, 0.50);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
      lineaH9 = new TLine(0.17, 0.43, 0.80, 0.43);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
      //Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{#color[1]{H}}");
	Hadamard1->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|w>
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.36, "#font[62]{|0#GT}");
      
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.29, "#font[62]{|0#GT}");
      
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.22, "#font[62]{|0#GT}");
      
	
	l12->SetTextFont(42); 
	l12->SetTextColor(1);
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.14, 0.14, "#font[62]{|0#GT}");
      
	l13->SetTextFont(42); 
	l13->SetTextColor(1);
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.14, 0.07, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH10 = new TLine(0.17, 0.34, 0.60, 0.34);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	lineaH11 = new TLine(0.17, 0.27, 0.60, 0.27);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.20, 0.60, 0.20);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	lineaH13 = new TLine(0.17, 0.12, 0.60, 0.12);
	lineaH13->SetLineColor(kBlack);
	lineaH13->Draw();
	
	lineaH14 = new TLine(0.17, 0.05, 0.60, 0.05);
	lineaH14->SetLineColor(kBlack);
	lineaH14->Draw();
      //Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.03, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	CompuertaU->SetFillColor(kGray); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[1]{U_{a,N}}}");
	CompuertaU->Draw();
      //Compuerta de medida de|w>
	TPaveText *Medidaw= new TPaveText(0.52, 0.05, 0.62, 0.38); 
	Medidaw->SetTextFont(42);
	Medidaw->SetFillColor(kOrange-9); 
	Medidaw->SetShadowColor(1);
	Medidaw->SetMargin(0);
	Medidaw->AddText("");
	Medidaw->Draw();
	
	//Para el simbolo de medida
        Double_t xCenter = 0.57;  
        Double_t yCenter = 0.21;  
        Double_t radius = 0.04;   
    
    	//Dibujar el circulo 
 	TEllipse *circle = new TEllipse(xCenter, yCenter, 0.03, 0.06, 0, 360);  
        circle->SetLineColor(2);  
        circle->SetLineWidth(2);
        circle->SetFillColor(kOrange-9);  
        circle->Draw();
	
	//Flechas
	flecha2 = new TArrow(0.57, 0.21, 0.59, 0.29, 0.01, ">");
	flecha2->SetLineColor(2);
     	flecha2->SetLineWidth(2);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
	
	//Cuadro para ocultar la mitad del circulo
	TPaveText *ocultar1= new TPaveText(0.5299999, 0.05, 0.62, 0.21); 
	ocultar1->SetTextFont(42);
	ocultar1->SetLineWidth(0);  
	ocultar1->SetFillColor(kOrange-9); 
	ocultar1->SetShadowColor(1);
	ocultar1->SetMargin(0);
	ocultar1->AddText("");
	ocultar1->Draw();
	
	//Cuadro para QFT+
	TPaveText *QFT= new TPaveText(0.64, 0.40, 0.73, 0.75); 
	QFT->SetTextFont(42);
	QFT->SetFillColor(kOrange-9); 
	QFT->SetShadowColor(1);
	QFT->SetMargin(0);
	QFT->AddText("#font[62]{#color[2]{QFT^{+}}}");
	QFT->Draw();
		
        //Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	TPaveText *Paso3_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso3_Circuito1_Exp->SetTextFont(42);
	Paso3_Circuito1_Exp->SetFillColor(0); 
	Paso3_Circuito1_Exp->SetShadowColor(kGray);
	Paso3_Circuito1_Exp->SetTextAlign(12);
	Paso3_Circuito1_Exp->SetMargin(0.01);
	Paso3_Circuito1_Exp->AddText("For #font[62]{step 3}, the measurements of the kets #font[62]{|w#GT} are first obtained, and then the #font[62]{Conjugate Transposed Quantum Fourier Transform} is performed");
	Paso3_Circuito1_Exp->AddText("or denoted as #font[62]{QFT^{+}} on the kets #font[62]{|x#GT}");
	Paso3_Circuito1_Exp->AddText("For the explanation of the #font[62]{QFT}, it is recommended to study another interface focused on its teaching, called #font[62]{QFTSoftEdu}, which belongs to");
	Paso3_Circuito1_Exp->AddText("#font[62]{FISINFOR} and developed by #font[62]{Ingrid Daiana Cuevas Ruiz}, a physics graduate from the #font[62]{Universidad Distrital}");
 	Paso3_Circuito1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1); 
      
        }
        if(Breakopt==4){

	//Titulo
	TPaveText *Paso4_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso4_circuit->SetTextFont(62);
	Paso4_circuit->SetFillColor(kCyan-10); 
	Paso4_circuit->SetShadowColor(kGray);
	Paso4_circuit->SetMargin(0);
	Paso4_circuit->AddText("Step #4");
	Paso4_circuit->Draw();
      //Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
      //Texto 1
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 21 therefore #color[9]{n} = 5");
      //Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
      //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q = 21");
      //Qbit|x>
	//Texto 2
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
      //Qbit|w>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
       //Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
      
        //Dibujo de los estados de los qbits 
	//Qbit|x>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.72, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.66, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.59, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.52, "#font[62]{|0#GT}");
      
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.45, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.70, 0.80, 0.70);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.64, 0.80, 0.64);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.57, 0.80, 0.57);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.50, 0.80, 0.50);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
      lineaH9 = new TLine(0.17, 0.43, 0.80, 0.43);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
      //Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{#color[1]{H}}");
	Hadamard1->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|w>
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.36, "#font[62]{|0#GT}");
      
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.29, "#font[62]{|0#GT}");
      
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.22, "#font[62]{|0#GT}");
      
	l12->SetTextFont(42); 
	l12->SetTextColor(1);
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.14, 0.14, "#font[62]{|0#GT}");
      
	l13->SetTextFont(42); 
	l13->SetTextColor(1);
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.14, 0.07, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH10 = new TLine(0.17, 0.34, 0.60, 0.34);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	lineaH11 = new TLine(0.17, 0.27, 0.60, 0.27);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.20, 0.60, 0.20);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	lineaH13 = new TLine(0.17, 0.12, 0.60, 0.12);
	lineaH13->SetLineColor(kBlack);
	lineaH13->Draw();
	
	lineaH14 = new TLine(0.17, 0.05, 0.60, 0.05);
	lineaH14->SetLineColor(kBlack);
	lineaH14->Draw();
      //Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.03, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	CompuertaU->SetFillColor(kGray); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[1]{U_{a,N}}}");
	CompuertaU->Draw();
      //Compuerta de medida de|w>
	TPaveText *Medidaw= new TPaveText(0.52, 0.05, 0.62, 0.38); 
	Medidaw->SetTextFont(42);
	Medidaw->SetFillColor(kGray); 
	Medidaw->SetShadowColor(1);
	Medidaw->SetMargin(0);
	Medidaw->AddText("");
	Medidaw->Draw();
	
	//Para el simbolo de medida
        Double_t xCenter = 0.57;  
        Double_t yCenter = 0.21;  
        Double_t radius = 0.04;   
    
        // Dibujar el circulo 
 	TEllipse *circle = new TEllipse(xCenter, yCenter, 0.03, 0.06, 0, 360);  
        circle->SetLineColor(1);  
        circle->SetLineWidth(2);
        circle->SetFillColor(kGray);  
        circle->Draw();
	
	//Flechas
	flecha2 = new TArrow(0.57, 0.21, 0.59, 0.29, 0.01, ">");
	flecha2->SetLineColor(1);
     	flecha2->SetLineWidth(2);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
	
	//Cuadro para ocultar la mitad del circulo
	TPaveText *ocultar1= new TPaveText(0.5299999, 0.05, 0.62, 0.21); 
	ocultar1->SetTextFont(42);
	ocultar1->SetLineWidth(0);  
	ocultar1->SetFillColor(kGray); 
	ocultar1->SetShadowColor(1);
	ocultar1->SetMargin(0);
	ocultar1->AddText("");
	ocultar1->Draw();
	
	//Cuadro para QFT+
	TPaveText *QFT= new TPaveText(0.64, 0.40, 0.73, 0.75); 
	QFT->SetTextFont(42);
	QFT->SetFillColor(kGray); 
	QFT->SetShadowColor(1);
	QFT->SetMargin(0);
	QFT->AddText("#font[62]{#color[1]{QFT^{+}}}");
	QFT->Draw();
      //medida|x>
	TPaveText *medidax= new TPaveText(0.77, 0.40, 0.87, 0.75); 
	medidax->SetTextFont(42);
	medidax->SetFillColor(kOrange-9); 
	medidax->SetShadowColor(1);
	medidax->SetMargin(0);
	medidax->AddText("");
	medidax->Draw();
	
	//Diagrama de medida de x
	// Dibujar el circulo 
        circle1 = new TEllipse(0.82, 0.59, 0.03, 0.06, 0, 360);  
        circle1->SetLineColor(2);  
        circle1->SetLineWidth(2);
        circle1->SetFillColor(kOrange-9);  
        circle1->Draw();
	
	//Flechas
	flecha3 = new TArrow(0.82, 0.59, 0.85, 0.67, 0.01, ">");
	flecha3->SetLineColor(2);
     	flecha3->SetLineWidth(2);
     	flecha3->SetLineStyle(1);
     	flecha3->Draw();
	
	//Cuadro para ocultar la mitad del circulo 2
	TPaveText *ocultar2= new TPaveText(0.78, 0.40, 0.87, 0.59); 
	ocultar2->SetTextFont(42);
	ocultar2->SetLineWidth(0);  
	ocultar2->SetFillColor(kOrange-9); 
	ocultar2->SetShadowColor(1);
	ocultar2->SetMargin(0);
	ocultar2->AddText("");
	ocultar2->Draw();
      //Segundo canvas    	
     	TCanvas *ExpPaso4 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso4->SetFillColor(0);
	ExpPaso4->SetEditable(1);
	ExpPaso4->Clear();
	ExpPaso4->Update();
	TPaveText *Paso4_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso4_Circuito1_Exp->SetTextFont(42);
	Paso4_Circuito1_Exp->SetFillColor(0); 
	Paso4_Circuito1_Exp->SetShadowColor(kGray);
	Paso4_Circuito1_Exp->SetTextAlign(12);
	Paso4_Circuito1_Exp->SetMargin(0.01);
	Paso4_Circuito1_Exp->AddText("For #font[62]{step 4}, the measurement of the kets #font[62]{|x#GT} is performed, and at this point, the circuit is complete. To resolve any questions about the procedures");
	Paso4_Circuito1_Exp->AddText("for each gate, you can study the different cases, and if the doubt persists, then go to the #font[62]{CLEAR} button and then #font[62]{CONCEPTS}");
	Paso4_Circuito1_Exp->AddText("where you will find definitions of the concepts used in the #font[62]{Shor's algorithm} in a more basic and detailed manner for better understanding.");
 	Paso4_Circuito1_Exp->Draw();     	
     	
     	ExpPaso4->Update();
	ExpPaso4->SetEditable(1); 
        }
      }  
      	if(Breakopt == 5){
     	fTextButtonBACK->SetState(kButtonUp, kTRUE);
     	fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
     	DoCircuit();
     	CambioTab(1);
     	}
      break;
      case 5:{
	if(Breakopt==1){
         //Titulo
	TPaveText *Paso1_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso1_circuit->SetTextFont(62);
	Paso1_circuit->SetFillColor(kBlue-10); 
	Paso1_circuit->SetShadowColor(kGray);
	Paso1_circuit->SetMargin(0);
	Paso1_circuit->AddText("Step #1");
	Paso1_circuit->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();

        //Texto 1
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 21 therefore #color[9]{n} = 5");
      //Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
     	
     	//Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q = 21");
     	
        //Qbit|x>
	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
	
	//Qbit|w>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
      //Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|x>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.72, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.66, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.59, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.52, "#font[62]{|0#GT}");
      
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.45, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.70, 0.50, 0.70);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.64, 0.50, 0.64);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.57, 0.50, 0.57);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.50, 0.50, 0.50);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
      lineaH9 = new TLine(0.17, 0.43, 0.50, 0.43);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
      //Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.30, 0.40, 0.40, 0.75); 
	Hadamard1->SetTextFont(42);
	
	Hadamard1->SetFillColor(kOrange-9); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#color[2]{H}");
	Hadamard1->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|w>
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.36, "#font[62]{|0#GT}");
      
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.29, "#font[62]{|0#GT}");
      
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.22, "#font[62]{|0#GT}");
      
	l12->SetTextFont(42); 
	l12->SetTextColor(1);
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.14, 0.14, "#font[62]{|0#GT}");
      
	l13->SetTextFont(42); 
	l13->SetTextColor(1);
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.14, 0.07, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH10 = new TLine(0.17, 0.34, 0.50, 0.34);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	lineaH11 = new TLine(0.17, 0.27, 0.50, 0.27);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.20, 0.50, 0.20);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	lineaH13 = new TLine(0.17, 0.12, 0.50, 0.12);
	lineaH13->SetLineColor(kBlack);
	lineaH13->Draw();
	
	lineaH14 = new TLine(0.17, 0.05, 0.50, 0.05);
	lineaH14->SetLineColor(kBlack);
	lineaH14->Draw();
	
	//Detalles del circuito
	TPaveText *Circuit1= new TPaveText(0.60, 0.05, 0.90, 0.75); 
	Circuit1->SetTextFont(42);
	Circuit1->SetFillColor(kRed-10); 
	Circuit1->SetShadowColor(kGray);
	Circuit1->SetTextAlign(22);
	Circuit1->SetMargin(0);
	Circuit1->AddText("Due to the #font[62]{Shor's algorithm}, the kets #font[62]{|x#GT}");
	Circuit1->AddText("are defined as the number of #font[62]{n qubits}");
	Circuit1->AddText("and the kets #font[62]{|w#GT} are known as");
	Circuit1->AddText("#font[62]{auxiliary kets} and are used for");
	Circuit1->AddText("#font[62]{achieving greater precision} in the");
	Circuit1->AddText("#font[62]{result} of the #font[62]{factorization}");
	Circuit1->Draw();
	
	//Segundo canvas    	
     	TCanvas *ExpPaso1 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1->SetFillColor(0);
	ExpPaso1->SetEditable(1);
	ExpPaso1->Clear();
	ExpPaso1->Update();
	TPaveText *Paso1_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso1_Circuito1_Exp->SetTextFont(42);
	Paso1_Circuito1_Exp->SetFillColor(0); 
	Paso1_Circuito1_Exp->SetShadowColor(kGray);
	Paso1_Circuito1_Exp->SetTextAlign(12);
	Paso1_Circuito1_Exp->SetMargin(0.01);
	Paso1_Circuito1_Exp->AddText("For #font[62]{step 1}, it is necessary to define the number of #font[62]{n qubits} to use, which should be #font[62]{the nearest and greater number than the one to be factored}.");
	Paso1_Circuito1_Exp->AddText("After obtaining #font[62]{n}, the #font[62]{kets} #font[62]{|x#GT} and #font[62]{|w#GT} are separated, note that double #font[62]{n} is taken due to #font[62]{Shor's algorithm}.");
	Paso1_Circuito1_Exp->AddText("Then, the #font[62]{Hadamard gate} is applied only to the #font[62]{kets} #font[62]{|x#GT} to create the #font[62]{equiprobable superposition states}.");
 	Paso1_Circuito1_Exp->Draw();     	
    
     	ExpPaso1->Update();
	ExpPaso1->SetEditable(1); 
      }
         
        if(Breakopt==2){
      
        //Titulo
        TPaveText *Paso2_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso2_circuit->SetTextFont(62);
	Paso2_circuit->SetFillColor(kGreen-10); 
	Paso2_circuit->SetShadowColor(kGray);
	Paso2_circuit->SetMargin(0);
	Paso2_circuit->AddText("Step #2");
	Paso2_circuit->Draw();
      //Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
      //Texto 1
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 21 therefore #color[9]{n} = 5");
      //Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
      //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q = 21");
      //Qbit|x>
	//Texto 2
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
      //Qbit|w>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
      //Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|x>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.72, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.66, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.59, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.52, "#font[62]{|0#GT}");
      
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.45, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.70, 0.50, 0.70);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.64, 0.50, 0.64);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.57, 0.50, 0.57);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.50, 0.50, 0.50);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
      lineaH9 = new TLine(0.17, 0.43, 0.50, 0.43);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
      //Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{#color[1]{H}}");
	Hadamard1->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|w>
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.36, "#font[62]{|0#GT}");
      
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.29, "#font[62]{|0#GT}");
      
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.22, "#font[62]{|0#GT}");
      
	l12->SetTextFont(42); 
	l12->SetTextColor(1);
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.14, 0.14, "#font[62]{|0#GT}");
      
	l13->SetTextFont(42); 
	l13->SetTextColor(1);
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.14, 0.07, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH10 = new TLine(0.17, 0.34, 0.50, 0.34);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	lineaH11 = new TLine(0.17, 0.27, 0.50, 0.27);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.20, 0.50, 0.20);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	lineaH13 = new TLine(0.17, 0.12, 0.50, 0.12);
	lineaH13->SetLineColor(kBlack);
	lineaH13->Draw();
	
	lineaH14 = new TLine(0.17, 0.05, 0.50, 0.05);
	lineaH14->SetLineColor(kBlack);
	lineaH14->Draw();
      //Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.03, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	CompuertaU->SetFillColor(kOrange-9); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[2]{U_{a,N}}}");
	CompuertaU->Draw();
		
        //Segundo canvas    	
     	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	TPaveText *Paso2_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso2_Circuito1_Exp->SetTextFont(42);
	Paso2_Circuito1_Exp->SetFillColor(0); 
	Paso2_Circuito1_Exp->SetShadowColor(kGray);
	Paso2_Circuito1_Exp->SetTextAlign(12);
	Paso2_Circuito1_Exp->SetMargin(0.01);
	Paso2_Circuito1_Exp->AddText("For #font[62]{step 2}, the gate #font[62]{U_{a,N}} is applied, which affects and performs operations on all the kets to determine possible periodicity values,");
	Paso2_Circuito1_Exp->AddText("denoted as #font[62]{r}, from the function #font[62]{F = a^{r}(mod N)} in Shor's #font[62]{algorithm}. Due to the complexity of the gate #font[62]{U_{a,N}} in many cases");
	Paso2_Circuito1_Exp->AddText("it is treated as a #font[62]{black box}, and its explanations are often unclear. It is recommended to review #font[62]{modular algebra} and the operations performed in the");
	Paso2_Circuito1_Exp->AddText("tabs #font[62]{CLASSICAL} and #font[62]{QUANTUM} to compare the procedures that the gate performs on the #font[62]{qubits}.");
 	Paso2_Circuito1_Exp->Draw();     	
     	
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(1);   
      
        } 
        if(Breakopt==3){
      
        //Titulo
        TPaveText *Paso3_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_circuit->SetTextFont(62);
	Paso3_circuit->SetFillColor(kMagenta-10); 
	Paso3_circuit->SetShadowColor(kGray);
	Paso3_circuit->SetMargin(0);
	Paso3_circuit->AddText("Step #3");
	Paso3_circuit->Draw();
      //Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
      //Texto 1
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 21 therefore #color[9]{n} = 5");
      //Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
      //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q = 21");
      //Qbit|x>
	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
      //Qbit|w>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
       //Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
      
         //Dibujo de los estados de los qbits 
	//Qbit|x>
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.72, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.66, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.59, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.52, "#font[62]{|0#GT}");
      
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.45, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.70, 0.80, 0.70);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.64, 0.80, 0.64);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.57, 0.80, 0.57);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.50, 0.80, 0.50);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
      lineaH9 = new TLine(0.17, 0.43, 0.80, 0.43);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
      //Compuertas hadamard
	 TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{#color[1]{H}}");
	Hadamard1->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|w>
	
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.36, "#font[62]{|0#GT}");
      
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.29, "#font[62]{|0#GT}");
      
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.22, "#font[62]{|0#GT}");
      
	l12->SetTextFont(42); 
	l12->SetTextColor(1);
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.14, 0.14, "#font[62]{|0#GT}");
      
	l13->SetTextFont(42); 
	l13->SetTextColor(1);
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.14, 0.07, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH10 = new TLine(0.17, 0.34, 0.60, 0.34);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	lineaH11 = new TLine(0.17, 0.27, 0.60, 0.27);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.20, 0.60, 0.20);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	lineaH13 = new TLine(0.17, 0.12, 0.60, 0.12);
	lineaH13->SetLineColor(kBlack);
	lineaH13->Draw();
	
	lineaH14 = new TLine(0.17, 0.05, 0.60, 0.05);
	lineaH14->SetLineColor(kBlack);
	lineaH14->Draw();
      //Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.03, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	CompuertaU->SetFillColor(kGray); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[1]{U_{a,N}}}");
	CompuertaU->Draw();
      //Compuerta de medida de|w>
	TPaveText *Medidaw= new TPaveText(0.52, 0.05, 0.62, 0.38); 
	Medidaw->SetTextFont(42);
	Medidaw->SetFillColor(kOrange-9); 
	Medidaw->SetShadowColor(1);
	Medidaw->SetMargin(0);
	Medidaw->AddText("");
	Medidaw->Draw();
	
	//Para el simbolo de medida
        Double_t xCenter = 0.57;  
        Double_t yCenter = 0.21;  
        Double_t radius = 0.04;   
    
        // Dibujar el circulo 
 	TEllipse *circle = new TEllipse(xCenter, yCenter, 0.03, 0.06, 0, 360);  
        circle->SetLineColor(2);  
        circle->SetLineWidth(2);
        circle->SetFillColor(kOrange-9);  
        circle->Draw();
	
	//Flechas
	flecha2 = new TArrow(0.57, 0.21, 0.59, 0.29, 0.01, ">");
	flecha2->SetLineColor(2);
     	flecha2->SetLineWidth(2);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
	
	//Cuadro para ocultar la mitad del circulo
	TPaveText *ocultar1= new TPaveText(0.5299999, 0.05, 0.62, 0.21); 
	ocultar1->SetTextFont(42);
	ocultar1->SetLineWidth(0);  
	ocultar1->SetFillColor(kOrange-9); 
	ocultar1->SetShadowColor(1);
	ocultar1->SetMargin(0);
	ocultar1->AddText("");
	ocultar1->Draw();
	
	
	//Cuadro para QFT+
	TPaveText *QFT= new TPaveText(0.64, 0.40, 0.73, 0.75); 
	QFT->SetTextFont(42);
	QFT->SetFillColor(kOrange-9); 
	QFT->SetShadowColor(1);
	QFT->SetMargin(0);
	QFT->AddText("#font[62]{#color[2]{QFT^{+}}}");
	QFT->Draw();
		
		
        //Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	TPaveText *Paso3_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso3_Circuito1_Exp->SetTextFont(42);
	Paso3_Circuito1_Exp->SetFillColor(0); 
	Paso3_Circuito1_Exp->SetShadowColor(kGray);
	Paso3_Circuito1_Exp->SetTextAlign(12);
	Paso3_Circuito1_Exp->SetMargin(0.01);
	Paso3_Circuito1_Exp->AddText("For #font[62]{step 3}, the measurements of the kets #font[62]{|w#GT} are first obtained, and then the #font[62]{Conjugate Transposed Quantum Fourier Transform} is performed");
	Paso3_Circuito1_Exp->AddText("or denoted as #font[62]{QFT^{+}} on the kets #font[62]{|x#GT}");
	Paso3_Circuito1_Exp->AddText("For the explanation of the #font[62]{QFT}, it is recommended to study another interface focused on its teaching, called #font[62]{QFTSoftEdu}, which belongs to");
	Paso3_Circuito1_Exp->AddText("#font[62]{FISINFOR} and developed by #font[62]{Ingrid Daiana Cuevas Ruiz}, a physics graduate from the #font[62]{Universidad Distrital}");
 	Paso3_Circuito1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1); 
      
        }
        if(Breakopt==4){

	//Titulo
	TPaveText *Paso4_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso4_circuit->SetTextFont(62);
	Paso4_circuit->SetFillColor(kCyan-10); 
	Paso4_circuit->SetShadowColor(kGray);
	Paso4_circuit->SetMargin(0);
	Paso4_circuit->AddText("Step #4");
	Paso4_circuit->Draw();
      //Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
      //Texto 1
	
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 21 therefore #color[9]{n} = 5");
      //Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
      //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q = 21");
      //Qbit|x>
	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
      //Qbit|w>
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
       //Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
      
        //Dibujo de los estados de los qbits 
	//Qbit|x>
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.72, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.66, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.59, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.52, "#font[62]{|0#GT}");
      
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.45, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.70, 0.80, 0.70);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.64, 0.80, 0.64);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.57, 0.80, 0.57);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.50, 0.80, 0.50);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
      lineaH9 = new TLine(0.17, 0.43, 0.80, 0.43);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
      //Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{#color[1]{H}}");
	Hadamard1->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|w>
	
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.36, "#font[62]{|0#GT}");
      
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.29, "#font[62]{|0#GT}");
      
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.22, "#font[62]{|0#GT}");
      
	l12->SetTextFont(42); 
	l12->SetTextColor(1);
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.14, 0.14, "#font[62]{|0#GT}");
      
	l13->SetTextFont(42); 
	l13->SetTextColor(1);
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.14, 0.07, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH10 = new TLine(0.17, 0.34, 0.60, 0.34);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	lineaH11 = new TLine(0.17, 0.27, 0.60, 0.27);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.20, 0.60, 0.20);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	lineaH13 = new TLine(0.17, 0.12, 0.60, 0.12);
	lineaH13->SetLineColor(kBlack);
	lineaH13->Draw();
	
	lineaH14 = new TLine(0.17, 0.05, 0.60, 0.05);
	lineaH14->SetLineColor(kBlack);
	lineaH14->Draw();
      //Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.03, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	
	CompuertaU->SetFillColor(kGray); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[1]{U_{a,N}}}");
	CompuertaU->Draw();
      //Compuerta de medida de|w>
	TPaveText *Medidaw= new TPaveText(0.52, 0.05, 0.62, 0.38); 
	Medidaw->SetTextFont(42);
	
	Medidaw->SetFillColor(kGray); 
	Medidaw->SetShadowColor(1);
	Medidaw->SetMargin(0);
	Medidaw->AddText("");
	Medidaw->Draw();
	
	//Para el simbolo de medida
        Double_t xCenter = 0.57;  
        Double_t yCenter = 0.21;  
        Double_t radius = 0.04;   
    
        // Dibujar el circulo 
 	TEllipse *circle = new TEllipse(xCenter, yCenter, 0.03, 0.06, 0, 360);  
        circle->SetLineColor(1);  
        circle->SetLineWidth(2);
        circle->SetFillColor(kGray);  
        circle->Draw();
	
	//Flechas
	flecha2 = new TArrow(0.57, 0.21, 0.59, 0.29, 0.01, ">");
	flecha2->SetLineColor(1);
     	flecha2->SetLineWidth(2);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
	
	//Cuadro para ocultar la mitad del circulo
	TPaveText *ocultar1= new TPaveText(0.5299999, 0.05, 0.62, 0.21); 
	ocultar1->SetTextFont(42);
	ocultar1->SetLineWidth(0);  
	ocultar1->SetFillColor(kGray); 
	ocultar1->SetShadowColor(1);
	ocultar1->SetMargin(0);
	ocultar1->AddText("");
	ocultar1->Draw();
	
	
	//Cuadro para QFT+
	TPaveText *QFT= new TPaveText(0.64, 0.40, 0.73, 0.75); 
	QFT->SetTextFont(42);
	QFT->SetFillColor(kGray); 
	QFT->SetShadowColor(1);
	QFT->SetMargin(0);
	QFT->AddText("#font[62]{#color[1]{QFT^{+}}}");
	QFT->Draw();
      //medida|x>
	TPaveText *medidax= new TPaveText(0.77, 0.40, 0.87, 0.75); 
	medidax->SetTextFont(42);
	medidax->SetFillColor(kOrange-9); 
	medidax->SetShadowColor(1);
	medidax->SetMargin(0);
	medidax->AddText("");
	medidax->Draw();
	
	//Diagrama de medida de x
	// Dibujar el circulo 
    	circle1 = new TEllipse(0.82, 0.59, 0.03, 0.06, 0, 360);  
    	circle1->SetLineColor(2);  
    	circle1->SetLineWidth(2);
    	circle1->SetFillColor(kOrange-9);  
    	circle1->Draw();
	
	//Flechas
	flecha3 = new TArrow(0.82, 0.59, 0.85, 0.67, 0.01, ">");
	flecha3->SetLineColor(2);
     	flecha3->SetLineWidth(2);
     	flecha3->SetLineStyle(1);
     	flecha3->Draw();
	
	//Cuadro para ocultar la mitad del circulo 2
	TPaveText *ocultar2= new TPaveText(0.78, 0.40, 0.87, 0.59); 
	ocultar2->SetTextFont(42);
	
	ocultar2->SetLineWidth(0);  
	ocultar2->SetFillColor(kOrange-9); 
	ocultar2->SetShadowColor(1);
	ocultar2->SetMargin(0);
	ocultar2->AddText("");
	ocultar2->Draw();
      //Segundo canvas    	
     	TCanvas *ExpPaso4 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso4->SetFillColor(0);
	ExpPaso4->SetEditable(1);
	ExpPaso4->Clear();
	ExpPaso4->Update();
	TPaveText *Paso4_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso4_Circuito1_Exp->SetTextFont(42);
	Paso4_Circuito1_Exp->SetFillColor(0); 
	Paso4_Circuito1_Exp->SetShadowColor(kGray);
	Paso4_Circuito1_Exp->SetTextAlign(12);
	Paso4_Circuito1_Exp->SetMargin(0.01);
	Paso4_Circuito1_Exp->AddText("For #font[62]{step 4}, the measurement of the kets #font[62]{|x#GT} is performed, and at this point, the circuit is complete. To resolve any questions about the procedures");
	Paso4_Circuito1_Exp->AddText("for each gate, you can study the different cases, and if the doubt persists, then go to the #font[62]{CLEAR} button and then #font[62]{CONCEPTS}");
	Paso4_Circuito1_Exp->AddText("where you will find definitions of the concepts used in the #font[62]{Shor's algorithm} in a more basic and detailed manner for better understanding.");
 	Paso4_Circuito1_Exp->Draw();     	
     	
     	ExpPaso4->Update();
	ExpPaso4->SetEditable(1); 
        }
      } 
      	if(Breakopt == 5){
     	fTextButtonBACK->SetState(kButtonUp, kTRUE);
     	fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
     	DoCircuit();
     	CambioTab(1);
     	}
      break;
  }
}

if(Valueopt1 == 35){
  switch(Valueopt2){
     case 1:{
        if(Breakopt==1){
      //Titulo
        TPaveText *Paso1_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso1_circuit->SetTextFont(62);
	
	Paso1_circuit->SetFillColor(kBlue-10); 
	Paso1_circuit->SetShadowColor(kGray);
	Paso1_circuit->SetMargin(0);
	Paso1_circuit->AddText("Step #1");
	Paso1_circuit->Draw();
      //Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
      //Texto 1
	
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 35 therefore #color[9]{n} = 6");
      //Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
     	
     	//Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q = 35");
      //Qbit|x>
	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
	
	//Qbit|w>
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
	
	//Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|x>
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.72, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.67, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.61, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.56, "#font[62]{|0#GT}");
      
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.51, "#font[62]{|0#GT}");
      
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.45, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.70, 0.50, 0.70);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.65, 0.50, 0.65);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.59, 0.50, 0.59);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.54, 0.50, 0.54);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
      lineaH9 = new TLine(0.17, 0.49, 0.50, 0.49);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
      lineaH10 = new TLine(0.17, 0.43, 0.50, 0.43);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
      //Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.30, 0.40, 0.40, 0.75); 
	Hadamard1->SetTextFont(42);
	
	Hadamard1->SetFillColor(kOrange-9); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#color[2]{H}");
	Hadamard1->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|w>
	
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.36, "#font[62]{|0#GT}");
	
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.31, "#font[62]{|0#GT}");
      
	l12->SetTextFont(42); 
	l12->SetTextColor(1);
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.14, 0.25, "#font[62]{|0#GT}");
      
	l13->SetTextFont(42); 
	l13->SetTextColor(1);
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.14, 0.19, "#font[62]{|0#GT}");
      
	l14->SetTextFont(42); 
	l14->SetTextColor(1);
	l14->SetTextAlign(12); 
	l14->DrawLatex(0.14, 0.13, "#font[62]{|0#GT}");
	
	 
	l15->SetTextFont(42); 
	l15->SetTextColor(1);
	l15->SetTextAlign(12); 
	l15->DrawLatex(0.14, 0.07, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH11 = new TLine(0.17, 0.34, 0.50, 0.34);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.29, 0.50, 0.29);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	lineaH13 = new TLine(0.17, 0.23, 0.50, 0.23);
	lineaH13->SetLineColor(kBlack);
	lineaH13->Draw();
	
	lineaH14 = new TLine(0.17, 0.17, 0.50, 0.17);
	lineaH14->SetLineColor(kBlack);
	lineaH14->Draw();
	
	lineaH15 = new TLine(0.17, 0.11, 0.50, 0.11);
	lineaH15->SetLineColor(kBlack);
	lineaH15->Draw();
	
	lineaH16 = new TLine(0.17, 0.05, 0.50, 0.05);
	lineaH16->SetLineColor(kBlack);
	lineaH16->Draw();
	
	//Detalles del circuito
	TPaveText *Circuit1= new TPaveText(0.60, 0.05, 0.90, 0.75); 
	Circuit1->SetTextFont(42);
	Circuit1->SetFillColor(kRed-10); 
	Circuit1->SetShadowColor(kGray);
	Circuit1->SetTextAlign(22);
	Circuit1->SetMargin(0);
	Circuit1->AddText("Due to the #font[62]{Shor's algorithm}, the kets #font[62]{|x#GT}");
	Circuit1->AddText("are defined as the number of #font[62]{n qubits}");
	Circuit1->AddText("and the kets #font[62]{|w#GT} are known as");
	Circuit1->AddText("#font[62]{auxiliary kets} and are used for");
	Circuit1->AddText("#font[62]{achieving greater precision} in the");
	Circuit1->AddText("#font[62]{result} of the #font[62]{factorization}");
	Circuit1->Draw();
      //Segundo canvas    	
     	TCanvas *ExpPaso1 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1->SetFillColor(0);
	ExpPaso1->SetEditable(1);
	ExpPaso1->Clear();
	ExpPaso1->Update();
	TPaveText *Paso1_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso1_Circuito1_Exp->SetTextFont(42);
	Paso1_Circuito1_Exp->SetFillColor(0); 
	Paso1_Circuito1_Exp->SetShadowColor(kGray);
	Paso1_Circuito1_Exp->SetTextAlign(12);
	Paso1_Circuito1_Exp->SetMargin(0.01);
	Paso1_Circuito1_Exp->AddText("For #font[62]{step 1}, it is necessary to define the number of #font[62]{n qubits} to use, which should be #font[62]{the nearest and greater number than the one to be factored}.");
	Paso1_Circuito1_Exp->AddText("After obtaining #font[62]{n}, the #font[62]{kets} #font[62]{|x#GT} and #font[62]{|w#GT} are separated, note that double #font[62]{n} is taken due to #font[62]{Shor's algorithm}.");
	Paso1_Circuito1_Exp->AddText("Then, the #font[62]{Hadamard gate} is applied only to the #font[62]{kets} #font[62]{|x#GT} to create the #font[62]{equiprobable superposition states}.");
 	Paso1_Circuito1_Exp->Draw();     	
     	
     	ExpPaso1->Update();
	ExpPaso1->SetEditable(1);
      }
        if(Breakopt==2){
      
        //Titulo
        TPaveText *Paso2_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso2_circuit->SetTextFont(62);
	Paso2_circuit->SetFillColor(kGreen-10); 
	Paso2_circuit->SetShadowColor(kGray);
	Paso2_circuit->SetMargin(0);
	Paso2_circuit->AddText("Step #2");
	Paso2_circuit->Draw();
      //Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
      //Texto 1
	
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 35 therefore #color[9]{n} = 6");
      //Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
      //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q = 35");
	
	//Qbit|x>
	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
	
	//Qbit|w>
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
	
	//Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|x>
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.72, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.67, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.61, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.56, "#font[62]{|0#GT}");
      
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.51, "#font[62]{|0#GT}");
      
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.45, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.70, 0.50, 0.70);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.65, 0.50, 0.65);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.59, 0.50, 0.59);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.54, 0.50, 0.54);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
      lineaH9 = new TLine(0.17, 0.49, 0.50, 0.49);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
      lineaH10 = new TLine(0.17, 0.43, 0.50, 0.43);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	//Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{#color[1]{H}}");
	Hadamard1->Draw();
	
	//Dibujo de los estados de los qbits 
	//Qbit|w>
	
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.36, "#font[62]{|0#GT}");
	
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.31, "#font[62]{|0#GT}");
      
	l12->SetTextFont(42); 
	l12->SetTextColor(1);
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.14, 0.25, "#font[62]{|0#GT}");
      
	l13->SetTextFont(42); 
	l13->SetTextColor(1);
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.14, 0.19, "#font[62]{|0#GT}");
	
      	
	l14->SetTextFont(42); 
	l14->SetTextColor(1);
	l14->SetTextAlign(12); 
	l14->DrawLatex(0.14, 0.13, "#font[62]{|0#GT}");
	 
	l15->SetTextFont(42); 
	l15->SetTextColor(1);
	l15->SetTextAlign(12); 
	l15->DrawLatex(0.14, 0.07, "#font[62]{|0#GT}");
      
      	//Lineas de representacion de cada qbit|w>
	lineaH11 = new TLine(0.17, 0.34, 0.50, 0.34);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.29, 0.50, 0.29);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	lineaH13 = new TLine(0.17, 0.23, 0.50, 0.23);
	lineaH13->SetLineColor(kBlack);
	lineaH13->Draw();
	
	lineaH14 = new TLine(0.17, 0.17, 0.50, 0.17);
	lineaH14->SetLineColor(kBlack);
	lineaH14->Draw();
	
	lineaH15 = new TLine(0.17, 0.11, 0.50, 0.11);
	lineaH15->SetLineColor(kBlack);
	lineaH15->Draw();
	
	lineaH16 = new TLine(0.17, 0.05, 0.50, 0.05);
	lineaH16->SetLineColor(kBlack);
	lineaH16->Draw();
      //Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.03, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	CompuertaU->SetFillColor(kOrange-9); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[2]{U_{a,N}}}");
	CompuertaU->Draw();
		
        //Segundo canvas    	
     	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	TPaveText *Paso2_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso2_Circuito1_Exp->SetTextFont(42);
	Paso2_Circuito1_Exp->SetFillColor(0); 
	Paso2_Circuito1_Exp->SetShadowColor(kGray);
	Paso2_Circuito1_Exp->SetTextAlign(12);
	Paso2_Circuito1_Exp->SetMargin(0.01);
	Paso2_Circuito1_Exp->AddText("For #font[62]{step 2}, the gate #font[62]{U_{a,N}} is applied, which affects and performs operations on all the kets to determine possible periodicity values,");
	Paso2_Circuito1_Exp->AddText("denoted as #font[62]{r}, from the function #font[62]{F = a^{r}(mod N)} in Shor's #font[62]{algorithm}. Due to the complexity of the gate #font[62]{U_{a,N}} in many cases");
	Paso2_Circuito1_Exp->AddText("it is treated as a #font[62]{black box}, and its explanations are often unclear. It is recommended to review #font[62]{modular algebra} and the operations performed in the");
	Paso2_Circuito1_Exp->AddText("tabs #font[62]{CLASSICAL} and #font[62]{QUANTUM} to compare the procedures that the gate performs on the #font[62]{qubits}.");
 	Paso2_Circuito1_Exp->Draw();     	
     	
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(1);
      
        }
        if(Breakopt==3){
      
        //Titulo
        TPaveText *Paso3_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_circuit->SetTextFont(62);
	Paso3_circuit->SetFillColor(kMagenta-10); 
	Paso3_circuit->SetShadowColor(kGray);
	Paso3_circuit->SetMargin(0);
	Paso3_circuit->AddText("Step #3");
	Paso3_circuit->Draw();
      
        //Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
      //Texto 1
	
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 35 therefore #color[9]{n} = 6");
      //Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
      //Texto 2
	
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q = 35");
	
	//Qbit|x>
	//Texto 3
	
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
	
	//Qbit|w>
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
	
	//Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|x>
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.72, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.67, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.61, "#font[62]{|0#GT}");
	
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.56, "#font[62]{|0#GT}");
      
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.51, "#font[62]{|0#GT}");
      
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.45, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.70, 0.80, 0.70);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.65, 0.80, 0.65);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.59, 0.80, 0.59);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.54, 0.80, 0.54);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
      lineaH9 = new TLine(0.17, 0.49, 0.80, 0.49);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
      lineaH10 = new TLine(0.17, 0.43, 0.80, 0.43);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	//Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{#color[1]{H}}");
	Hadamard1->Draw();
	
	//Dibujo de los estados de los qbits 
	//Qbit|w>
	
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.36, "#font[62]{|0#GT}");
	
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.31, "#font[62]{|0#GT}");
      
	l12->SetTextFont(42); 
	l12->SetTextColor(1);
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.14, 0.25, "#font[62]{|0#GT}");
      
	l13->SetTextFont(42); 
	l13->SetTextColor(1);
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.14, 0.19, "#font[62]{|0#GT}");
      
	l14->SetTextFont(42); 
	l14->SetTextColor(1);
	l14->SetTextAlign(12); 
	l14->DrawLatex(0.14, 0.13, "#font[62]{|0#GT}");
	
	 
	l15->SetTextFont(42); 
	l15->SetTextColor(1);
	l15->SetTextAlign(12); 
	l15->DrawLatex(0.14, 0.07, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|w>
	lineaH11 = new TLine(0.17, 0.34, 0.60, 0.34);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.29, 0.60, 0.29);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	lineaH13 = new TLine(0.17, 0.23, 0.60, 0.23);
	lineaH13->SetLineColor(kBlack);
	lineaH13->Draw();
	
	lineaH14 = new TLine(0.17, 0.17, 0.60, 0.17);
	lineaH14->SetLineColor(kBlack);
	lineaH14->Draw();
	
	lineaH15 = new TLine(0.17, 0.11, 0.60, 0.11);
	lineaH15->SetLineColor(kBlack);
	lineaH15->Draw();
	
	lineaH16 = new TLine(0.17, 0.05, 0.60, 0.05);
	lineaH16->SetLineColor(kBlack);
	lineaH16->Draw();
      //Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.03, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	CompuertaU->SetFillColor(kGray); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[1]{U_{a,N}}}");
	CompuertaU->Draw();
      //Compuerta de medida de|w>
	TPaveText *Medidaw= new TPaveText(0.52, 0.05, 0.62, 0.38); 
	Medidaw->SetTextFont(42);
	Medidaw->SetFillColor(kOrange-9); 
	Medidaw->SetShadowColor(1);
	Medidaw->SetMargin(0);
	Medidaw->AddText("");
	Medidaw->Draw();
	
	//Para el simbolo de medida
        Double_t xCenter = 0.57;  
        Double_t yCenter = 0.21;  
        Double_t radius = 0.04;   
    
        //Dibujar el circulo 
 	TEllipse *circle = new TEllipse(xCenter, yCenter, 0.03, 0.06, 0, 360);  
        circle->SetLineColor(2);  
        circle->SetLineWidth(2);
        circle->SetFillColor(kOrange-9);  
        circle->Draw();
	
	//Flechas
	flecha2 = new TArrow(0.57, 0.21, 0.59, 0.29, 0.01, ">");
	flecha2->SetLineColor(2);
     	flecha2->SetLineWidth(2);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
	
	//Cuadro para ocultar la mitad del circulo
	TPaveText *ocultar1= new TPaveText(0.5299999, 0.05, 0.62, 0.21); 
	ocultar1->SetTextFont(42);
	ocultar1->SetLineWidth(0);  
	ocultar1->SetFillColor(kOrange-9); 
	ocultar1->SetShadowColor(1);
	ocultar1->SetMargin(0);
	ocultar1->AddText("");
	ocultar1->Draw();
	
	//Cuadro para QFT+
	TPaveText *QFT= new TPaveText(0.64, 0.40, 0.73, 0.75); 
	QFT->SetTextFont(42);
	QFT->SetFillColor(kOrange-9); 
	QFT->SetShadowColor(1);
	QFT->SetMargin(0);
	QFT->AddText("#font[62]{#color[2]{QFT^{+}}}");
	QFT->Draw();
		
        //Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	TPaveText *Paso3_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso3_Circuito1_Exp->SetTextFont(42);
	Paso3_Circuito1_Exp->SetFillColor(0); 
	Paso3_Circuito1_Exp->SetShadowColor(kGray);
	Paso3_Circuito1_Exp->SetTextAlign(12);
	Paso3_Circuito1_Exp->SetMargin(0.01);
	Paso3_Circuito1_Exp->AddText("For #font[62]{step 3}, the measurements of the kets #font[62]{|w#GT} are first obtained, and then the #font[62]{Conjugate Transposed Quantum Fourier Transform} is performed");
	Paso3_Circuito1_Exp->AddText("or denoted as #font[62]{QFT^{+}} on the kets #font[62]{|x#GT}");
	Paso3_Circuito1_Exp->AddText("For the explanation of the #font[62]{QFT}, it is recommended to study another interface focused on its teaching, called #font[62]{QFTSoftEdu}, which belongs to");
	Paso3_Circuito1_Exp->AddText("#font[62]{FISINFOR} and developed by #font[62]{Ingrid Daiana Cuevas Ruiz}, a physics graduate from the #font[62]{Universidad Distrital}");
 	Paso3_Circuito1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1);
      }
        if(Breakopt==4){
      
        //Titulo
	TPaveText *Paso4_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso4_circuit->SetTextFont(62);
	Paso4_circuit->SetFillColor(kCyan-10); 
	Paso4_circuit->SetShadowColor(kGray);
	Paso4_circuit->SetMargin(0);
	Paso4_circuit->AddText("Step #4");
	Paso4_circuit->Draw();
      //Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
      //Texto 1
	
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 35 therefore #color[9]{n} = 6");
      //Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
      //Texto 2
	
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q = 35");
	
	//Qbit|x>
	//Texto 3
	
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
	
	//Qbit|w>
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
	
	//Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|x>
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.72, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.67, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.61, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.56, "#font[62]{|0#GT}");
      
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.51, "#font[62]{|0#GT}");
      
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.45, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.70, 0.80, 0.70);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.65, 0.80, 0.65);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.59, 0.80, 0.59);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.54, 0.80, 0.54);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
      lineaH9 = new TLine(0.17, 0.49, 0.80, 0.49);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
      lineaH10 = new TLine(0.17, 0.43, 0.80, 0.43);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	//Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{#color[1]{H}}");
	Hadamard1->Draw();
	
	//Dibujo de los estados de los qbits 
	//Qbit|w>
	
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.36, "#font[62]{|0#GT}");
	
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.31, "#font[62]{|0#GT}");
      
	l12->SetTextFont(42); 
	l12->SetTextColor(1);
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.14, 0.25, "#font[62]{|0#GT}");
      
	l13->SetTextFont(42); 
	l13->SetTextColor(1);
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.14, 0.19, "#font[62]{|0#GT}");
      
	l14->SetTextFont(42); 
	l14->SetTextColor(1);
	l14->SetTextAlign(12); 
	l14->DrawLatex(0.14, 0.13, "#font[62]{|0#GT}");
	 
	l15->SetTextFont(42); 
	l15->SetTextColor(1);
	l15->SetTextAlign(12); 
	l15->DrawLatex(0.14, 0.07, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|w>
	lineaH11 = new TLine(0.17, 0.34, 0.60, 0.34);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.29, 0.60, 0.29);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	lineaH13 = new TLine(0.17, 0.23, 0.60, 0.23);
	lineaH13->SetLineColor(kBlack);
	lineaH13->Draw();
	
	lineaH14 = new TLine(0.17, 0.17, 0.60, 0.17);
	lineaH14->SetLineColor(kBlack);
	lineaH14->Draw();
	
	lineaH15 = new TLine(0.17, 0.11, 0.60, 0.11);
	lineaH15->SetLineColor(kBlack);
	lineaH15->Draw();
	
	lineaH16 = new TLine(0.17, 0.05, 0.60, 0.05);
	lineaH16->SetLineColor(kBlack);
	lineaH16->Draw();
       //Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.03, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	
	CompuertaU->SetFillColor(kGray); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[1]{U_{a,N}}}");
	CompuertaU->Draw();
      //Compuerta de medida de|w>
	TPaveText *Medidaw= new TPaveText(0.52, 0.05, 0.62, 0.38); 
	Medidaw->SetTextFont(42);
	
	Medidaw->SetFillColor(kGray); 
	Medidaw->SetShadowColor(1);
	Medidaw->SetMargin(0);
	Medidaw->AddText("");
	Medidaw->Draw();
	
	//Para el simbolo de medida
        Double_t xCenter = 0.57;  
        Double_t yCenter = 0.21;  
        Double_t radius = 0.04;   
    
        //Dibujar el circulo 
 	TEllipse *circle = new TEllipse(xCenter, yCenter, 0.03, 0.06, 0, 360);  
        circle->SetLineColor(1);  
        circle->SetLineWidth(2);
        circle->SetFillColor(kGray);  
        circle->Draw();
	
	//Flechas
	flecha2 = new TArrow(0.57, 0.21, 0.59, 0.29, 0.01, ">");
	flecha2->SetLineColor(1);
     	flecha2->SetLineWidth(2);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
	
	//Cuadro para ocultar la mitad del circulo
	TPaveText *ocultar1= new TPaveText(0.5299999, 0.05, 0.62, 0.21); 
	ocultar1->SetTextFont(42);
	
	ocultar1->SetLineWidth(0);  
	ocultar1->SetFillColor(kGray); 
	ocultar1->SetShadowColor(1);
	ocultar1->SetMargin(0);
	ocultar1->AddText("");
	ocultar1->Draw();
	
	
	//Cuadro para QFT+
	TPaveText *QFT= new TPaveText(0.64, 0.40, 0.73, 0.75); 
	QFT->SetTextFont(42);
	QFT->SetFillColor(kGray); 
	QFT->SetShadowColor(1);
	QFT->SetMargin(0);
	QFT->AddText("#font[62]{#color[1]{QFT^{+}}}");
	QFT->Draw();
      //medida|x>
	TPaveText *medidax= new TPaveText(0.77, 0.40, 0.87, 0.75); 
	medidax->SetTextFont(42);
	medidax->SetFillColor(kOrange-9); 
	medidax->SetShadowColor(1);
	medidax->SetMargin(0);
	medidax->AddText("");
	medidax->Draw();
	
	//Diagrama de medida de x
	// Dibujar el circulo 
        circle1 = new TEllipse(0.82, 0.59, 0.03, 0.06, 0, 360);  
        circle1->SetLineColor(2);  
        circle1->SetLineWidth(2);
        circle1->SetFillColor(kOrange-9);  
        circle1->Draw();
	
	//Flechas
	flecha3 = new TArrow(0.82, 0.59, 0.85, 0.67, 0.01, ">");
	flecha3->SetLineColor(2);
     	flecha3->SetLineWidth(2);
     	flecha3->SetLineStyle(1);
     	flecha3->Draw();
	
	//Cuadro para ocultar la mitad del circulo 2
	TPaveText *ocultar2= new TPaveText(0.78, 0.40, 0.87, 0.59); 
	ocultar2->SetTextFont(42);
	ocultar2->SetLineWidth(0);  
	ocultar2->SetFillColor(kOrange-9); 
	ocultar2->SetShadowColor(1);
	ocultar2->SetMargin(0);
	ocultar2->AddText("");
	ocultar2->Draw();
      //Segundo canvas    	
     	TCanvas *ExpPaso4 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso4->SetFillColor(0);
	ExpPaso4->SetEditable(1);
	ExpPaso4->Clear();
	ExpPaso4->Update();
	TPaveText *Paso4_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso4_Circuito1_Exp->SetTextFont(42);
	Paso4_Circuito1_Exp->SetFillColor(0); 
	Paso4_Circuito1_Exp->SetShadowColor(kGray);
	Paso4_Circuito1_Exp->SetTextAlign(12);
	Paso4_Circuito1_Exp->SetMargin(0.01);
	Paso4_Circuito1_Exp->AddText("For #font[62]{step 4}, the measurement of the kets #font[62]{|x#GT} is performed, and at this point, the circuit is complete. To resolve any questions about the procedures");
	Paso4_Circuito1_Exp->AddText("for each gate, you can study the different cases, and if the doubt persists, then go to the #font[62]{CLEAR} button and then #font[62]{CONCEPTS}");
	Paso4_Circuito1_Exp->AddText("where you will find definitions of the concepts used in the #font[62]{Shor's algorithm} in a more basic and detailed manner for better understanding.");
 	Paso4_Circuito1_Exp->Draw();     	
     	
     	ExpPaso4->Update();
	ExpPaso4->SetEditable(1); 
      }
        }
        if(Breakopt == 5){
     	fTextButtonBACK->SetState(kButtonUp, kTRUE);
     	fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
     	DoCircuit();
     	CambioTab(1);
     	}
     break;
     case 11:{
	if(Breakopt==1){
      
        //Titulo
        TPaveText *Paso1_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso1_circuit->SetTextFont(62);
	Paso1_circuit->SetFillColor(kBlue-10); 
	Paso1_circuit->SetShadowColor(kGray);
	Paso1_circuit->SetMargin(0);
	Paso1_circuit->AddText("Step #1");
	Paso1_circuit->Draw();
      //Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
      //Texto 1
	
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 35 therefore #color[9]{n} = 6");
      //Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
     	
     	//Texto 2
	
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q = 35");
      //Qbit|x>
	//Texto 3
	
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
	
	//Qbit|w>
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
	
	//Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|x>
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.72, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.67, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.61, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.56, "#font[62]{|0#GT}");
      
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.51, "#font[62]{|0#GT}");
      
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.45, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.70, 0.50, 0.70);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.65, 0.50, 0.65);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.59, 0.50, 0.59);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.54, 0.50, 0.54);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
      lineaH9 = new TLine(0.17, 0.49, 0.50, 0.49);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
      lineaH10 = new TLine(0.17, 0.43, 0.50, 0.43);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
      //Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.30, 0.40, 0.40, 0.75); 
	Hadamard1->SetTextFont(42);
	Hadamard1->SetFillColor(kOrange-9); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#color[2]{H}");
	Hadamard1->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|w>
	
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.36, "#font[62]{|0#GT}");
	
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.31, "#font[62]{|0#GT}");
      
	l12->SetTextFont(42); 
	l12->SetTextColor(1);
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.14, 0.25, "#font[62]{|0#GT}");
      
	l13->SetTextFont(42); 
	l13->SetTextColor(1);
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.14, 0.19, "#font[62]{|0#GT}");
      
	l14->SetTextFont(42); 
	l14->SetTextColor(1);
	l14->SetTextAlign(12); 
	l14->DrawLatex(0.14, 0.13, "#font[62]{|0#GT}");
	 
	l15->SetTextFont(42); 
	l15->SetTextColor(1);
	l15->SetTextAlign(12); 
	l15->DrawLatex(0.14, 0.07, "#font[62]{|0#GT}");
	
	//Lineas de representacion de cada qbit|w>
	lineaH11 = new TLine(0.17, 0.34, 0.50, 0.34);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.29, 0.50, 0.29);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	lineaH13 = new TLine(0.17, 0.23, 0.50, 0.23);
	lineaH13->SetLineColor(kBlack);
	lineaH13->Draw();
	
	lineaH14 = new TLine(0.17, 0.17, 0.50, 0.17);
	lineaH14->SetLineColor(kBlack);
	lineaH14->Draw();
	
	lineaH15 = new TLine(0.17, 0.11, 0.50, 0.11);
	lineaH15->SetLineColor(kBlack);
	lineaH15->Draw();
	
	lineaH16 = new TLine(0.17, 0.05, 0.50, 0.05);
	lineaH16->SetLineColor(kBlack);
	lineaH16->Draw();
	
	//Detalles del circuito
	TPaveText *Circuit1= new TPaveText(0.60, 0.05, 0.90, 0.75); 
	Circuit1->SetTextFont(42);
	Circuit1->SetFillColor(kRed-10); 
	Circuit1->SetShadowColor(kGray);
	Circuit1->SetTextAlign(22);
	Circuit1->SetMargin(0);
	Circuit1->AddText("Due to the #font[62]{Shor's algorithm}, the kets #font[62]{|x#GT}");
	Circuit1->AddText("are defined as the number of #font[62]{n qubits}");
	Circuit1->AddText("and the kets #font[62]{|w#GT} are known as");
	Circuit1->AddText("#font[62]{auxiliary kets} and are used for");
	Circuit1->AddText("#font[62]{achieving greater precision} in the");
	Circuit1->AddText("#font[62]{result} of the #font[62]{factorization}");
	Circuit1->Draw();
      //Segundo canvas    	
     	TCanvas *ExpPaso1 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1->SetFillColor(0);
	ExpPaso1->SetEditable(1);
	ExpPaso1->Clear();
	ExpPaso1->Update();
	TPaveText *Paso1_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso1_Circuito1_Exp->SetTextFont(42);
	Paso1_Circuito1_Exp->SetFillColor(0); 
	Paso1_Circuito1_Exp->SetShadowColor(kGray);
	Paso1_Circuito1_Exp->SetTextAlign(12);
	Paso1_Circuito1_Exp->SetMargin(0.01);
	Paso1_Circuito1_Exp->AddText("For #font[62]{step 1}, it is necessary to define the number of #font[62]{n qubits} to use, which should be #font[62]{the nearest and greater number than the one to be factored}.");
	Paso1_Circuito1_Exp->AddText("After obtaining #font[62]{n}, the #font[62]{kets} #font[62]{|x#GT} and #font[62]{|w#GT} are separated, note that double #font[62]{n} is taken due to #font[62]{Shor's algorithm}.");
	Paso1_Circuito1_Exp->AddText("Then, the #font[62]{Hadamard gate} is applied only to the #font[62]{kets} #font[62]{|x#GT} to create the #font[62]{equiprobable superposition states}.");
 	Paso1_Circuito1_Exp->Draw();     	
     	
     	ExpPaso1->Update();
	ExpPaso1->SetEditable(1);
      }
        if(Breakopt==2){
      
        //Titulo
        TPaveText *Paso2_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso2_circuit->SetTextFont(62);
	Paso2_circuit->SetFillColor(kGreen-10); 
	Paso2_circuit->SetShadowColor(kGray);
	Paso2_circuit->SetMargin(0);
	Paso2_circuit->AddText("Step #2");
	Paso2_circuit->Draw();
      //Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
      //Texto 1
	
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 35 therefore #color[9]{n} = 6");
      //Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
      //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q = 35");
	
	//Qbit|x>
	//Texto 2
	
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
	
	//Qbit|w>
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
	
	//Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|x>
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.72, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.67, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.61, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.56, "#font[62]{|0#GT}");
      
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.51, "#font[62]{|0#GT}");
      
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.45, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.70, 0.50, 0.70);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.65, 0.50, 0.65);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.59, 0.50, 0.59);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.54, 0.50, 0.54);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
      lineaH9 = new TLine(0.17, 0.49, 0.50, 0.49);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
      lineaH10 = new TLine(0.17, 0.43, 0.50, 0.43);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	//Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{#color[1]{H}}");
	Hadamard1->Draw();
	
	//Dibujo de los estados de los qbits 
	//Qbit|w>
	
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.36, "#font[62]{|0#GT}");
	
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.31, "#font[62]{|0#GT}");
      
	l12->SetTextFont(42); 
	l12->SetTextColor(1);
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.14, 0.25, "#font[62]{|0#GT}");
      
	l13->SetTextFont(42); 
	l13->SetTextColor(1);
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.14, 0.19, "#font[62]{|0#GT}");
      
	l14->SetTextFont(42); 
	l14->SetTextColor(1);
	l14->SetTextAlign(12); 
	l14->DrawLatex(0.14, 0.13, "#font[62]{|0#GT}");
	 
	l15->SetTextFont(42); 
	l15->SetTextColor(1);
	l15->SetTextAlign(12); 
	l15->DrawLatex(0.14, 0.07, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|w>
	lineaH11 = new TLine(0.17, 0.34, 0.50, 0.34);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.29, 0.50, 0.29);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	lineaH13 = new TLine(0.17, 0.23, 0.50, 0.23);
	lineaH13->SetLineColor(kBlack);
	lineaH13->Draw();
	
	lineaH14 = new TLine(0.17, 0.17, 0.50, 0.17);
	lineaH14->SetLineColor(kBlack);
	lineaH14->Draw();
	
	lineaH15 = new TLine(0.17, 0.11, 0.50, 0.11);
	lineaH15->SetLineColor(kBlack);
	lineaH15->Draw();
	
	lineaH16 = new TLine(0.17, 0.05, 0.50, 0.05);
	lineaH16->SetLineColor(kBlack);
	lineaH16->Draw();
       //Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.03, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	CompuertaU->SetFillColor(kOrange-9); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[2]{U_{a,N}}}");
	CompuertaU->Draw();
		
        //Segundo canvas    	
     	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	TPaveText *Paso2_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso2_Circuito1_Exp->SetTextFont(42);
	Paso2_Circuito1_Exp->SetFillColor(0); 
	Paso2_Circuito1_Exp->SetShadowColor(kGray);
	Paso2_Circuito1_Exp->SetTextAlign(12);
	Paso2_Circuito1_Exp->SetMargin(0.01);
	Paso2_Circuito1_Exp->AddText("For #font[62]{step 2}, the gate #font[62]{U_{a,N}} is applied, which affects and performs operations on all the kets to determine possible periodicity values,");
	Paso2_Circuito1_Exp->AddText("denoted as #font[62]{r}, from the function #font[62]{F = a^{r}(mod N)} in Shor's #font[62]{algorithm}. Due to the complexity of the gate #font[62]{U_{a,N}} in many cases");
	Paso2_Circuito1_Exp->AddText("it is treated as a #font[62]{black box}, and its explanations are often unclear. It is recommended to review #font[62]{modular algebra} and the operations performed in the");
	Paso2_Circuito1_Exp->AddText("tabs #font[62]{CLASSICAL} and #font[62]{QUANTUM} to compare the procedures that the gate performs on the #font[62]{qubits}.");
 	Paso2_Circuito1_Exp->Draw();     	
     	
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(1);
      
        }
        if(Breakopt==3){
      
        //Titulo
        TPaveText *Paso3_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_circuit->SetTextFont(62);
	Paso3_circuit->SetFillColor(kMagenta-10); 
	Paso3_circuit->SetShadowColor(kGray);
	Paso3_circuit->SetMargin(0);
	Paso3_circuit->AddText("Step #3");
	Paso3_circuit->Draw();
      
        //Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
      //Texto 1
	
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 35 therefore #color[9]{n} = 6");
      //Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
      //Texto 2
	
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q = 35");
	
	//Qbit|x>
	//Texto 2
	
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
	
	//Qbit|w>
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
	
	//Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|x>
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.72, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.67, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.61, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.56, "#font[62]{|0#GT}");
      
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.51, "#font[62]{|0#GT}");
      
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.45, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.70, 0.80, 0.70);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.65, 0.80, 0.65);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.59, 0.80, 0.59);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.54, 0.80, 0.54);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
      lineaH9 = new TLine(0.17, 0.49, 0.80, 0.49);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
      lineaH10 = new TLine(0.17, 0.43, 0.80, 0.43);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	//Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{#color[1]{H}}");
	Hadamard1->Draw();
	
	//Dibujo de los estados de los qbits 
	//Qbit|w>
	
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.36, "#font[62]{|0#GT}");
	
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.31, "#font[62]{|0#GT}");
      
	l12->SetTextFont(42); 
	l12->SetTextColor(1);
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.14, 0.25, "#font[62]{|0#GT}");
      
	l13->SetTextFont(42); 
	l13->SetTextColor(1);
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.14, 0.19, "#font[62]{|0#GT}");
      
	l14->SetTextFont(42); 
	l14->SetTextColor(1);
	l14->SetTextAlign(12); 
	l14->DrawLatex(0.14, 0.13, "#font[62]{|0#GT}");
	 
	l15->SetTextFont(42); 
	l15->SetTextColor(1);
	l15->SetTextAlign(12); 
	l15->DrawLatex(0.14, 0.07, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|w>
	lineaH11 = new TLine(0.17, 0.34, 0.60, 0.34);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.29, 0.60, 0.29);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	lineaH13 = new TLine(0.17, 0.23, 0.60, 0.23);
	lineaH13->SetLineColor(kBlack);
	lineaH13->Draw();
	
	lineaH14 = new TLine(0.17, 0.17, 0.60, 0.17);
	lineaH14->SetLineColor(kBlack);
	lineaH14->Draw();
	
	lineaH15 = new TLine(0.17, 0.11, 0.60, 0.11);
	lineaH15->SetLineColor(kBlack);
	lineaH15->Draw();
	
	lineaH16 = new TLine(0.17, 0.05, 0.60, 0.05);
	lineaH16->SetLineColor(kBlack);
	lineaH16->Draw();
       //Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.03, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	
	CompuertaU->SetFillColor(kGray); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[1]{U_{a,N}}}");
	CompuertaU->Draw();
      //Compuerta de medida de|w>
	TPaveText *Medidaw= new TPaveText(0.52, 0.05, 0.62, 0.38); 
	Medidaw->SetTextFont(42);
	
	Medidaw->SetFillColor(kOrange-9); 
	Medidaw->SetShadowColor(1);
	Medidaw->SetMargin(0);
	Medidaw->AddText("");
	Medidaw->Draw();
	
	//Para el simbolo de medida
        Double_t xCenter = 0.57;  
        Double_t yCenter = 0.21;  
        Double_t radius = 0.04;   
    
        //Dibujar el circulo 
 	TEllipse *circle = new TEllipse(xCenter, yCenter, 0.03, 0.06, 0, 360);  
        circle->SetLineColor(2);  
        circle->SetLineWidth(2);
        circle->SetFillColor(kOrange-9);  
        circle->Draw();
	
	//Flechas
	flecha2 = new TArrow(0.57, 0.21, 0.59, 0.29, 0.01, ">");
	flecha2->SetLineColor(2);
     	flecha2->SetLineWidth(2);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
	
	//Cuadro para ocultar la mitad del circulo
	TPaveText *ocultar1= new TPaveText(0.5299999, 0.05, 0.62, 0.21); 
	ocultar1->SetTextFont(42);
	ocultar1->SetLineWidth(0);  
	ocultar1->SetFillColor(kOrange-9); 
	ocultar1->SetShadowColor(1);
	ocultar1->SetMargin(0);
	ocultar1->AddText("");
	ocultar1->Draw();
	
	//Cuadro para QFT+
	TPaveText *QFT= new TPaveText(0.64, 0.40, 0.73, 0.75); 
	QFT->SetTextFont(42);
	QFT->SetFillColor(kOrange-9); 
	QFT->SetShadowColor(1);
	QFT->SetMargin(0);
	QFT->AddText("#font[62]{#color[2]{QFT^{+}}}");
	QFT->Draw();
		
		
        //Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	TPaveText *Paso3_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso3_Circuito1_Exp->SetTextFont(42);
	Paso3_Circuito1_Exp->SetFillColor(0); 
	Paso3_Circuito1_Exp->SetShadowColor(kGray);
	Paso3_Circuito1_Exp->SetTextAlign(12);
	Paso3_Circuito1_Exp->SetMargin(0.01);
	Paso3_Circuito1_Exp->AddText("For #font[62]{step 3}, the measurements of the kets #font[62]{|w#GT} are first obtained, and then the #font[62]{Conjugate Transposed Quantum Fourier Transform} is performed");
	Paso3_Circuito1_Exp->AddText("or denoted as #font[62]{QFT^{+}} on the kets #font[62]{|x#GT}");
	Paso3_Circuito1_Exp->AddText("For the explanation of the #font[62]{QFT}, it is recommended to study another interface focused on its teaching, called #font[62]{QFTSoftEdu}, which belongs to");
	Paso3_Circuito1_Exp->AddText("#font[62]{FISINFOR} and developed by #font[62]{Ingrid Daiana Cuevas Ruiz}, a physics graduate from the #font[62]{Universidad Distrital}");
 	Paso3_Circuito1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1);
      }
        if(Breakopt==4){
      
        //Titulo
	TPaveText *Paso4_circuit = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso4_circuit->SetTextFont(62);
	Paso4_circuit->SetFillColor(kCyan-10); 
	Paso4_circuit->SetShadowColor(kGray);
	Paso4_circuit->SetMargin(0);
	Paso4_circuit->AddText("Step #4");
	Paso4_circuit->Draw();
      //Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
      //Texto 1
	
	
	l1->SetTextColor(1);
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.82, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 35 therefore #color[9]{n} = 6");
      //Flecha 1
	flecha1 = new TArrow(0.57, 0.82, 0.61, 0.82, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
      //Texto 2
	
	l2->SetTextFont(42); 
	l2->SetTextColor(1);
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.63, 0.82, "#font[62]{Number to factorize:} N = P*Q = 35");
	
	//Qbit|x>
	//Texto 2
	
	l3->SetTextFont(42); 
	l3->SetTextColor(1);
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "#font[62]{|x#GT}");
	
	//Qbit|w>
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.25, "#font[62]{|w#GT}");
	
	//Dibujando las lineas para definir cada ket
	
	lineaV1 = new TLine(0.12, 0.40, 0.12, 0.72);
	lineaV1->SetLineColor(kBlack);
	lineaV1->Draw();
	
	lineaV2 = new TLine(0.12, 0.02, 0.12, 0.37);
	lineaV2->SetLineColor(kBlack);
	lineaV2->Draw();
	
	//lineas horizontales cortas
	lineaH1 = new TLine(0.12, 0.72, 0.13, 0.72);
	lineaH1->SetLineColor(kBlack);
	lineaH1->Draw();
	
	lineaH2 = new TLine(0.12, 0.40, 0.13, 0.40);
	lineaH2->SetLineColor(kBlack);
	lineaH2->Draw();
	
	lineaH3 = new TLine(0.12, 0.37, 0.13, 0.37);
	lineaH3->SetLineColor(kBlack);
	lineaH3->Draw();
	
	lineaH4 = new TLine(0.12, 0.02, 0.13, 0.02);
	lineaH4->SetLineColor(kBlack);
	lineaH4->Draw();
      //Dibujo de los estados de los qbits 
	//Qbit|x>
	
	l4->SetTextFont(42); 
	l4->SetTextColor(1);
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.14, 0.72, "#font[62]{|0#GT}");
	
	l5->SetTextFont(42); 
	l5->SetTextColor(1);
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.14, 0.67, "#font[62]{|0#GT}");
	
	l6->SetTextFont(42); 
	l6->SetTextColor(1);
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.14, 0.61, "#font[62]{|0#GT}");
	
	l7->SetTextFont(42); 
	l7->SetTextColor(1);
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.14, 0.56, "#font[62]{|0#GT}");
      
	l8->SetTextFont(42); 
	l8->SetTextColor(1);
	l8->SetTextAlign(12); 
	l8->DrawLatex(0.14, 0.51, "#font[62]{|0#GT}");
      
	l9->SetTextFont(42); 
	l9->SetTextColor(1);
	l9->SetTextAlign(12); 
	l9->DrawLatex(0.14, 0.45, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|x>
	lineaH5 = new TLine(0.17, 0.70, 0.80, 0.70);
	lineaH5->SetLineColor(kBlack);
	lineaH5->Draw();
	
	lineaH6 = new TLine(0.17, 0.65, 0.80, 0.65);
	lineaH6->SetLineColor(kBlack);
	lineaH6->Draw();
	
	lineaH7 = new TLine(0.17, 0.59, 0.80, 0.59);
	lineaH7->SetLineColor(kBlack);
	lineaH7->Draw();
	
	lineaH8 = new TLine(0.17, 0.54, 0.80, 0.54);
	lineaH8->SetLineColor(kBlack);
	lineaH8->Draw();
      lineaH9 = new TLine(0.17, 0.49, 0.80, 0.49);
	lineaH9->SetLineColor(kBlack);
	lineaH9->Draw();
      lineaH10 = new TLine(0.17, 0.43, 0.80, 0.43);
	lineaH10->SetLineColor(kBlack);
	lineaH10->Draw();
	
	//Compuertas hadamard
	TPaveText *Hadamard1= new TPaveText(0.25, 0.40, 0.33, 0.75); 
	Hadamard1->SetTextFont(42);
	Hadamard1->SetFillColor(kGray); 
	Hadamard1->SetShadowColor(kGray);
	Hadamard1->SetTextAlign(12);
	Hadamard1->AddText("#font[62]{#color[1]{H}}");
	Hadamard1->Draw();
	
	//Dibujo de los estados de los qbits 
	//Qbit|w>
	
	l10->SetTextFont(42); 
	l10->SetTextColor(1);
	l10->SetTextAlign(12); 
	l10->DrawLatex(0.14, 0.36, "#font[62]{|0#GT}");
	
	l11->SetTextFont(42); 
	l11->SetTextColor(1);
	l11->SetTextAlign(12); 
	l11->DrawLatex(0.14, 0.31, "#font[62]{|0#GT}");
      
	l12->SetTextFont(42); 
	l12->SetTextColor(1);
	l12->SetTextAlign(12); 
	l12->DrawLatex(0.14, 0.25, "#font[62]{|0#GT}");
      
	l13->SetTextFont(42); 
	l13->SetTextColor(1);
	l13->SetTextAlign(12); 
	l13->DrawLatex(0.14, 0.19, "#font[62]{|0#GT}");
      
	l14->SetTextFont(42); 
	l14->SetTextColor(1);
	l14->SetTextAlign(12); 
	l14->DrawLatex(0.14, 0.13, "#font[62]{|0#GT}");
	 
	l15->SetTextFont(42); 
	l15->SetTextColor(1);
	l15->SetTextAlign(12); 
	l15->DrawLatex(0.14, 0.07, "#font[62]{|0#GT}");
      //Lineas de representacion de cada qbit|w>
	lineaH11 = new TLine(0.17, 0.34, 0.60, 0.34);
	lineaH11->SetLineColor(kBlack);
	lineaH11->Draw();
	
	lineaH12 = new TLine(0.17, 0.29, 0.60, 0.29);
	lineaH12->SetLineColor(kBlack);
	lineaH12->Draw();
	
	lineaH13 = new TLine(0.17, 0.23, 0.60, 0.23);
	lineaH13->SetLineColor(kBlack);
	lineaH13->Draw();
	
	lineaH14 = new TLine(0.17, 0.17, 0.60, 0.17);
	lineaH14->SetLineColor(kBlack);
	lineaH14->Draw();
	
	lineaH15 = new TLine(0.17, 0.11, 0.60, 0.11);
	lineaH15->SetLineColor(kBlack);
	lineaH15->Draw();
	
	lineaH16 = new TLine(0.17, 0.05, 0.60, 0.05);
	lineaH16->SetLineColor(kBlack);
	lineaH16->Draw();
       //Compuerta Uf_a,N
	TPaveText *CompuertaU= new TPaveText(0.38, 0.03, 0.48, 0.75); 
	CompuertaU->SetTextFont(42);
	CompuertaU->SetFillColor(kGray); 
	CompuertaU->SetShadowColor(kGray);
	CompuertaU->SetMargin(0);
	CompuertaU->AddText("#font[62]{#color[1]{U_{a,N}}}");
	CompuertaU->Draw();
      //Compuerta de medida de|w>
	TPaveText *Medidaw= new TPaveText(0.52, 0.05, 0.62, 0.38); 
	Medidaw->SetTextFont(42);
	Medidaw->SetFillColor(kGray); 
	Medidaw->SetShadowColor(1);
	Medidaw->SetMargin(0);
	Medidaw->AddText("");
	Medidaw->Draw();
	
	//Para el simbolo de medida
        Double_t xCenter = 0.57;  
        Double_t yCenter = 0.21;  
        Double_t radius = 0.04;   
    
        //Dibujar el circulo 
 	TEllipse *circle = new TEllipse(xCenter, yCenter, 0.03, 0.06, 0, 360);  
        circle->SetLineColor(1);  
        circle->SetLineWidth(2);
        circle->SetFillColor(kGray);  
        circle->Draw();
	
	//Flechas
	flecha2 = new TArrow(0.57, 0.21, 0.59, 0.29, 0.01, ">");
	flecha2->SetLineColor(1);
     	flecha2->SetLineWidth(2);
     	flecha2->SetLineStyle(1);
     	flecha2->Draw();
	
	//Cuadro para ocultar la mitad del circulo
	TPaveText *ocultar1= new TPaveText(0.5299999, 0.05, 0.62, 0.21); 
	ocultar1->SetTextFont(42);
	ocultar1->SetLineWidth(0);  
	ocultar1->SetFillColor(kGray); 
	ocultar1->SetShadowColor(1);
	ocultar1->SetMargin(0);
	ocultar1->AddText("");
	ocultar1->Draw();
	
	
	//Cuadro para QFT+
	TPaveText *QFT= new TPaveText(0.64, 0.40, 0.73, 0.75); 
	QFT->SetTextFont(42);
	QFT->SetFillColor(kGray); 
	QFT->SetShadowColor(1);
	QFT->SetMargin(0);
	QFT->AddText("#font[62]{#color[1]{QFT^{+}}}");
	QFT->Draw();
      //medida|x>
	TPaveText *medidax= new TPaveText(0.77, 0.40, 0.87, 0.75); 
	medidax->SetTextFont(42);
	medidax->SetFillColor(kOrange-9); 
	medidax->SetShadowColor(1);
	medidax->SetMargin(0);
	medidax->AddText("");
	medidax->Draw();
	
	//Diagrama de medida de x
	// Dibujar el circulo 
        circle1 = new TEllipse(0.82, 0.59, 0.03, 0.06, 0, 360);  
        circle1->SetLineColor(2);  
        circle1->SetLineWidth(2);
        circle1->SetFillColor(kOrange-9);  
        circle1->Draw();
	
	//Flechas
	flecha3 = new TArrow(0.82, 0.59, 0.85, 0.67, 0.01, ">");
	flecha3->SetLineColor(2);
     	flecha3->SetLineWidth(2);
     	flecha3->SetLineStyle(1);
     	flecha3->Draw();
	
	//Cuadro para ocultar la mitad del circulo 2
	TPaveText *ocultar2= new TPaveText(0.78, 0.40, 0.87, 0.59); 
	ocultar2->SetTextFont(42);
	
	ocultar2->SetLineWidth(0);  
	ocultar2->SetFillColor(kOrange-9); 
	ocultar2->SetShadowColor(1);
	ocultar2->SetMargin(0);
	ocultar2->AddText("");
	ocultar2->Draw();
      //Segundo canvas    	
     	TCanvas *ExpPaso4 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso4->SetFillColor(0);
	ExpPaso4->SetEditable(1);
	ExpPaso4->Clear();
	ExpPaso4->Update();
	TPaveText *Paso4_Circuito1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso4_Circuito1_Exp->SetTextFont(42);
	Paso4_Circuito1_Exp->SetFillColor(0); 
	Paso4_Circuito1_Exp->SetShadowColor(kGray);
	Paso4_Circuito1_Exp->SetTextAlign(12);
	Paso4_Circuito1_Exp->SetMargin(0.01);
	Paso4_Circuito1_Exp->AddText("For #font[62]{step 4}, the measurement of the kets #font[62]{|x#GT} is performed, and at this point, the circuit is complete. To resolve any questions about the procedures");
	Paso4_Circuito1_Exp->AddText("for each gate, you can study the different cases, and if the doubt persists, then go to the #font[62]{CLEAR} button and then #font[62]{CONCEPTS}");
	Paso4_Circuito1_Exp->AddText("where you will find definitions of the concepts used in the #font[62]{Shor's algorithm} in a more basic and detailed manner for better understanding.");
 	Paso4_Circuito1_Exp->Draw();     	
     	
     	ExpPaso4->Update();
	ExpPaso4->SetEditable(1); 
      
        }
	}
	if(Breakopt == 5){
     	fTextButtonBACK->SetState(kButtonUp, kTRUE);
     	fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
     	DoCircuit();
     	CambioTab(1);
     	}
     break;
  }
}

canvas2->Update();
}
/*************************************************************/
void MyMainFrame::DoQuantum(){

fTextButtonBACK->SetState(kButtonDisabled, kTRUE);

Int_t Valueopt1 = fComboBoxNUMSFACTORS->GetSelected();
Int_t Valueopt2 = fComboBoxVALUESA->GetSelected();

	//Inicio de los paso clasicos
	TCanvas *Quantum = fRootEmbeddedCanvasDRAWQUANTUM->GetCanvas();
	Quantum->SetFillColor(0);
	Quantum->SetEditable(1);
	Quantum->Clear();
	Quantum->cd();

	TPaveText *Pasos_Quantum = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Pasos_Quantum->SetTextFont(62);
	Pasos_Quantum->SetFillColor(0); 
	Pasos_Quantum->SetShadowColor(kGray);
	Pasos_Quantum->SetMargin(0);
	Pasos_Quantum->AddText("Steps of Shor's Algorithm in a #color[2]{Qua}ntum #color[4]{For}m");
	Pasos_Quantum->Draw();

	//Creacion de las separaciones 
	TPad *paso1 = new TPad("pad1","This is pad1",0.01 ,0.42, 0.50, 0.83); 
	paso1->SetFillColor(0);
	paso1->Draw();
	
	TPad *paso2 = new TPad("pad2","This is pad2",0.51 ,0.42, 0.99, 0.83); 
	paso2->SetFillColor(0);
	paso2->Draw();

	TPad *paso3 = new TPad("pad3","This is pad3",0.01, 0.01, 0.50, 0.40);
	paso3->SetFillColor(0);
	paso3->Draw();
	
	TPad *paso4 = new TPad("pad3","This is pad3",0.51, 0.01, 0.99, 0.40);
	paso4->SetFillColor(0);
	paso4->Draw();
	
	//Texto dentro del pad1
	paso1->cd();
	TPaveText *TPTPaso1 = new TPaveText(0.001 ,0.009, 0.995, 0.995); 
 	TPTPaso1->SetTextFont(42);
	TPTPaso1->SetFillColor(kBlue-10); 
	TPTPaso1->SetShadowColor(kGray);
	TPTPaso1->SetTextAlign(12);
	TPTPaso1->SetMargin(0.04);
	TPTPaso1->AddText("");
 	TPTPaso1->AddText("#font[62]{#scale[1.7]{STEP #1}}");
 	TPTPaso1->AddText("");
 	TPTPaso1->AddText("Determine the number of #font[62]{qbits} #font[62]{n} such that #font[62]{N = P*Q = 2^{n}}");
 	TPTPaso1->AddText("Define the #font[62]{kets} #font[62]{|x#GT} and #font[62]{|w#GT} and initialize them in the state #font[62]{|0#GT}, having");
 	TPTPaso1->AddText("#font[62]{|x#GT} -> #font[62]{|0#GT} and #font[62]{|w#GT} -> #font[62]{|0#GT}");
 	TPTPaso1->AddText("Apply the #font[62]{Hadamard gate} to the qbits #font[62]{|x#GT}");
 	TPTPaso1->AddText("");
 	TPTPaso1->Draw();
 	
 	//Texto dentro del pad2
	paso2->cd();
	TPaveText *TPTPaso2 = new TPaveText(0.001 ,0.009, 0.995, 0.995); 
 	TPTPaso2->SetTextFont(42);
	TPTPaso2->SetFillColor(kGreen-10); 
	TPTPaso2->SetShadowColor(kGray);
	TPTPaso2->SetTextAlign(12);
	TPTPaso2->SetMargin(0.04);
 	TPTPaso2->AddText("");
 	TPTPaso2->AddText("#font[62]{#scale[1.7]{STEP #2}}");
 	TPTPaso2->AddText("");
 	TPTPaso2->AddText("Apply the gate #font[62]{U_{a,N}} to perform modular arithmetic");
 	TPTPaso2->AddText("#font[62]{F_{a,N} = a^{r}(mod N)} on the kets #font[62]{|w#GT}.");
 	TPTPaso2->AddText("In Boolean algebra, this operation is known as");
 	TPTPaso2->AddText("#font[62]{Modulo 2 Sum}.");
 	TPTPaso2->AddText("In quantum computing, it is known as the #font[62]{XOR gate}.");
 	TPTPaso2->AddText("");
 	TPTPaso2->Draw();
 	
 	//Texto dentro del pad3
 	paso3->cd();
	TPaveText *TPTPaso3 = new TPaveText(0.001 ,0.009, 0.995, 0.995); 
 	TPTPaso3->SetTextFont(42);
	TPTPaso3->SetFillColor(kMagenta-10); 
	TPTPaso3->SetShadowColor(kGray);
	TPTPaso3->SetTextAlign(12);
	TPTPaso3->SetMargin(0.04);
 	TPTPaso3->AddText("");
 	TPTPaso3->AddText("#font[62]{#scale[1.7]{STEP #3}}");
 	TPTPaso3->AddText("");
 	TPTPaso3->AddText("For step 3, the resulting matrix is created to obtain the possible");
 	TPTPaso3->AddText("results of the kets #font[62]{|w#GT}.");
 	TPTPaso3->AddText("Then, the #font[62]{Quantum Fourier Transform dagger} is applied over the kets #font[62]{|x#GT}.");
 	TPTPaso3->AddText("");
 	TPTPaso3->Draw();
 	
 	//Texto dentro del pad4
 	paso4->cd();
	TPaveText *TPTPaso4 = new TPaveText(0.001 ,0.009, 0.995, 0.995); 
 	TPTPaso4->SetTextFont(42);
	TPTPaso4->SetFillColor(kCyan-10); 
	TPTPaso4->SetShadowColor(kGray);
	TPTPaso4->SetTextAlign(12);
	TPTPaso4->SetMargin(0.04);
 	TPTPaso4->AddText("");
 	TPTPaso4->AddText("#font[62]{#scale[1.7]{STEP #4}}");
 	TPTPaso4->AddText("");
 	TPTPaso4->AddText("For step 4, the measurements of the #font[62]{kets} #font[62]{|x#GT} are denoted");
 	TPTPaso4->AddText("as #font[62]{M}, and each result is evaluated in the following expression #font[62]{ #frac{jN}{r} = M }");
 	TPTPaso4->AddText("to determine the value #font[62]{r} and substitute it into #font[62]{ X#equiv a^{#frac{r}{2}}(mod N) }.");
 	TPTPaso4->AddText("Finally, #font[62]{ P = GCD(X+1, N) } and #font[62]{ Q = GCD(X-1, N) } are calculated to");
 	TPTPaso4->AddText("#font[62]{obtain the factorization.}");
 	TPTPaso4->AddText("");
 	TPTPaso4->Draw();

	Quantum->Update();
        Quantum->SetEditable(1);
}
/*************************************************************/
void MyMainFrame::CondQuantum(){

Int_t Valueopt1 = fComboBoxNUMSFACTORS->GetSelected();
Int_t Valueopt2 = fComboBoxVALUESA->GetSelected();

TCanvas *canvas3 = fRootEmbeddedCanvasDRAWQUANTUM->GetCanvas();
canvas3->Clear();
canvas3->cd();

if(Valueopt1 == 15){
  switch (Valueopt2){
     case 13:{
     	if(Breakopt==1){
	  
	//Titulo
	TPaveText *Paso1_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso1_cuantico->SetTextFont(62);
	Paso1_cuantico->SetFillColor(kBlue-10); 
	Paso1_cuantico->SetShadowColor(kGray);
	Paso1_cuantico->SetMargin(0);
	Paso1_cuantico->AddText("Step #1");
	Paso1_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
	
	//Texto 1
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 16 #color[9]{n = 4}");
	
	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "States: #font[62]{#color[1]{|x#GT^{#otimes#color[9]{4}}}}#font[62]{#color[1]{|w#GT^{#otimes#color[9]{4}}}}");
	
	//Flecha 1
	flecha1 = new TArrow(0.23, 0.60, 0.37, 0.60, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	//Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.40, 0.60, "#font[62]{#color[1]{|0#GT^{#otimes#color[9]{4}}}}#font[62]{#color[1]{|0#GT^{#otimes#color[9]{4}}}}");
	
	//Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.03, 0.40, "Applying the #font[62]{#color[2]{Hadamard}} gate to the kets #font[62]{#color[1]{|x#GT^{#otimes#color[9]{4}}}}");
	
	//Texto 6
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.08, 0.25, "[#color[2]{H^{#otimes 4}}#color[1]{|x#GT^{#otimes#color[9]{4}}}]#color[1]{|w#GT^{#otimes#color[9]{4}}} = #frac{1}{#sqrt{16}}[#sum_{x=0}^{15}#color[1]{|x#GT^{#otimes#color[9]{4}}}]#color[1]{|0#GT^{#otimes#color[9]{4}}}");
	
	//Cuadros explicativos
	TPaveText *Estados_example_1 = new TPaveText(0.55, 0.5, 0.99, 0.75); 
	Estados_example_1->SetTextFont(42);
	Estados_example_1->SetFillColor(kRed-10); 
	Estados_example_1->SetShadowColor(kGray);
	Estados_example_1->SetMargin(0);
	Estados_example_1->AddText("");
	Estados_example_1->AddText("The initial states of #font[62]{|x#GT and |w#GT}");
	Estados_example_1->AddText("will always be in #font[62]{|0#GT}");
	Estados_example_1->AddText("");
	Estados_example_1->Draw();
	
	TPaveText *Comp_H = new TPaveText(0.55, 0.4, 0.99, 0.1); 
	Comp_H->SetTextFont(42);
	Comp_H->SetFillColor(kMagenta-10); 
	Comp_H->SetShadowColor(kGray);
	Comp_H->SetMargin(0);
	Comp_H->AddText("");
	Comp_H->AddText("The #font[62]{Hadamard} operation creates");
	Comp_H->AddText("the states in #font[62]{superposition} that are");
	Comp_H->AddText("#font[62]{equiprobable}.");
	Comp_H->AddText("");
	Comp_H->Draw();
	
	//Segundo canvas    	
     	TCanvas *ExpPaso1 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1->SetFillColor(0);
	ExpPaso1->SetEditable(1);
	ExpPaso1->Clear();
	ExpPaso1->Update();
	
	TPaveText *Paso1_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.999, 0.99);
	Paso1_Quantum1_Exp->SetTextFont(42);
	Paso1_Quantum1_Exp->SetFillColor(0); 
	Paso1_Quantum1_Exp->SetShadowColor(kGray);
	Paso1_Quantum1_Exp->SetTextAlign(12);
	Paso1_Quantum1_Exp->SetMargin(0.01);
	Paso1_Quantum1_Exp->AddText("For #font[62]{Step 1}, the #font[62]{number of states} of the denoted system is defined as #font[62]{N*}, where the number of #font[62]{Qubits} #font[62]{n} is determined.");
	Paso1_Quantum1_Exp->AddText("The possible states are written in the form of a #font[62]{summation} due to the #font[62]{Hadamard} gate and the use of #font[62]{Dirac notation with the power}");
	Paso1_Quantum1_Exp->AddText("#font[62]{of the tensor product and the number n} indicates the number of #font[62]{Qubits} used to represent each possible state, thus the representation of a state");
	Paso1_Quantum1_Exp->AddText("random within that interval will be in the form: #font[62]{|x#GT^{#otimes n} = |x#GT#otimes|x#GT#otimes|x#GT#otimes|x#GT ...#otimes|x#GT (n times)}");
 	Paso1_Quantum1_Exp->Draw();     	
     	
     	ExpPaso1->Update();
	ExpPaso1->SetEditable(1); 
	   	
	}
	if(Breakopt==2){
	//Titulo
        TPaveText *Paso2_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso2_cuantico->SetTextFont(62);
	Paso2_cuantico->SetFillColor(kGreen-10); 
	Paso2_cuantico->SetShadowColor(kGray);
	Paso2_cuantico->SetMargin(0);
	Paso2_cuantico->AddText("Step #2");
	Paso2_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
	
	//Texto 1
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 16 #color[9]{n = 4}");
	
	//Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.03, 0.65, "By applying the operator #color[2]{U_{a,N}} we obtain:");
	
	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.55, "#color[2]{U_{a,N}}(#frac{1}{#sqrt{16}}[#sum_{x=0}^{15}|x#GT^{#otimes#color[9]{4}}]|0#GT^{#otimes#color[9]{4}}) = #frac{1}{#sqrt{16}}[#sum_{x=0}^{15}|x#GT^{#otimes#color[9]{4}}]#color[2]{|0#oplusF_{a,N}#GT^{#otimes#color[9]{4}}}");
	
	//Cuadros explicativos
	TPaveText *Operador_Uf = new TPaveText(0.55, 0.40, 0.99, 0.65); 
	Operador_Uf->SetTextFont(42);
	Operador_Uf->SetFillColor(kMagenta-8); 
	Operador_Uf->SetShadowColor(kGray);
	Operador_Uf->SetMargin(0);
	Operador_Uf->AddText("");
	Operador_Uf->AddText("#font[62]{Modulo 2 Addition Property}");
	Operador_Uf->AddText("");
	Operador_Uf->AddText("#font[62]{|0#oplusF_{a,N}#GT^{#otimes#color[9]{4}} =|F_{a,N}#GT^{#otimes#color[9]{4}} =|a^{r}mod N#GT^{#otimes#color[9]{4}}}");
	Operador_Uf->AddText("");
	Operador_Uf->Draw();
	
	//Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.30, "The final result after substituting the values is:");
	
	//Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.2, 0.20, "#color[2]{U_{a,N}}(#frac{1}{#sqrt{16}}[#sum_{x=0}^{15}|x#GT^{#otimes#color[9]{4}}]|0#GT^{#otimes#color[9]{4}}) = #frac{1}{#sqrt{16}}[#sum_{x=0}^{15}|x#GT^{#otimes#color[9]{4}}]#color[2]{|13^{r}mod15#GT^{#otimes#color[9]{4}}}");
	
	//Segundo canvas    	
     	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	
	TPaveText *Paso2_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.999, 0.99);
	Paso2_Quantum1_Exp->SetTextFont(42);
	Paso2_Quantum1_Exp->SetFillColor(0); 
	Paso2_Quantum1_Exp->SetShadowColor(kGray);
	Paso2_Quantum1_Exp->SetTextAlign(12);
	Paso2_Quantum1_Exp->SetMargin(0.01);
	Paso2_Quantum1_Exp->AddText("For #font[62]{step 2}, the unitary operator #font[62]{U_{a,N}} is applied to the previous result. This, in turn, performs the #font[62]{modulo 2 addition} operation");
	Paso2_Quantum1_Exp->AddText("which satisfies an important property because the ket #font[62]{|w#GT} is initialized in the state #font[62]{|0#GT}, as shown in the box.");
	Paso2_Quantum1_Exp->AddText("The final result applies the function #font[62]{F_{a,N} = a^{r}mod N}, which is #font[62]{periodic} and takes the values of #font[62]{r} as #font[62]{1, 2, 3, 4, 5, 6 ...}");
 	Paso2_Quantum1_Exp->Draw();     	
     	
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(1); 
	}
	
	if(Breakopt==3){
	
	//Titulo
        TPaveText *Paso3_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_cuantico->SetTextFont(62);
	Paso3_cuantico->SetFillColor(kMagenta-10); 
	Paso3_cuantico->SetShadowColor(kGray);
	Paso3_cuantico->SetMargin(0);
	Paso3_cuantico->AddText("Step #3");
	Paso3_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
     	
	//Texto 1
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.03, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 16 #color[9]{n = 4}");
       
       	//Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.03, 0.70, "Equation: #frac{1}{#sqrt{16}}[#sum_{x=0}^{15}|x#GT^{#otimes#color[9]{4}}]#color[1]{|13^{r}mod15#GT^{#otimes#color[9]{4}}}");
	
	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "Matrix response of the equation with the states: #font[62]{#color[1]{|x#GT^{#otimes#color[9]{4}}}}#font[62]{#color[2]{|w#GT^{#otimes#color[9]{4}}}}");
	
	//Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.02, 0.40, "#frac{1}{#sqrt{16}}");
	
	//Lineas para delimitar la matriz
	lineaV1 = new TLine(0.08, 0.15, 0.08, 0.55);
	lineaV2 = new TLine(0.98, 0.15, 0.98, 0.55);
	
	lineaH1 = new TLine(0.08, 0.55, 0.09, 0.55);
	lineaH2 = new TLine(0.08, 0.15, 0.09, 0.15);
	lineaH3 = new TLine(0.98, 0.55, 0.97, 0.55);
	lineaH4 = new TLine(0.98, 0.15, 0.97, 0.15);
	
	lineaV1->SetLineColor(kBlack);
	lineaV2->SetLineColor(kBlack);
	lineaH1->SetLineColor(kBlack);
	lineaH2->SetLineColor(kBlack);
	lineaH3->SetLineColor(kBlack);
	lineaH4->SetLineColor(kBlack);
	
	lineaV1->Draw();
	lineaV2->Draw();
	lineaH1->Draw();
	lineaH2->Draw();
	lineaH3->Draw();
	lineaH4->Draw();
	
	// Definir la matriz (3x3 en este caso)
   	const int filas = 4;
    	const int columnas = 4;
    	const char* matriz[filas][columnas] = {
        {"|0#GT^{#otimes#color[9]{4}}|1#GT^{#otimes#color[9]{4}} + ", "|1#GT^{#otimes#color[9]{4}}|13#GT^{#otimes#color[9]{4}} + ", "|2#GT^{#otimes#color[9]{4}}|4#GT^{#otimes#color[9]{4}} + ", "#color[38]{|3#GT^{#otimes#color[9]{4}}}#color[2]{|7#GT^{#otimes#color[9]{4}}}  "},
        {"|4#GT^{#otimes#color[9]{4}}|1#GT^{#otimes#color[9]{4}} + ", "|5#GT^{#otimes#color[9]{4}}|13#GT^{#otimes#color[9]{4}} + ", "|6#GT^{#otimes#color[9]{4}}|4#GT^{#otimes#color[9]{4}} + ", "#color[39]{|7#GT^{#otimes#color[9]{4}}}#color[2]{|7#GT^{#otimes#color[9]{4}}}  "},
        {"|8#GT^{#otimes#color[9]{4}}|1#GT^{#otimes#color[9]{4}} + ", "|9#GT^{#otimes#color[9]{4}}|13#GT^{#otimes#color[9]{4}} + ", "|10#GT^{#otimes#color[9]{4}}|4#GT^{#otimes#color[9]{4}} + ", " #color[6]{|11#GT^{#otimes#color[9]{4}}}#color[2]{|7#GT^{#otimes#color[9]{4}}}  "},
        {"|12#GT^{#otimes#color[9]{4}}|1#GT^{#otimes#color[9]{4}} + ", "|13#GT^{#otimes#color[9]{4}}|13#GT^{#otimes#color[9]{4}} + ", "  |14#GT^{#otimes#color[9]{4}}|4#GT^{#otimes#color[9]{4}} + ", "  #color[46]{|15#GT^{#otimes#color[9]{4}}}#color[2]{|7#GT^{#otimes#color[9]{4}}}  "},
    	};
    	
    	//Posiciones para dibujar la matriz
    	double xMin = 0.03, xMax = 0.85; 
    	double yMin = 0.15, yMax = 0.55; 
    	double dx = (xMax - xMin) / columnas; 
    	double dy = (yMax - yMin) / filas;   
	
	TLatex latex;
    	for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
        // Posición de cada elemento en el centro de cada celda
        double xPos = xMin + (j + 0.5) * dx;
        double yPos = yMax - (i + 0.5) * dy;
        latex.DrawLatex(xPos, yPos, matriz[i][j]);
        }
       }
       
        //Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.02, 0.10, "Proposed measurement of #font[62]{|w#GT^{#otimes#color[9]{4}}} is #font[62]{#color[2]{|7#GT^{#otimes#color[9]{4}}}}");
	
	//Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso3_Quantum1_Exp->SetTextFont(42);
	Paso3_Quantum1_Exp->SetFillColor(0); 
	Paso3_Quantum1_Exp->SetShadowColor(kGray);
	Paso3_Quantum1_Exp->SetTextAlign(12);
	Paso3_Quantum1_Exp->SetMargin(0.01);
	Paso3_Quantum1_Exp->AddText("The #font[62]{step 3} obtains the #font[62]{resulting matrix} after performing the summation of the equation. This matrix is organized to make it possible to observe");
	Paso3_Quantum1_Exp->AddText("Each record of #font[62]{|w#GT^{#otimes#color[9]{4}}} is used to identify the #font[62]{periodicity} of the function. Then, a random value from #font[62]{|w#GT^{#otimes#color[9]{4}}} is selected, which has been highlighted, and");
	Paso3_Quantum1_Exp->AddText("based on that number, various possible results of #font[62]{|x#GT^{#otimes#color[9]{4}}} are recorded with a #font[62]{normalization depending on the number of possible elements}.");
	Paso3_Quantum1_Exp->AddText("These elements are evaluated in the #font[62]{QFT^{+}} to take advantage of the properties of #font[62]{interference} by eliminating values. The new values will be evaluated");
	Paso3_Quantum1_Exp->AddText("in the next step to complete the factorization.");
 	Paso3_Quantum1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1); 
        }
      	
      	if(Breakopt==4){
      	//Titulo
        TPaveText *Paso3_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_cuantico->SetTextFont(62);
	Paso3_cuantico->SetFillColor(kMagenta-10); 
	Paso3_cuantico->SetShadowColor(kGray);
	Paso3_cuantico->SetMargin(0);
	Paso3_cuantico->AddText("Step #3");
	Paso3_cuantico->Draw();
	
      	//Texto 1
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.80, "#font[62]{Possible results} #font[62]{|x#GT^{#otimes#color[9]{4}}}");
	
	//Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.2, 0.70, "#font[62]{|x#GT^{#otimes#color[9]{4}}} = #font[62]{#frac{1}{#sqrt{4}}[#color[38]{|3#GT^{#otimes#color[9]{4}}}} + #font[62]{#color[39]{|7#GT^{#otimes#color[9]{4}}}} + #font[62]{#color[6]{|11#GT^{#otimes#color[9]{4}}}} + #font[62]{#color[46]{|15#GT^{#otimes#color[9]{4}}}}]#otimes#color[2]{|7#GT^{#otimes#color[9]{4}}}");
	
	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.01, 0.60, "#font[62]{Apply the QFT^{+} to #font[62]{#color[4]{|x#GT^{#otimes#color[9]{4}}}}}");
      
       	//Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.2, 0.50, "QFT^{+}#color[4]{|x#GT^{#otimes#color[9]{4}}} = #frac{1}{#sqrt{16}}#sum_{y=0}^{15} e^{#frac{-2#pi i#color[4]{x}y}{16}}|y#GT^{#otimes#color[9]{4}}");
	
	//Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.2, 0.35, "QFT^{+}#color[1]{|x#GT^{#otimes#color[9]{4}}} = #frac{1}{#sqrt{4}}#frac{1}{#sqrt{16}}#sum_{y=0}^{15}[e^{#frac{-#color[38]{3}#pi iy}{8}} + e^{#frac{-#color[39]{7}#pi iy}{8}} + e^{#frac{-#color[6]{11}#pi iy}{8}} + e^{#frac{-#color[46]{15}#pi iy}{8}}]|y#GT^{#otimes#color[9]{4}}");
	
	//Texto 6
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.2, 0.20, "QFT^{+}#color[1]{|x#GT^{#otimes#color[9]{4}}} = #frac{1}{#sqrt{4}}#frac{1}{#sqrt{16}}[4#color[8]{|0#GT^{#otimes#color[9]{4}}}+4i#color[40]{|4#GT^{#otimes#color[9]{4}}}-4#color[43]{|8#GT^{#otimes#color[9]{4}}}-4i#color[44]{|12#GT^{#otimes#color[9]{4}}}]");
	
	//Texto 7
	l7->SetTextFont(42); 
	l7->SetTextColor(1); 
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.01, 0.08, "#font[62]{Values For the next step:} #color[39]{|0#GT^{#otimes#color[9]{4}}}, #color[6]{|4#GT^{#otimes#color[9]{4}}}, #color[6]{|8#GT^{#otimes#color[9]{4}}}, #color[6]{|12#GT^{#otimes#color[9]{4}}}");
		
	//Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso3_Quantum1_Exp->SetTextFont(42);
	Paso3_Quantum1_Exp->SetFillColor(0); 
	Paso3_Quantum1_Exp->SetShadowColor(kGray);
	Paso3_Quantum1_Exp->SetTextAlign(12);
	Paso3_Quantum1_Exp->SetMargin(0.01);
	Paso3_Quantum1_Exp->AddText("The #font[62]{step 3} obtains the #font[62]{resulting matrix} after performing the summation of the equation. This matrix is organized to make it possible to observe");
	Paso3_Quantum1_Exp->AddText("Each record of #font[62]{|w#GT^{#otimes#color[9]{4}}} is used to identify the #font[62]{periodicity} of the function. Then, a random value from #font[62]{|w#GT^{#otimes#color[9]{4}}} is selected, which has been highlighted, and");
	Paso3_Quantum1_Exp->AddText("based on that number, various possible results of #font[62]{|x#GT^{#otimes#color[9]{4}}} are recorded with a #font[62]{normalization depending on the number of possible elements}.");
	Paso3_Quantum1_Exp->AddText("These elements are evaluated in the #font[62]{QFT^{+}} to take advantage of the properties of #font[62]{interference} by eliminating values. The new values will be evaluated");
	Paso3_Quantum1_Exp->AddText("in the next step to complete the factorization.");
 	Paso3_Quantum1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1); 
	
	}
	if(Breakopt==5){
	
	//Titulo
	TPaveText *Paso4_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso4_cuantico->SetTextFont(62);
	Paso4_cuantico->SetFillColor(kCyan-10); 
	Paso4_cuantico->SetShadowColor(kGray);
	Paso4_cuantico->SetMargin(0);
	Paso4_cuantico->AddText("Step #4");
	Paso4_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
	
	//Resultado 1 Num Fac. p1
	TPaveText *resultado1 = new TPaveText(0.001, 0.55, 0.5, 0.83); 
	resultado1->SetTextFont(42);
	resultado1->SetFillColor(0); 
	resultado1->SetShadowColor(kGray);
	resultado1->SetMargin(0);
	resultado1->AddText("");
	resultado1->AddText("Measured value #font[62]{#color[6]{|4#GT^{#otimes#color[9]{4}}}}");
	resultado1->AddText("");
	resultado1->AddText("Result: #frac{jN*}{r} = M  #frac{j16}{r} = #color[6]{4}  j = 1, r = 4");
	resultado1->AddText("");
	resultado1->AddText("X = 13^{#frac{4}{2}} mod 15 = 4");
	resultado1->AddText("");
	resultado1->AddText("#color[2]{P} = GCD(X+1, N)  #color[2]{P} = GCD(5, 15) = 5  #color[2]{P} = 5");
	resultado1->AddText("");
	resultado1->Draw();
	
	//Resultado 1 Num Fac. q1
	TPaveText *resultado2 = new TPaveText(0.5, 0.55, 0.999, 0.83); 
	resultado2->SetTextFont(42);
	resultado2->SetFillColor(0); 
	resultado2->SetShadowColor(kGray);
	resultado2->SetMargin(0);
	resultado2->AddText("");
	resultado2->AddText("Measured value #font[62]{#color[6]{|4#GT^{#otimes#color[9]{4}}}}");
	resultado2->AddText("");
	resultado2->AddText("Result: #frac{jN*}{r} = M  #frac{j16}{r} = #color[6]{4}  j = 1, r = 4");
	resultado2->AddText("");
	resultado2->AddText("X = 13^{#frac{4}{2}} mod 15 = 4");
	resultado2->AddText("");
	resultado2->AddText("#color[8]{Q} = GCD(X-1, N)  #color[8]{Q} = GCD(3, 15) = 3  #color[8]{Q} = 3");
	resultado2->AddText("");
	resultado2->Draw();

	//Resultado 1 Num Fac. p2
	TPaveText *resultado3 = new TPaveText(0.001, 0.27, 0.5, 0.54); 
	resultado3->SetTextFont(42);
	resultado3->SetFillColor(0); 
	resultado3->SetShadowColor(kGray);
	resultado3->SetMargin(0);
	resultado3->AddText("");
	resultado3->AddText("Measured value #font[62]{#color[6]{|8#GT^{#otimes#color[9]{4}}}}");
	resultado3->AddText("");
	resultado3->AddText("Result: #frac{jN*}{r} = M  #frac{j16}{r} = #color[6]{4}  j = 1, r = 2");
	resultado3->AddText("");
	resultado3->AddText("X = 13^{#frac{2}{2}} mod 15 = 13");
	resultado3->AddText("");
	resultado3->AddText("#color[2]{P} = GCD(X+1, N)  #color[2]{P} = GCD(14, 15) = 1  #color[2]{P} = 1  Partial Solution");
	resultado3->AddText("");
	resultado3->Draw();
	
	//Resultado 1 Num Fac. q2
	TPaveText *resultado4 = new TPaveText(0.5, 0.27, 0.999, 0.54); 
	resultado4->SetTextFont(42);
	resultado4->SetFillColor(0); 
	resultado4->SetShadowColor(kGray);
	resultado4->SetMargin(0);
	resultado4->AddText("");
	resultado4->AddText("Measured value #font[62]{#color[6]{|8#GT^{#otimes#color[9]{4}}}}");
	resultado4->AddText("");
	resultado4->AddText("Result: #frac{jN*}{r} = M  #frac{j16}{r} = #color[6]{4}  j = 1, r = 2");
	resultado4->AddText("");
	resultado4->AddText("X = 13^{#frac{2}{2}} mod 15 = 13");
	resultado4->AddText("");
	resultado4->AddText("#color[8]{Q} = GCD(X-1, N)  #color[8]{Q} = GCD(12, 15) = 3  #color[8]{Q} = 3");
	resultado4->AddText("");
	resultado4->Draw();
	
	//Resultado 1 Num Fac. p3
	TPaveText *resultado5 = new TPaveText(0.001, 0.01, 0.5, 0.26);
	resultado5->SetTextFont(42);
	resultado5->SetFillColor(0); 
	resultado5->SetShadowColor(kGray);
	resultado5->SetMargin(0);
	resultado5->AddText("");
	resultado5->AddText("Measured value #font[62]{#color[6]{|12#GT^{#otimes#color[9]{4}}}}");
	resultado5->AddText("");
	resultado5->AddText("Result: #frac{jN*}{r} = M  #frac{j16}{r} = #color[6]{4}  j = 3, r = 4");
	resultado5->AddText("");
	resultado5->AddText("X = 13^{#frac{4}{2}} mod 15 = 4");
	resultado5->AddText("");
	resultado5->AddText("#color[2]{P} = GCD(X+1, N)  #color[2]{P} = GCD(5, 15) = 5  #color[2]{P} = 5");
	resultado5->AddText("");
	resultado5->Draw();
	
	//Resultado 1 Num Fac. q3
	TPaveText *resultado6 = new TPaveText(0.5, 0.01, 0.999, 0.26); 
	resultado6->SetTextFont(42);
	resultado6->SetFillColor(0); 
	resultado6->SetShadowColor(kGray);
	resultado6->SetMargin(0);
	resultado6->AddText("");
	resultado6->AddText("Measured value #font[62]{#color[6]{|12#GT^{#otimes#color[9]{4}}}}");
	resultado6->AddText("");
	resultado6->AddText("Result: #frac{jN*}{r} = M  #frac{j16}{r} = #color[6]{4}  j = 3, r = 4");
	resultado6->AddText("");
	resultado6->AddText("X = 13^{#frac{4}{2}} mod 15 = 4");
	resultado6->AddText("");
	resultado6->AddText("#color[8]{Q} = GCD(X-1, N)  #color[8]{Q} = GCD(3, 15) = 3  #color[8]{Q} = 3");
	resultado6->AddText("");
	resultado6->Draw();
	
	//Segundo canvas    	
     	TCanvas *ExpPaso4 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso4->SetFillColor(0);
	ExpPaso4->SetEditable(1);
	ExpPaso4->Clear();
	ExpPaso4->Update();
	
	TPaveText *Paso4_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	
	Paso4_Quantum1_Exp->SetTextFont(42);
	
	Paso4_Quantum1_Exp->SetFillColor(0); 
	Paso4_Quantum1_Exp->SetShadowColor(0);
	Paso4_Quantum1_Exp->SetTextAlign(12);
	Paso4_Quantum1_Exp->SetMargin(0.01);
	
	Paso4_Quantum1_Exp->AddText("For #font[62]{step 4}, the results are evaluated to ensure they meet the condition #font[62]{#frac{jN}{r} = M}, which determines the period value for defining the");
	Paso4_Quantum1_Exp->AddText("value #font[62]{X} and perform the greatest common divisor operation to determine the values of #font[62]{P} and #font[62]{Q}. The results are found highlighted for each possible");
	
	Paso4_Quantum1_Exp->AddText("value from the previous step.");
 	Paso4_Quantum1_Exp->Draw();     	
     	
     	ExpPaso4->Update();
	ExpPaso4->SetEditable(1); 
	}
	}
	break; 
	
     case 14:{
        if(Breakopt==1){
        
        //Titulo
	TPaveText *Paso1_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso1_cuantico->SetTextFont(62);
	Paso1_cuantico->SetFillColor(kBlue-10); 
	Paso1_cuantico->SetShadowColor(kGray);
	Paso1_cuantico->SetMargin(0);
	Paso1_cuantico->AddText("Step #1");
	Paso1_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
	
	//Texto 1
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 16#color[9]{n = 4}");
	
	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "States: #font[62]{#color[1]{|x#GT^{#otimes#color[9]{4}}}}#font[62]{#color[1]{|w#GT^{#otimes#color[9]{4}}}}");
	
	//Flecha 1
	flecha1 = new TArrow(0.23, 0.60, 0.37, 0.60, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	//Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.40, 0.60, "#font[62]{#color[1]{|0#GT^{#otimes#color[9]{4}}}}#font[62]{#color[1]{|0#GT^{#otimes#color[9]{4}}}}");
	
	//Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.03, 0.40, "Applying the #font[62]{#color[2]{Hadamard}} gate to the kets #font[62]{#color[1]{|x#GT^{#otimes#color[9]{4}}}}");
	
	//Texto 6
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.08, 0.25, "[#color[2]{H^{#otimes 4}}#color[1]{|x#GT^{#otimes#color[9]{4}}}]#color[1]{|w#GT^{#otimes#color[9]{4}}} = #frac{1}{#sqrt{16}}[#sum_{x=0}^{15}#color[1]{|x#GT^{#otimes#color[9]{4}}}]#color[1]{|0#GT^{#otimes#color[9]{4}}}");
	
	//Cuadros explicativos
	TPaveText *Estados_example_1 = new TPaveText(0.55, 0.5, 0.99, 0.75); 
	Estados_example_1->SetTextFont(42);
	Estados_example_1->SetFillColor(kRed-10); 
	Estados_example_1->SetShadowColor(kGray);
	Estados_example_1->SetMargin(0);
	Estados_example_1->AddText("");
	Estados_example_1->AddText("The initial states of #font[62]{|x#GT and |w#GT}");
	Estados_example_1->AddText("will always be in #font[62]{|0#GT}");
	Estados_example_1->AddText("");
	Estados_example_1->Draw();
	
	TPaveText *Comp_H = new TPaveText(0.55, 0.4, 0.99, 0.1); 
	Comp_H->SetTextFont(42);
	Comp_H->SetFillColor(kMagenta-10); 
	Comp_H->SetShadowColor(kGray);
	Comp_H->SetMargin(0);
	Comp_H->AddText("");
	Comp_H->AddText("the #font[62]{Hadamard} operation creates");
	Comp_H->AddText("the states in #font[62]{superposition} that are");
	Comp_H->AddText("#font[62]{equiprobable}.");
	Comp_H->AddText("");
	Comp_H->Draw();
	
	//Segundo canvas    	
     	TCanvas *ExpPaso1 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1->SetFillColor(0);
	ExpPaso1->SetEditable(1);
	ExpPaso1->Clear();
	ExpPaso1->Update();
	TPaveText *Paso1_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.999, 0.99);
	Paso1_Quantum1_Exp->SetTextFont(42);
	Paso1_Quantum1_Exp->SetFillColor(0); 
	Paso1_Quantum1_Exp->SetShadowColor(kGray);
	Paso1_Quantum1_Exp->SetTextAlign(12);
	Paso1_Quantum1_Exp->SetMargin(0.01);
	Paso1_Quantum1_Exp->AddText("For #font[62]{Step 1}, the #font[62]{number of states} of the denoted system is defined as #font[62]{N*}, where the number of #font[62]{Qubits} #font[62]{n} is determined.");
	Paso1_Quantum1_Exp->AddText("The possible states are written in the form of a #font[62]{summation} due to the #font[62]{Hadamard} gate and the use of #font[62]{Dirac notation with the power}");
	Paso1_Quantum1_Exp->AddText("#font[62]{of the tensor product and the number n} indicates the number of #font[62]{Qubits} used to represent each possible state, thus the representation of a state");
	Paso1_Quantum1_Exp->AddText("random within that interval will be in the form: #font[62]{|x#GT^{#otimes n} = |x#GT#otimes|x#GT#otimes|x#GT#otimes|x#GT ...#otimes|x#GT (n times)}");
 	Paso1_Quantum1_Exp->Draw();     	
     	
     	ExpPaso1->Update();
	ExpPaso1->SetEditable(1); 
        
        }
     	if(Breakopt==2){
      
	//Titulo
        TPaveText *Paso2_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso2_cuantico->SetTextFont(62);
	Paso2_cuantico->SetFillColor(kGreen-10); 
	Paso2_cuantico->SetShadowColor(kGray);
	Paso2_cuantico->SetMargin(0);
	Paso2_cuantico->AddText("Step #2");
	Paso2_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();        
        
        //Texto 1
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 16 #color[9]{n = 4}");
        
        //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.03, 0.65, "By applying the operator #color[2]{U_{a,N}} we obtain:");
	
	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.55, "#color[2]{U_{a,N}}(#frac{1}{#sqrt{16}}[#sum_{x=0}^{15}|x#GT^{#otimes#color[9]{4}}]|0#GT^{#otimes#color[9]{4}}) = #frac{1}{#sqrt{16}}[#sum_{x=0}^{15}|x#GT^{#otimes#color[9]{4}}]#color[2]{|0#oplusF_{a,N}#GT^{#otimes#color[9]{4}}}");
        
        //Cuadros explicativos
	TPaveText *Operador_Uf = new TPaveText(0.55, 0.40, 0.99, 0.65); 
	Operador_Uf->SetTextFont(42);
	Operador_Uf->SetFillColor(kMagenta-8); 
	Operador_Uf->SetShadowColor(kGray);
	Operador_Uf->SetMargin(0);
	Operador_Uf->AddText("");
	Operador_Uf->AddText("#font[62]{Modulo 2 Addition Property}");
	Operador_Uf->AddText("");
	Operador_Uf->AddText("#font[62]{|0#oplusF_{a,N}#GT^{#otimes#color[9]{4}} = |F_{a,N}#GT^{#otimes#color[9]{4}} =|a^{r}mod N#GT^{#otimes#color[9]{4}}}");
	Operador_Uf->AddText("");
	Operador_Uf->Draw();
        
        //Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.30, "The final result after substituting the values is:");
	
	//Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.2, 0.20, "#color[2]{U_{a,N}}(#frac{1}{#sqrt{16}}[#sum_{x=0}^{15}|x#GT^{#otimes#color[9]{4}}]|0#GT^{#otimes#color[9]{4}}) = #frac{1}{#sqrt{16}}[#sum_{x=0}^{15}|x#GT^{#otimes#color[9]{4}}]#color[2]{|14^{r}mod15#GT^{#otimes#color[9]{4}}}");
        
        //Segundo canvas    	
     	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	
	TPaveText *Paso2_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.999, 0.99);
	Paso2_Quantum1_Exp->SetTextFont(42);
	Paso2_Quantum1_Exp->SetFillColor(0); 
	Paso2_Quantum1_Exp->SetShadowColor(kGray);
	Paso2_Quantum1_Exp->SetTextAlign(12);
	Paso2_Quantum1_Exp->SetMargin(0.01);
	Paso2_Quantum1_Exp->AddText("For #font[62]{step 2}, the unitary operator #font[62]{U_{a,N}} is applied to the previous result. This, in turn, performs the #font[62]{modulo 2 addition} operation");
	Paso2_Quantum1_Exp->AddText("which satisfies an important property because the ket #font[62]{|w#GT} is initialized in the state #font[62]{|0#GT}, as shown in the box.");
	Paso2_Quantum1_Exp->AddText("The final result applies the function #font[62]{F_{a,N} = a^{r}mod N}, which is #font[62]{periodic} and takes the values of #font[62]{r} as #font[62]{1, 2, 3, 4, 5, 6 ...}");
 	Paso2_Quantum1_Exp->Draw();     	
     
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(1); 
        
        }
     	if(Breakopt==3){
       
        //Titulo
        TPaveText *Paso3_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_cuantico->SetTextFont(62);
	
	Paso3_cuantico->SetFillColor(kMagenta-10); 
	Paso3_cuantico->SetShadowColor(kGray);
	Paso3_cuantico->SetMargin(0);
	Paso3_cuantico->AddText("Step #3");
	Paso3_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
       
        //Texto 1
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.03, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 16 #color[9]{n = 4}");
        
        //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.03, 0.70, "Equation: #frac{1}{#sqrt{16}}[#sum_{x=0}^{15}|x#GT^{#otimes#color[9]{4}}]#color[1]{|14^{r}mod15#GT^{#otimes#color[9]{4}}}");
        
        //Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "Matrix response of the equation with the states: #font[62]{#color[1]{|x#GT^{#otimes#color[9]{4}}}}#font[62]{#color[2]{|w#GT^{#otimes#color[9]{4}}}}");
	
	//Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.02, 0.40, "#frac{1}{#sqrt{16}} ");
	
	//Lineas para delimitar la matriz
	lineaV1 = new TLine(0.08, 0.15, 0.08, 0.55);
	lineaV2 = new TLine(0.98, 0.15, 0.98, 0.55);
	
	lineaH1 = new TLine(0.08, 0.55, 0.09, 0.55);
	lineaH2 = new TLine(0.08, 0.15, 0.09, 0.15);
	lineaH3 = new TLine(0.98, 0.55, 0.97, 0.55);
	lineaH4 = new TLine(0.98, 0.15, 0.97, 0.15);
	
	lineaV1->SetLineColor(kBlack);
	lineaV2->SetLineColor(kBlack);
	lineaH1->SetLineColor(kBlack);
	lineaH2->SetLineColor(kBlack);
	lineaH3->SetLineColor(kBlack);
	lineaH4->SetLineColor(kBlack);
	
	lineaV1->Draw();
	lineaV2->Draw();
	lineaH1->Draw();
	lineaH2->Draw();
	lineaH3->Draw();
	lineaH4->Draw();
	
	//Definir la matriz 
   	const int filas = 4;
    	const int columnas = 4;
    	const char* matriz[filas][columnas] = {
        {"|0#GT^{#otimes#color[9]{4}}|1#GT^{#otimes#color[9]{4}} + ", "#color[6]{|1#GT^{#otimes#color[9]{4}}}#color[2]{|14#GT^{#otimes#color[9]{4}}} + ", "|2#GT^{#otimes#color[9]{4}}|1#GT^{#otimes#color[9]{4}} + ", "#color[38]{|3#GT^{#otimes#color[9]{4}}}#color[2]{#color[2]{|14#GT^{#otimes#color[9]{4}}}}"},
        {"|4#GT^{#otimes#color[9]{4}}|1#GT^{#otimes#color[9]{4}} + ", "#color[7]{|5#GT^{#otimes#color[9]{4}}}#color[2]{|14#GT^{#otimes#color[9]{4}}} + ", "|6#GT^{#otimes#color[9]{4}}|1#GT^{#otimes#color[9]{4}} + ", "#color[39]{|7#GT^{#otimes#color[9]{4}}}#color[2]{#color[2]{|14#GT^{#otimes#color[9]{4}}}}"},
        {"|8#GT^{#otimes#color[9]{4}}|1#GT^{#otimes#color[9]{4}} + ", "#color[8]{|9#GT^{#otimes#color[9]{4}}}#color[2]{|14#GT^{#otimes#color[9]{4}}} + ", "|10#GT^{#otimes#color[9]{4}}|1#GT^{#otimes#color[9]{4}} + ", "#color[6]{|11#GT^{#otimes#color[9]{4}}}#color[2]{|14#GT^{#otimes#color[9]{4}}}"},
        {"|12#GT^{#otimes#color[9]{4}}|1#GT^{#otimes#color[9]{4}} + ", "#color[28]{|13#GT^{#otimes#color[9]{4}}}#color[2]{|14#GT^{#otimes#color[9]{4}}} + ", "|14#GT^{#otimes#color[9]{4}}|1#GT^{#otimes#color[9]{4}} + ", "#color[46]{|15#GT^{#otimes#color[9]{4}}}#color[2]{|14#GT^{#otimes#color[9]{4}}}"},
    	};
    	

    	//Posiciones para dibujar la matriz
    	double xMin = 0.03, xMax = 0.85; 
    	double yMin = 0.15, yMax = 0.55; 
    	double dx = (xMax - xMin) / columnas; 
    	double dy = (yMax - yMin) / filas;   
	
	TLatex latex;
    	
    	for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
        // Posición de cada elemento en el centro de cada celda
        double xPos = xMin + (j + 0.5) * dx;
        double yPos = yMax - (i + 0.5) * dy;
        latex.DrawLatex(xPos, yPos, matriz[i][j]);
        }
       }
	
	//Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.02, 0.10, "Proposed measurement of #font[62]{|w#GT^{#otimes#color[9]{4}}} is #font[62]{#color[2]{|14#GT^{#otimes#color[9]{4}}}}.");
	
	//Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso3_Quantum1_Exp->SetTextFont(42);
	Paso3_Quantum1_Exp->SetFillColor(0); 
	Paso3_Quantum1_Exp->SetShadowColor(kGray);
	Paso3_Quantum1_Exp->SetTextAlign(12);
	Paso3_Quantum1_Exp->SetMargin(0.01);
	Paso3_Quantum1_Exp->AddText("The #font[62]{step 3} obtains the #font[62]{resulting matrix} after performing the summation of the equation. This matrix is organized to make it possible to observe");
	Paso3_Quantum1_Exp->AddText("Each record of #font[62]{|w#GT^{#otimes#color[9]{4}}} is used to identify the #font[62]{periodicity} of the function. Then, a random value from #font[62]{|w#GT^{#otimes#color[9]{4}}} is selected, which has been highlighted, and");
	Paso3_Quantum1_Exp->AddText("based on that number, various possible results of #font[62]{|x#GT^{#otimes#color[9]{4}}} are recorded with a #font[62]{normalization depending on the number of possible elements}.");
	Paso3_Quantum1_Exp->AddText("These elements are evaluated in the #font[62]{QFT^{+}} to take advantage of the properties of #font[62]{interference} by eliminating values. The new values will be evaluated");
	Paso3_Quantum1_Exp->AddText("in the next step to complete the factorization.");
 	Paso3_Quantum1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1); 
        }
	
	if(Breakopt==4){
	//Titulo
        TPaveText *Paso3_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_cuantico->SetTextFont(62);
	Paso3_cuantico->SetFillColor(kMagenta-10); 
	Paso3_cuantico->SetShadowColor(kGray);
	Paso3_cuantico->SetMargin(0);
	Paso3_cuantico->AddText("Step #3");
	Paso3_cuantico->Draw();

	//Texto 1
	
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.80, "#font[62]{Possible results} #font[62]{|x#GT^{#otimes#color[9]{4}}}");
	
	//Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.01, 0.70, "#font[62]{#frac{1}{#sqrt{8}} [#color[6]{|1#GT^{#otimes#color[9]{4}}} + #color[38]{|3#GT^{#otimes#color[9]{4}}}} + #color[7]{|5#GT^{#otimes#color[9]{4}}} + #font[62]{#color[39]{|7#GT^{#otimes#color[9]{4}}}} + #color[8]{|9#GT^{#otimes#color[9]{4}}} + #font[62]{#color[6]{|11#GT^{#otimes#color[9]{4}}}} + #color[28]{|13#GT^{#otimes#color[9]{4}}} + #font[62]{#color[46]{|15#GT^{#otimes#color[9]{4}}}}]#otimes#color[2]{|14#GT^{#otimes#color[9]{4}}}");
	
	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.01, 0.60, "#font[62]{Apply the QFT^{+} to #font[62]{#color[4]{|x#GT^{#otimes#color[9]{4}}}}}");
	
       	//Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.01, 0.50, "QFT^{+}#color[4]{|x#GT^{#otimes#color[9]{4}}} = #frac{1}{#sqrt{16}}#sum_{y=0}^{15} e^{#frac{-2#pi i#color[4]{x}y}{16}}|y#GT^{#otimes#color[9]{4}}");
        
	//Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.01, 0.33, "QFT^{+}#color[1]{|x#GT^{#otimes#color[9]{4}}} = #frac{1}{#sqrt{8}}#frac{1}{#sqrt{16}}#sum_{y=0}^{15}[e^{#frac{-#color[6]{1}#pi iy}{8}} + e^{#frac{-#color[38]{3}#pi iy}{8}} + e^{#frac{-#color[7]{5}#pi iy}{8}} + e^{#frac{-#color[39]{7}#pi iy}{8}} + e^{#frac{-#color[8]{9}#pi iy}{8}} + e^{#frac{-#color[6]{11}#pi iy}{8}}+ e^{#frac{-#color[28]{13}#pi iy}{8}} + e^{#frac{-#color[46]{15}#pi iy}{8}}]|y#GT^{#otimes#color[9]{4}}");
        
        //Texto 6
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.01, 0.20, "QFT^{+}#color[1]{|x#GT^{#otimes#color[9]{4}}} = #frac{1}{#sqrt{8}}#frac{1}{#sqrt{16}}[8#color[8]{|0#GT^{#otimes#color[9]{4}}} + 0i#color[40]{|4#GT^{#otimes#color[9]{4}}} - 8#color[43]{|8#GT^{#otimes#color[9]{4}}} + 0i#color[44]{|12#GT^{#otimes#color[9]{4}}}]");
        
        //Texto 7
	l7->SetTextFont(42); 
	l7->SetTextColor(1); 
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.01, 0.08, "#font[62]{Values For the next step:} #color[39]{|0#GT^{#otimes#color[9]{4}}}, #color[6]{|4#GT^{#otimes#color[9]{4}}}, #color[6]{|8#GT^{#otimes#color[9]{4}}}, #color[6]{|12#GT^{#otimes#color[9]{4}}}");
        
        //Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso3_Quantum1_Exp->SetTextFont(42);
	Paso3_Quantum1_Exp->SetFillColor(0); 
	Paso3_Quantum1_Exp->SetShadowColor(kGray);
	Paso3_Quantum1_Exp->SetTextAlign(12);
	Paso3_Quantum1_Exp->SetMargin(0.01);
	Paso3_Quantum1_Exp->AddText("The #font[62]{step 3} obtains the #font[62]{resulting matrix} after performing the summation of the equation. This matrix is organized to make it possible to observe");
	Paso3_Quantum1_Exp->AddText("Each record of #font[62]{|w#GT^{#otimes#color[9]{4}}} is used to identify the #font[62]{periodicity} of the function. Then, a random value from #font[62]{|w#GT^{#otimes#color[9]{4}}} is selected, which has been highlighted, and");
	Paso3_Quantum1_Exp->AddText("based on that number, various possible results of #font[62]{|x#GT^{#otimes#color[9]{4}}} are recorded with a #font[62]{normalization depending on the number of possible elements}.");
	Paso3_Quantum1_Exp->AddText("These elements are evaluated in the #font[62]{QFT^{+}} to take advantage of the properties of #font[62]{interference} by eliminating values. The new values will be evaluated");
	Paso3_Quantum1_Exp->AddText("in the next step to complete the factorization.");
 	Paso3_Quantum1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1); 
        
        }
        if(Breakopt==5){
        
        //Titulo
	TPaveText *Paso4_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso4_cuantico->SetTextFont(62);
	
	Paso4_cuantico->SetFillColor(kCyan-10); 
	Paso4_cuantico->SetShadowColor(kGray);
	Paso4_cuantico->SetMargin(0);
	Paso4_cuantico->AddText("Step #4");
	Paso4_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
	
	//Resultado 1 Num Fac. p1
	TPaveText *resultado1 = new TPaveText(0.001, 0.55, 0.5, 0.83); 
	resultado1->SetTextFont(42);
	resultado1->SetFillColor(0); 
	resultado1->SetShadowColor(kGray);
	resultado1->SetMargin(0);
	resultado1->AddText("");
	resultado1->AddText("Measured value #font[62]{#color[6]{|4#GT^{#otimes#color[9]{4}}}}");
	resultado1->AddText("");
	resultado1->AddText("Result: #frac{jN*}{r} = M  #frac{j16}{r} = #color[6]{4}  j = 1, r = 4");
	resultado1->AddText("");
	resultado1->AddText("X = 14^{#frac{4}{2}} mod 15 = 14");
	resultado1->AddText("");
	resultado1->AddText("#color[2]{P} = GCD(X+1, N)  #color[2]{P} = GCD(15, 15) = 15  #color[2]{P} = 15");
	resultado1->AddText("");
	resultado1->Draw();
	
	//Resultado 1 Num Fac. q1
	TPaveText *resultado2 = new TPaveText(0.5, 0.55, 0.999, 0.83); 
	resultado2->SetTextFont(42);
	resultado2->SetFillColor(0); 
	resultado2->SetShadowColor(kGray);
	resultado2->SetMargin(0);
	resultado2->AddText("");
	resultado2->AddText("Measured value #font[62]{#color[6]{|4#GT^{#otimes#color[9]{4}}}}");
	resultado2->AddText("");
	resultado2->AddText("Result: #frac{jN*}{r} = M  #frac{j16}{r} = #color[6]{4}  j = 1, r = 4");
	resultado2->AddText("");
	resultado2->AddText("X = 14^{#frac{4}{2}} mod 15 = 14");
	resultado2->AddText("");
	resultado2->AddText("#color[8]{Q} = GCD(X-1, N)  #color[8]{Q} = GCD(13, 15) = 1  #color[8]{Q} = 1  Trivial Solution");
	resultado2->AddText("");
	resultado2->Draw();

	//Resultado 1 Num Fac. p2
	TPaveText *resultado3 = new TPaveText(0.001, 0.27, 0.5, 0.54); 
	resultado3->SetTextFont(42);
	resultado3->SetFillColor(0); 
	resultado3->SetShadowColor(kGray);
	resultado3->SetMargin(0);
	resultado3->AddText("");
	resultado3->AddText("Measured value #font[62]{#color[6]{|8#GT^{#otimes#color[9]{4}}}}");
	resultado3->AddText("");
	resultado3->AddText("Result: #frac{jN*}{r} = M  #frac{j16}{r} = #color[6]{8}  j = 1, r = 2");
	resultado3->AddText("");
	resultado3->AddText("X = 14^{#frac{2}{2}} mod 15 = 14");
	resultado3->AddText("");
	resultado3->AddText("#color[2]{P} = GCD(X+1, N)  #color[2]{P} = GCD(15, 15) = 15  #color[2]{P} = 15");
	resultado3->AddText("");
	resultado3->Draw();
	
	//Resultado 1 Num Fac. q2
	TPaveText *resultado4 = new TPaveText(0.5, 0.27, 0.999, 0.54); 
	resultado4->SetTextFont(42);
	resultado4->SetFillColor(0); 
	resultado4->SetShadowColor(kGray);
	resultado4->SetMargin(0);
	resultado4->AddText("");
	resultado4->AddText("Measured value #font[62]{#color[6]{|8#GT^{#otimes#color[9]{4}}}}");
	resultado4->AddText("");
	resultado4->AddText("Result: #frac{jN*}{r} = M  #frac{j16}{r} = #color[6]{8}  j = 1, r = 2");
	resultado4->AddText("");
	resultado4->AddText("X = 13^{#frac{2}{2}} mod 15 = 14");
	resultado4->AddText("");
	resultado4->AddText("#color[8]{Q} = GCD(X-1, N)  #color[8]{Q} = GCD(13, 15) = 1  #color[8]{Q} = 1  Trivial Solution");
	resultado4->AddText("");
	resultado4->Draw();
	
	//Resultado 1 Num Fac. p3
	TPaveText *resultado5 = new TPaveText(0.001, 0.01, 0.5, 0.26);
	resultado5->SetTextFont(42);
	resultado5->SetFillColor(0); 
	resultado5->SetShadowColor(kGray);
	resultado5->SetMargin(0);
	resultado5->AddText("");
	resultado5->AddText("Measured value #font[62]{#color[6]{|12#GT^{#otimes#color[9]{4}}}}");
	resultado5->AddText("");
	resultado5->AddText("Result: #frac{jN*}{r} = M  #frac{j16}{r} = #color[6]{12}  j = 3, r = 4");
	resultado5->AddText("");
	resultado5->AddText("X = 14^{#frac{4}{2}} mod 15 = 1");
	resultado5->AddText("");
	resultado5->AddText("#color[2]{P} = GCD(X+1, N)  #color[2]{P} = GCD(2, 15) = 1  #color[2]{P} = 1");
	resultado5->AddText("");
	resultado5->Draw();
	
	//Resultado 1 Num Fac. q3
	TPaveText *resultado6 = new TPaveText(0.5, 0.01, 0.999, 0.26); 
	resultado6->SetTextFont(42);
	resultado6->SetFillColor(0); 
	resultado6->SetShadowColor(kGray);
	resultado6->SetMargin(0);
	resultado6->AddText("");
	resultado6->AddText("Measured value #font[62]{#color[6]{|12#GT^{#otimes#color[9]{4}}}}");
	resultado6->AddText("");
	resultado6->AddText("Result: #frac{jN*}{r} = M  #frac{j16}{r} = #color[6]{12}  j = 3, r = 4");
	resultado6->AddText("");
	resultado6->AddText("X = 13^{#frac{4}{2}} mod 15 = 1");
	resultado6->AddText("");
	resultado6->AddText("The result is invalid since trying to substitute it into Q = GCD(X-1, N)");
	resultado6->AddText("");
	resultado6->Draw();
        
        //Segundo canvas    	
     	TCanvas *ExpPaso4 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso4->SetFillColor(0);
	ExpPaso4->SetEditable(1);
	ExpPaso4->Clear();
	ExpPaso4->Update();
	
	TPaveText *Paso4_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	
	Paso4_Quantum1_Exp->SetTextFont(42);
	Paso4_Quantum1_Exp->SetFillColor(0); 
	Paso4_Quantum1_Exp->SetShadowColor(0);
	Paso4_Quantum1_Exp->SetTextAlign(12);
	Paso4_Quantum1_Exp->SetMargin(0.01);
	Paso4_Quantum1_Exp->AddText("For #font[62]{step 4}, the results are evaluated under the condition #font[62]{#frac{jN}{r} = M}, which determines the value of #font[62]{r}. Given the choice of #font[62]{a}, it is observed that");
	Paso4_Quantum1_Exp->AddText("the results of the factorization are of #font[62]{trivial} and #font[62]{invalid} types. Therefore, for this selected value of #font[62]{a}, the operations are insufficient, and it becomes");
	Paso4_Quantum1_Exp->AddText("necessary to choose another value coprime with #font[62]{N} to repeat the algorithm again and obtain other possible results that factor the given number.");
 	Paso4_Quantum1_Exp->Draw();     	
     	
     	ExpPaso4->Update();
	ExpPaso4->SetEditable(1);
        }
     } 
     break;        
  }
}
if(Valueopt1 == 21){
  switch (Valueopt2){
      case 2:{
       if(Breakopt==1){
       //Titulo
	TPaveText *Paso1_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso1_cuantico->SetTextFont(62);
	Paso1_cuantico->SetFillColor(kBlue-10); 
	Paso1_cuantico->SetShadowColor(kGray);
	Paso1_cuantico->SetMargin(0);
	Paso1_cuantico->AddText("Step #1");
	Paso1_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
	
	//Texto 1
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 32 #color[9]{n = 5}");

	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "states: #font[62]{#color[1]{|x#GT^{#otimes#color[9]{5}}}}#font[62]{#color[1]{|w#GT^{#otimes#color[9]{5}}}}");
	
	//Flecha 1
	flecha1 = new TArrow(0.23, 0.60, 0.37, 0.60, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	//Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.40, 0.60, "#font[62]{#color[1]{|0#GT^{#otimes#color[9]{5}}}}#font[62]{#color[1]{|0#GT^{#otimes#color[9]{5}}}}");
	
	//Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.03, 0.40, "Applying the #font[62]{#color[2]{Hadamard}} gate to the kets #font[62]{#color[1]{|x#GT^{#otimes#color[9]{5}}}}");
	
	//Texto 6
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.08, 0.25, "[#color[2]{H^{#otimes 5}}#color[1]{|x#GT^{#otimes#color[9]{5}}}]#color[1]{|w#GT^{#otimes#color[9]{5}}} = #frac{1}{#sqrt{32}}[#sum_{x=0}^{31}#color[1]{|x#GT^{#otimes#color[9]{5}}}]#color[1]{|0#GT^{#otimes#color[9]{5}}}");
	
	//Cuadros explicativos
	TPaveText *Estados_example_1 = new TPaveText(0.55, 0.5, 0.99, 0.75); 
	Estados_example_1->SetTextFont(42);
	Estados_example_1->SetFillColor(kRed-10); 
	Estados_example_1->SetShadowColor(kGray);
	Estados_example_1->SetMargin(0);
	Estados_example_1->AddText("");
	Estados_example_1->AddText("The initial states of #font[62]{|x#GT and |w#GT}");
	Estados_example_1->AddText("will always be in #font[62]{|0#GT}");
	Estados_example_1->AddText("");
	Estados_example_1->Draw();
	
	TPaveText *Comp_H = new TPaveText(0.55, 0.4, 0.99, 0.1); 
	Comp_H->SetTextFont(42);
	Comp_H->SetFillColor(kMagenta-10); 
	Comp_H->SetShadowColor(kGray);
	Comp_H->SetMargin(0);
	Comp_H->AddText("");
	Comp_H->AddText("the #font[62]{Hadamard} operation creates");
	Comp_H->AddText("the states in #font[62]{superposition} that are");
	Comp_H->AddText("#font[62]{equiprobable}.");
	Comp_H->AddText("");
	Comp_H->Draw();
	
	//Segundo canvas    	
     	TCanvas *ExpPaso1 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1->SetFillColor(0);
	ExpPaso1->SetEditable(1);
	ExpPaso1->Clear();
	ExpPaso1->Update();
	
	TPaveText *Paso1_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.999, 0.99);
	Paso1_Quantum1_Exp->SetTextFont(42);
	Paso1_Quantum1_Exp->SetFillColor(0); 
	Paso1_Quantum1_Exp->SetShadowColor(kGray);
	Paso1_Quantum1_Exp->SetTextAlign(12);
	Paso1_Quantum1_Exp->SetMargin(0.01);
	Paso1_Quantum1_Exp->AddText("For #font[62]{Step 1}, the #font[62]{number of states} of the denoted system is defined as #font[62]{N*}, where the number of #font[62]{Qubits} #font[62]{n} is determined.");
	Paso1_Quantum1_Exp->AddText("The possible states are written in the form of a #font[62]{summation} due to the #font[62]{Hadamard} gate and the use of #font[62]{Dirac notation with the power}");
	Paso1_Quantum1_Exp->AddText("#font[62]{of the tensor product and the number n} indicates the number of #font[62]{Qubits} used to represent each possible state, thus the representation of a state");
	Paso1_Quantum1_Exp->AddText("random within that interval will be in the form: #font[62]{|x#GT^{#otimes n} = |x#GT#otimes|x#GT#otimes|x#GT#otimes|x#GT ...#otimes|x#GT (n times)}");
 	Paso1_Quantum1_Exp->Draw();     	
     	
     	ExpPaso1->Update();
	ExpPaso1->SetEditable(1);  
        
        } 
       if(Breakopt==2){
       
        //Titulo
        TPaveText *Paso2_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso2_cuantico->SetTextFont(62);
	Paso2_cuantico->SetFillColor(kGreen-10); 
	Paso2_cuantico->SetShadowColor(kGray);
	Paso2_cuantico->SetMargin(0);
	Paso2_cuantico->AddText("Step #2");
	Paso2_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
        
        //Texto 1
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 32 #color[9]{n = 5}");
        
        //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.03, 0.65, "By applying the operator #color[2]{U_{a,N}} we obtain:");
        
        //Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.55, "#color[2]{U_{a,N}}(#frac{1}{#sqrt{32}}[#sum_{x=0}^{31}|x#GT^{#otimes#color[9]{5}}]|0#GT^{#otimes#color[9]{5}}) = #frac{1}{#sqrt{32}}[#sum_{x=0}^{31}|x#GT^{#otimes#color[9]{5}}]#color[2]{|0#oplusF_{a,N}#GT^{#otimes#color[9]{5}}}");
        
        //Cuadros explicativos
	TPaveText *Operador_Uf = new TPaveText(0.55, 0.40, 0.99, 0.65); 
	Operador_Uf->SetTextFont(42);
	Operador_Uf->SetFillColor(kMagenta-8); 
	Operador_Uf->SetShadowColor(kGray);
	Operador_Uf->SetMargin(0);
	Operador_Uf->AddText("");
	Operador_Uf->AddText("#font[62]{Modulo 2 Addition Property}");
	Operador_Uf->AddText("");
	Operador_Uf->AddText("#font[62]{|0#oplusF_{a,N}#GT^{#otimes#color[9]{5}} = |F_{a,N}#GT^{#otimes#color[9]{5}} =|a^{r}mod N#GT^{#otimes#color[9]{5}}}");
	Operador_Uf->AddText("");
	Operador_Uf->Draw();
        
        //Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.30, "The final result after substituting the values is:");
        
        //Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.2, 0.20, "#color[2]{U_{a,N}}(#frac{1}{#sqrt{32}}[#sum_{x=0}^{31}|x#GT^{#otimes#color[9]{5}}]|0#GT^{#otimes#color[9]{5}}) = #frac{1}{#sqrt{32}}[#sum_{x=0}^{31}|x#GT^{#otimes#color[9]{5}}]#color[2]{|2^{r}mod 21 #GT^{#otimes#color[9]{5}}}");
        
        //Segundo canvas    	
     	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	
	TPaveText *Paso2_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.999, 0.99);
	Paso2_Quantum1_Exp->SetTextFont(42);
	Paso2_Quantum1_Exp->SetFillColor(0); 
	Paso2_Quantum1_Exp->SetShadowColor(kGray);
	Paso2_Quantum1_Exp->SetTextAlign(12);
	Paso2_Quantum1_Exp->SetMargin(0.01);
	Paso2_Quantum1_Exp->AddText("For #font[62]{step 2}, the unitary operator #font[62]{U_{a,N}} is applied to the previous result. This, in turn, performs the #font[62]{modulo 2 addition} operation");
	Paso2_Quantum1_Exp->AddText("which satisfies an important property because the ket #font[62]{|w#GT} is initialized in the state #font[62]{|0#GT}, as shown in the box.");
	Paso2_Quantum1_Exp->AddText("The final result applies the function #font[62]{F_{a,N} = a^{r}mod N}, which is #font[62]{periodic} and takes the values of #font[62]{r} as #font[62]{1, 2, 3, 4, 5, 6 ...}");
 	Paso2_Quantum1_Exp->Draw();     	
     	
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(1);    
        } 
     
        if(Breakopt==3){
        
        //Titulo
        TPaveText *Paso3_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_cuantico->SetTextFont(62);
	Paso3_cuantico->SetFillColor(kMagenta-10); 
	Paso3_cuantico->SetShadowColor(kGray);
	Paso3_cuantico->SetMargin(0);
	Paso3_cuantico->AddText("Step #3");
	Paso3_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
       
	//Texto 1
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 32 #color[9]{n = 5}");
        
        //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.03, 0.70, "Equation: #frac{1}{#sqrt{32}}[#sum_{x=0}^{31}|x#GT^{#otimes#color[9]{5}}]#color[1]{|2^{r}mod 21 #GT^{#otimes#color[9]{5}}}");
        
        //Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "Matrix response of the equation with the states: #font[62]{#color[1]{|x#GT^{#otimes#color[9]{5}}}}#font[62]{#color[2]{|w#GT^{#otimes#color[9]{5}}}}");
        
        //Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.02, 0.40, "#frac{1}{#sqrt{32}}");
        
        //Lineas para delimitar la matriz
	lineaV1 = new TLine(0.08, 0.15, 0.08, 0.55);
	lineaV2 = new TLine(0.98, 0.15, 0.98, 0.55);
	
	lineaH1 = new TLine(0.08, 0.55, 0.09, 0.55);
	lineaH2 = new TLine(0.08, 0.15, 0.09, 0.15);
	lineaH3 = new TLine(0.98, 0.55, 0.97, 0.55);
	lineaH4 = new TLine(0.98, 0.15, 0.97, 0.15);
	
	lineaV1->SetLineColor(kBlack);
	lineaV2->SetLineColor(kBlack);
	lineaH1->SetLineColor(kBlack);
	lineaH2->SetLineColor(kBlack);
	lineaH3->SetLineColor(kBlack);
	lineaH4->SetLineColor(kBlack);
	
	lineaV1->Draw();
	lineaV2->Draw();
	lineaH1->Draw();
	lineaH2->Draw();
	lineaH3->Draw();
	lineaH4->Draw();
        
        // Definir la matriz (3x3 en este caso)
   	const int filas = 6;
    	const int columnas = 6;
    	const char* matriz[filas][columnas] = {
        {"#color[38]{|0#GT^{#otimes#color[9]{5}}}#color[2]{|2#GT^{#otimes#color[9]{5}}} + ", "|1#GT^{#otimes#color[9]{5}}|4#GT^{#otimes#color[9]{5}} + ", "|2#GT^{#otimes#color[9]{5}}|8#GT^{#otimes#color[9]{5}} + ", "|3#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}} + ", "|4#GT^{#otimes#color[9]{5}}|11#GT^{#otimes#color[9]{5}} + ", " |5#GT^{#otimes#color[9]{5}}|1#GT^{#otimes#color[9]{5}}"},
        
        {"#color[39]{|6#GT^{#otimes#color[9]{5}}}#color[2]{|2#GT^{#otimes#color[9]{5}}} + ", "|7#GT^{#otimes#color[9]{5}}|4#GT^{#otimes#color[9]{5}} + ", "|8#GT^{#otimes#color[9]{5}}|8#GT^{#otimes#color[9]{5}} + ", "|9#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}} + ", "|10#GT^{#otimes#color[9]{5}}|11#GT^{#otimes#color[9]{5}} + ", " |11#GT^{#otimes#color[9]{5}}|1#GT^{#otimes#color[9]{5}}"},
        
        {"#color[6]{|12#GT^{#otimes#color[9]{5}}}#color[2]{|2#GT^{#otimes#color[9]{5}}} + ", "|13#GT^{#otimes#color[9]{5}}|4#GT^{#otimes#color[9]{5}} + ", "|14#GT^{#otimes#color[9]{5}}|8#GT^{#otimes#color[9]{5}} + ", "|15#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}} + ", "|16#GT^{#otimes#color[9]{5}}|11#GT^{#otimes#color[9]{5}} + ", " |17#GT^{#otimes#color[9]{5}}|1#GT^{#otimes#color[9]{5}}"},
        
        {"#color[46]{|18#GT^{#otimes#color[9]{5}}}#color[2]{|2#GT^{#otimes#color[9]{5}}} + ", "|19#GT^{#otimes#color[9]{5}}|4#GT^{#otimes#color[9]{5}} + ", "|20#GT^{#otimes#color[9]{5}}|8#GT^{#otimes#color[9]{5}} + ", "|21#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}} + ", "|22#GT^{#otimes#color[9]{5}}|11#GT^{#otimes#color[9]{5}} + ", " |23#GT^{#otimes#color[9]{5}}|1#GT^{#otimes#color[9]{5}}"},
        
        {"#color[8]{|24#GT^{#otimes#color[9]{5}}}#color[2]{|2#GT^{#otimes#color[9]{5}}} + ", "|25#GT^{#otimes#color[9]{5}}|4#GT^{#otimes#color[9]{5}} + ", "|26#GT^{#otimes#color[9]{5}}|8#GT^{#otimes#color[9]{5}} + ", "|27#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}} + ", "|28#GT^{#otimes#color[9]{5}}|11#GT^{#otimes#color[9]{5}} + ", " |29#GT^{#otimes#color[9]{5}}|1#GT^{#otimes#color[9]{5}}"},
        
        {"#color[7]{|30#GT^{#otimes#color[9]{5}}}#color[2]{|2#GT^{#otimes#color[9]{5}}} + ", "|31#GT^{#otimes#color[9]{5}}|4#GT^{#otimes#color[9]{5}}"}
      };  
        //Posiciones para dibujar la matriz
    	double xMin = 0.03, xMax = 0.85; 
    	double yMin = 0.15, yMax = 0.55; 
    	double dx = (xMax - xMin) / columnas; 
    	double dy = (yMax - yMin) / filas;   
	
	TLatex latex;
    	latex.SetTextSize(0.027);
    	for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
        // Posición de cada elemento en el centro de cada celda
        double xPos = xMin + (j + 0.5) * dx;
        double yPos = yMax - (i + 0.5) * dy;
        latex.DrawLatex(xPos, yPos, matriz[i][j]);
        }
       }
        
        //Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.02, 0.10, "Proposed measurement of #font[62]{|w#GT^{#otimes#color[9]{5}}} is #font[62]{#color[2]{|2#GT^{#otimes#color[9]{5}}}}");
        
        //Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso3_Quantum1_Exp->SetTextFont(42);
	Paso3_Quantum1_Exp->SetFillColor(0); 
	Paso3_Quantum1_Exp->SetShadowColor(kGray);
	Paso3_Quantum1_Exp->SetTextAlign(12);
	Paso3_Quantum1_Exp->SetMargin(0.01);
	Paso3_Quantum1_Exp->AddText("The #font[62]{step 3} obtains the #font[62]{resulting matrix} after performing the summation of the equation. This matrix is organized to make it possible to observe");
	Paso3_Quantum1_Exp->AddText("Each record of #font[62]{|w#GT^{#otimes#color[9]{5}}} is used to identify the #font[62]{periodicity} of the function. Then, a random value from #font[62]{|w#GT^{#otimes#color[9]{5}}} is selected, which has been highlighted, and");
	Paso3_Quantum1_Exp->AddText("based on that number, various possible results of #font[62]{|x#GT^{#otimes#color[9]{5}}} are recorded with a #font[62]{normalization depending on the number of possible elements}.");
	Paso3_Quantum1_Exp->AddText("These elements are evaluated in the #font[62]{QFT^{+}} to take advantage of the properties of #font[62]{interference} by eliminating values. The new values will be evaluated");
	Paso3_Quantum1_Exp->AddText("in the next step to complete the factorization.");
 	Paso3_Quantum1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1); 
       
        }
	if(Breakopt==4){
	
	//Titulo
        TPaveText *Paso3_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_cuantico->SetTextFont(62);
	Paso3_cuantico->SetFillColor(kMagenta-10); 
	Paso3_cuantico->SetShadowColor(kGray);
	Paso3_cuantico->SetMargin(0);
	Paso3_cuantico->AddText("Step #3");
	Paso3_cuantico->Draw();
	
	//Texto 1
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.80, "#font[62]{Possible results}#font[62]{|x#GT^{#otimes#color[9]{5}}} ");
        
        //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.2, 0.70, "#font[62]{|x#GT^{#otimes#color[9]{4}}} = #font[62]{#frac{1}{#sqrt{6}} [#color[38]{|0#GT^{#otimes#color[9]{5}}}} + #font[62]{#color[39]{|6#GT^{#otimes#color[9]{5}}}} + #font[62]{#color[6]{|12#GT^{#otimes#color[9]{5}}}} + #font[62]{#color[46]{|18#GT^{#otimes#color[9]{5}}}} + #font[62]{#color[8]{|24#GT^{#otimes#color[9]{5}}}} + #font[62]{#color[7]{|30#GT^{#otimes#color[9]{5}}}}]#otimes#color[2]{|2#GT^{#otimes#color[9]{5}}}");
        
        //Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.01, 0.60, "#font[62]{Apply the QFT^{+} to #font[62]{#color[4]{|x#GT^{#otimes#color[9]{5}}}}}");
        
        //Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.01, 0.50, "QFT^{+}#color[4]{|x#GT^{#otimes#color[9]{5}}} = #frac{1}{#sqrt{32}}#sum_{y=0}^{31} e^{#frac{-2#pi i#color[4]{x}y}{32}}|y#GT^{#otimes#color[9]{5}}");
        
        //Texto 5
        l5->SetTextSize(0.04);
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.01, 0.35, "QFT^{+}#color[1]{|x#GT^{#otimes#color[9]{5}}} = #frac{1}{#sqrt{6}}#frac{1}{#sqrt{32}}#sum_{y=0}^{31}[e^{#frac{-#color[38]{0}#pi iy}{16}} + e^{#frac{-#color[39]{6}#pi iy}{16}} + e^{#frac{-#color[6]{12}#pi iy}{16}} + e^{#frac{-#color[46]{18}#pi iy}{16}} + e^{#frac{-#color[8]{24}#pi iy}{16}} + e^{#frac{-#color[7]{30}#pi iy}{16}}]|y#GT^{#otimes#color[9]{5}}");
        
        //Texto 6
        l6->SetTextSize(0.04);
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.01, 0.20, "QFT^{+}#color[1]{|x#GT^{#otimes#color[9]{4}}} = #frac{1}{#sqrt{6}}#frac{1}{#sqrt{32}} [6#color[8]{|0#GT^{#otimes#color[9]{5}}} + i#color[40]{|4#GT^{#otimes#color[9]{5}}} - i#color[43]{|6#GT^{#otimes#color[9]{5}}} + i#color[46]{|10#GT^{#otimes#color[9]{4}}} + 1#color[44]{|12#GT^{#otimes#color[9]{5}}} + 16#color[31]{|16#GT^{#otimes#color[9]{5}}} + 1#color[32]{|20#GT^{#otimes#color[9]{5}}} - i#color[33]{|22#GT^{#otimes#color[9]{5}}} + i#color[34]{|26#GT^{#otimes#color[9]{5}}}]");

	//Texto 8
	l7->SetTextSize(0.04);
	l7->SetTextFont(42); 
	l7->SetTextColor(1); 
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.01, 0.05, "#font[62]{Values For the next step:} #color[39]{|0#GT^{#otimes#color[9]{5}}}, #color[6]{|4#GT^{#otimes#color[9]{5}}}, #color[6]{|6#GT^{#otimes#color[9]{5}}}, #color[39]{|10#GT^{#otimes#color[9]{5}}}, #color[6]{|12#GT^{#otimes#color[9]{5}}}, #color[39]{|16#GT^{#otimes#color[9]{5}}}, #color[39]{|20#GT^{#otimes#color[9]{5}}}, #color[39]{|22#GT^{#otimes#color[9]{5}}}, #color[39]{|26#GT^{#otimes#color[9]{5}}}");
	
        //Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso3_Quantum1_Exp->SetTextFont(42);
	Paso3_Quantum1_Exp->SetFillColor(0); 
	Paso3_Quantum1_Exp->SetShadowColor(kGray);
	Paso3_Quantum1_Exp->SetTextAlign(12);
	Paso3_Quantum1_Exp->SetMargin(0.01);
	Paso3_Quantum1_Exp->AddText("The #font[62]{step 3} obtains the #font[62]{resulting matrix} after performing the summation of the equation. This matrix is organized to make it possible to observe");
	Paso3_Quantum1_Exp->AddText("Each record of #font[62]{|w#GT^{#otimes#color[9]{5}}} is used to identify the #font[62]{periodicity} of the function. Then, a random value from #font[62]{|w#GT^{#otimes#color[9]{5}}} is selected, which has been highlighted, and");
	Paso3_Quantum1_Exp->AddText("based on that number, various possible results of #font[62]{|x#GT^{#otimes#color[9]{5}}} are recorded with a #font[62]{normalization depending on the number of possible elements}.");
	Paso3_Quantum1_Exp->AddText("These elements are evaluated in the #font[62]{QFT^{+}} to take advantage of the properties of #font[62]{interference} by eliminating values. The new values will be evaluated");
	Paso3_Quantum1_Exp->AddText("in the next step to complete the factorization.");
 	Paso3_Quantum1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1); 
        
	}
        if(Breakopt==5){
        
        //Titulo
	TPaveText *Paso4_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso4_cuantico->SetTextFont(62);
	
	Paso4_cuantico->SetFillColor(kCyan-10); 
	Paso4_cuantico->SetShadowColor(kGray);
	Paso4_cuantico->SetMargin(0);
	Paso4_cuantico->AddText("Step #4");
	Paso4_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
	
	//Resultado 1 Num Fac. p1
	TPaveText *resultado1 = new TPaveText(0.001, 0.55, 0.5, 0.83); 
	resultado1->SetTextFont(42);
	resultado1->SetFillColor(0); 
	resultado1->SetShadowColor(kGray);
	resultado1->SetMargin(0);
	resultado1->AddText("");
	resultado1->AddText("Measured value #font[62]{#color[6]{|4#GT^{#otimes#color[9]{5}}}}");
	resultado1->AddText("");
	resultado1->AddText("Result: #frac{jN*}{r} = M  #frac{j21}{r} = #color[6]{4}  j = 8, r = 42");
	resultado1->AddText("");
	resultado1->AddText("X = 2^{#frac{48}{2}} mod 21 = 8");
	resultado1->AddText("");
	resultado1->AddText("#color[2]{P} = GCD(X+1, N)  #color[2]{P} = GCD(9, 21) = 3  #color[2]{P} = 3");
	resultado1->AddText("");
	resultado1->Draw();
	
	//Resultado 1 Num Fac. q1
	TPaveText *resultado2 = new TPaveText(0.5, 0.55, 0.999, 0.83); 
	resultado2->SetTextFont(42);
	resultado2->SetFillColor(0); 
	resultado2->SetShadowColor(kGray);
	resultado2->SetMargin(0);
	resultado2->AddText("");
	resultado2->AddText("Measured value #font[62]{#color[6]{|4#GT^{#otimes#color[9]{5}}}}");
	resultado2->AddText("");
	resultado2->AddText("Result: #frac{jN*}{r} = M  #frac{j21}{r} = #color[6]{4}  j = 8, r = 42");
	resultado2->AddText("");
	resultado2->AddText("X = 2^{#frac{48}{2}} mod 21 = 8");
	resultado2->AddText("");
	resultado2->AddText("#color[8]{Q} = GCD(X-1, N)  #color[8]{Q} = GCD(7, 21) = 7  #color[8]{Q} = 7");
	resultado2->AddText("");
	resultado2->Draw();

	//Resultado 1 Num Fac. p2
	TPaveText *resultado3 = new TPaveText(0.001, 0.27, 0.5, 0.54); 
	resultado3->SetTextFont(42);
	resultado3->SetFillColor(0); 
	resultado3->SetShadowColor(kGray);
	resultado3->SetMargin(0);
	resultado3->AddText("");
	resultado3->AddText("Measured value #font[62]{#color[6]{|6#GT^{#otimes#color[9]{5}}}}");
	resultado3->AddText("");
	resultado3->AddText("Result: #frac{jN*}{r} = M  #frac{j21}{r} = #color[6]{6}  j = 4, r = 14");
	resultado3->AddText("");
	resultado3->AddText("X = 2^{#frac{14}{2}} mod 21 = 2");
	resultado3->AddText("");
	resultado3->AddText("#color[2]{P} = GCD(X+1, N)  #color[2]{P} = GCD(3, 21) = 3  #color[2]{P} = 3");
	resultado3->AddText("");
	resultado3->Draw();
	
	//Resultado 1 Num Fac. q2
	TPaveText *resultado4 = new TPaveText(0.5, 0.27, 0.999, 0.54); 
	resultado4->SetTextFont(42);
	resultado4->SetFillColor(0); 
	resultado4->SetShadowColor(kGray);
	resultado4->SetMargin(0);
	resultado4->AddText("");
	resultado4->AddText("Measured value #font[62]{#color[6]{|6#GT^{#otimes#color[9]{5}}}}");
	resultado4->AddText("");
	resultado4->AddText("Result: #frac{jN*}{r} = M  #frac{j21}{r} = #color[6]{6}  j = 4, r = 14");
	resultado4->AddText("");
	resultado4->AddText("X = 2^{#frac{14}{2}} mod 21 = 2");
	resultado4->AddText("");
	resultado4->AddText("#color[8]{Q} = GCD(X-1, N)  #color[8]{Q} = GCD(1, 21) = 1  #color[8]{Q} = 1  Partial Solution");
	resultado4->AddText("");
	resultado4->Draw();
	
	//Resultado 1 Num Fac. p3
	TPaveText *resultado5 = new TPaveText(0.001, 0.01, 0.5, 0.26);
	resultado5->SetTextFont(42);
	resultado5->SetFillColor(0); 
	resultado5->SetShadowColor(kGray);
	resultado5->SetMargin(0);
	resultado5->AddText("");
	resultado5->AddText("Measured value #font[62]{#color[6]{|12#GT^{#otimes#color[9]{5}}}}");
	resultado5->AddText("");
	resultado5->AddText("Result: #frac{jN*}{r} = M  #frac{j21}{r} = #color[6]{12}  j = 4, r = 6");
	resultado5->AddText("");
	resultado5->AddText("X = 2^{#frac{6}{2}} mod 21 = 8");
	resultado5->AddText("");
	resultado5->AddText("#color[2]{P} = GCD(X+1, N)  #color[2]{P} = GCD(9, 21) = 3  #color[2]{P} = 3");
	resultado5->AddText("");
	resultado5->Draw();
	
	//Resultado 1 Num Fac. q3
	TPaveText *resultado6 = new TPaveText(0.5, 0.01, 0.999, 0.26); 
	resultado6->SetTextFont(42);
	resultado6->SetFillColor(0); 
	resultado6->SetShadowColor(kGray);
	resultado6->SetMargin(0);
	resultado6->AddText("");
	resultado6->AddText("Measured value #font[62]{#color[6]{|12#GT^{#otimes#color[9]{4}}}}");
	resultado6->AddText("");
	resultado6->AddText("Result: #frac{jN*}{r} = M  #frac{j21}{r} = #color[6]{12}  j = 4, r = 6");
	resultado6->AddText("");
	resultado6->AddText("X = 2^{#frac{6}{2}} mod 21 = 8");
	resultado6->AddText("");
	resultado6->AddText("#color[8]{Q} = GCD(X-1, N)  #color[8]{Q} = GCD(7, 21) = 7  #color[8]{Q} = 7");
	resultado6->AddText("");
	resultado6->Draw();
        
        //Segundo canvas    	
     	TCanvas *ExpPaso4 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso4->SetFillColor(0);
	ExpPaso4->SetEditable(1);
	ExpPaso4->Clear();
	ExpPaso4->Update();
	
	TPaveText *Paso4_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	
	Paso4_Quantum1_Exp->SetTextFont(42);
	Paso4_Quantum1_Exp->SetFillColor(0); 
	Paso4_Quantum1_Exp->SetShadowColor(0);
	Paso4_Quantum1_Exp->SetTextAlign(12);
	Paso4_Quantum1_Exp->SetMargin(0.01);
	Paso4_Quantum1_Exp->AddText("For #font[62]{step 4}, the results are evaluated under the condition #font[62]{#frac{jN}{r} = M}, which determines the value of #font[62]{r}. Given the choice of #font[62]{a}, it is observed that");
	Paso4_Quantum1_Exp->AddText("the results of the factorization are of #font[62]{trivial} and #font[62]{invalid} types. Therefore, for this selected value of #font[62]{a}, the operations are insufficient, and it becomes");
	Paso4_Quantum1_Exp->AddText("necessary to choose another value coprime with #font[62]{N} to repeat the algorithm again and obtain other possible results that factor the given number.");
 	Paso4_Quantum1_Exp->Draw();     	
     	
     	ExpPaso4->Update();
	ExpPaso4->SetEditable(1);
        } 
      }  
      break;
      case 4:{
        if(Breakopt==1){
        //Titulo
	TPaveText *Paso1_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso1_cuantico->SetTextFont(62);
	Paso1_cuantico->SetFillColor(kBlue-10); 
	Paso1_cuantico->SetShadowColor(kGray);
	Paso1_cuantico->SetMargin(0);
	Paso1_cuantico->AddText("Step #1");
	Paso1_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
	
	//Texto 1
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 32 #color[9]{n = 5}");
	
	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "states: #font[62]{#color[1]{|x#GT^{#otimes#color[9]{5}}}}#font[62]{#color[1]{|w#GT^{#otimes#color[9]{5}}}}");
	
	//Flecha 1
	flecha1 = new TArrow(0.23, 0.60, 0.37, 0.60, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	//Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.40, 0.60, "#font[62]{#color[1]{|0#GT^{#otimes#color[9]{5}}}}#font[62]{#color[1]{|0#GT^{#otimes#color[9]{5}}}}");
	
	//Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.03, 0.40, "Applying the #font[62]{#color[2]{Hadamard}} gate to the kets #font[62]{#color[1]{|x#GT^{#otimes#color[9]{5}}}}");
	
	//Texto 6
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.08, 0.25, "[#color[2]{H^{#otimes 5}}#color[1]{|x#GT^{#otimes#color[9]{5}}}]#color[1]{|w#GT^{#otimes#color[9]{5}}} = #frac{1}{#sqrt{32}}[#sum_{x=0}^{31}#color[1]{|x#GT^{#otimes#color[9]{5}}}]#color[1]{|0#GT^{#otimes#color[9]{5}}}");
	
	//Cuadros explicativos
	TPaveText *Estados_example_1 = new TPaveText(0.55, 0.5, 0.99, 0.75); 
	Estados_example_1->SetTextFont(42);
	Estados_example_1->SetFillColor(kRed-10); 
	Estados_example_1->SetShadowColor(kGray);
	Estados_example_1->SetMargin(0);
	Estados_example_1->AddText("");
	Estados_example_1->AddText("The initial states of #font[62]{|x#GT and |w#GT}");
	Estados_example_1->AddText("will always be in #font[62]{|0#GT}");
	Estados_example_1->AddText("");
	Estados_example_1->Draw();
	
	TPaveText *Comp_H = new TPaveText(0.55, 0.4, 0.99, 0.1); 
	Comp_H->SetTextFont(42);
	Comp_H->SetFillColor(kMagenta-10); 
	Comp_H->SetShadowColor(kGray);
	Comp_H->SetMargin(0);
	Comp_H->AddText("");
	Comp_H->AddText("the #font[62]{Hadamard} operation creates");
	Comp_H->AddText("the states in #font[62]{superposition} that are");
	Comp_H->AddText("#font[62]{equiprobable}.");
	Comp_H->AddText("");
	Comp_H->Draw();
	
	//Segundo canvas    	
     	TCanvas *ExpPaso1 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1->SetFillColor(0);
	ExpPaso1->SetEditable(1);
	ExpPaso1->Clear();
	ExpPaso1->Update();
	
	TPaveText *Paso1_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.999, 0.99);
	
	Paso1_Quantum1_Exp->SetTextFont(42);
	Paso1_Quantum1_Exp->SetFillColor(0); 
	Paso1_Quantum1_Exp->SetShadowColor(kGray);
	Paso1_Quantum1_Exp->SetTextAlign(12);
	Paso1_Quantum1_Exp->SetMargin(0.01);
	Paso1_Quantum1_Exp->AddText("For #font[62]{Step 1}, the #font[62]{number of states} of the denoted system is defined as #font[62]{N*}, where the number of #font[62]{Qubits} #font[62]{n} is determined.");
	Paso1_Quantum1_Exp->AddText("The possible states are written in the form of a #font[62]{summation} due to the #font[62]{Hadamard} gate and the use of #font[62]{Dirac notation with the power}");
	Paso1_Quantum1_Exp->AddText("#font[62]{of the tensor product and the number n} indicates the number of #font[62]{Qubits} used to represent each possible state, thus the representation of a state");
	Paso1_Quantum1_Exp->AddText("random within that interval will be in the form: #font[62]{|x#GT^{#otimes n} = |x#GT#otimes|x#GT#otimes|x#GT#otimes|x#GT ...#otimes|x#GT (n times)}");
 	Paso1_Quantum1_Exp->Draw();     	
     	
     	ExpPaso1->Update();
	ExpPaso1->SetEditable(1); 
        
        }
        if(Breakopt==2){
        //Titulo
        TPaveText *Paso2_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso2_cuantico->SetTextFont(62);
	Paso2_cuantico->SetFillColor(kGreen-10); 
	Paso2_cuantico->SetShadowColor(kGray);
	Paso2_cuantico->SetMargin(0);
	Paso2_cuantico->AddText("Step #2");
	Paso2_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
        
        //Texto 1
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 32 #color[9]{n = 5}");
        
        //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.03, 0.65, "By applying the operator #color[2]{U_{a,N}} we obtain:");
        
        //Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.55, "#color[2]{U_{a,N}}(#frac{1}{#sqrt{32}}[#sum_{x=0}^{31}|x#GT^{#otimes#color[9]{5}}]|0#GT^{#otimes#color[9]{5}}) = #frac{1}{#sqrt{32}}[#sum_{x=0}^{31}|x#GT^{#otimes#color[9]{5}}]#color[2]{|0#oplusF_{a,N}#GT^{#otimes#color[9]{5}}}");
        
        //Cuadros explicativos
	TPaveText *Operador_Uf = new TPaveText(0.55, 0.40, 0.99, 0.65); 
	Operador_Uf->SetTextFont(42);
	Operador_Uf->SetFillColor(kMagenta-8); 
	Operador_Uf->SetShadowColor(kGray);
	Operador_Uf->SetMargin(0);
	Operador_Uf->AddText("");
	Operador_Uf->AddText("#font[62]{Modulo 2 Addition Property}");
	Operador_Uf->AddText("");
	Operador_Uf->AddText("#font[62]{|0#oplusF_{a,N}#GT^{#otimes#color[9]{5}} = |F_{a,N}#GT^{#otimes#color[9]{5}} =|a^{r}mod N#GT^{#otimes#color[9]{5}}}");
	Operador_Uf->AddText("");
	Operador_Uf->Draw();
        
        //Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.30, "The final result after substituting the values is:");
        
        //Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.2, 0.20, "#color[2]{U_{a,N}}(#frac{1}{#sqrt{32}}[#sum_{x=0}^{31}|x#GT^{#otimes#color[9]{5}}]|0#GT^{#otimes#color[9]{5}}) = #frac{1}{#sqrt{32}}[#sum_{x=0}^{31}|x#GT^{#otimes#color[9]{5}}]#color[2]{|4^{r}mod 21 #GT^{#otimes#color[9]{5}}}");
        
        //Segundo canvas    	
     	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	
	TPaveText *Paso2_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.999, 0.99);
	
	Paso2_Quantum1_Exp->SetTextFont(42);
	Paso2_Quantum1_Exp->SetFillColor(0); 
	Paso2_Quantum1_Exp->SetShadowColor(kGray);
	Paso2_Quantum1_Exp->SetTextAlign(12);
	Paso2_Quantum1_Exp->SetMargin(0.01);
	Paso2_Quantum1_Exp->AddText("For #font[62]{step 2}, the unitary operator #font[62]{U_{a,N}} is applied to the previous result. This, in turn, performs the #font[62]{modulo 2 addition} operation");
	Paso2_Quantum1_Exp->AddText("which satisfies an important property because the ket #font[62]{|w#GT} is initialized in the state #font[62]{|0#GT}, as shown in the box.");
	Paso2_Quantum1_Exp->AddText("The final result applies the function #font[62]{F_{a,N} = a^{r}mod N}, which is #font[62]{periodic} and takes the values of #font[62]{r} as #font[62]{1, 2, 3, 4, 5, 6 ...}");
 	Paso2_Quantum1_Exp->Draw();     	
     	
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(1);
        
        }
        if(Breakopt==3){
        //Titulo
        TPaveText *Paso3_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_cuantico->SetTextFont(62);
	Paso3_cuantico->SetFillColor(kMagenta-10); 
	Paso3_cuantico->SetShadowColor(kGray);
	Paso3_cuantico->SetMargin(0);
	Paso3_cuantico->AddText("Step #3");
	Paso3_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
       
	//Texto 1
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.03, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 32 #color[9]{n = 5}");
        
        //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.03, 0.70, "Equation: #frac{1}{#sqrt{32}}[#sum_{x=0}^{31}|x#GT^{#otimes#color[9]{5}}]#color[1]{|4^{r}mod 21 #GT^{#otimes#color[9]{5}}}");
        
        //Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "Matrix response of the equation with the states: #font[62]{#color[1]{|x#GT^{#otimes#color[9]{5}}}}#font[62]{#color[2]{|w#GT^{#otimes#color[9]{5}}}}");
        
        //Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.02, 0.40, "#frac{1}{#sqrt{32}}");
        
        //Lineas para delimitar la matriz
	lineaV1 = new TLine(0.08, 0.15, 0.08, 0.55);
	lineaV2 = new TLine(0.98, 0.15, 0.98, 0.55);
	
	lineaH1 = new TLine(0.08, 0.55, 0.09, 0.55);
	lineaH2 = new TLine(0.08, 0.15, 0.09, 0.15);
	lineaH3 = new TLine(0.98, 0.55, 0.97, 0.55);
	lineaH4 = new TLine(0.98, 0.15, 0.97, 0.15);
	
	lineaV1->SetLineColor(kBlack);
	lineaV2->SetLineColor(kBlack);
	lineaH1->SetLineColor(kBlack);
	lineaH2->SetLineColor(kBlack);
	lineaH3->SetLineColor(kBlack);
	lineaH4->SetLineColor(kBlack);
	
	lineaV1->Draw();
	lineaV2->Draw();
	lineaH1->Draw();
	lineaH2->Draw();
	lineaH3->Draw();
	lineaH4->Draw();
        
        // Definir la matriz (3x3 en este caso)
   	const int filas = 6;
    	const int columnas = 6;
    	const char* matriz[filas][columnas] = {
        {"#color[38]{|0#GT^{#otimes#color[9]{5}}}#color[2]{|4#GT^{#otimes#color[9]{5}}}   + ", "|1#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}} + ", " |2#GT^{#otimes#color[9]{5}}|1#GT^{#otimes#color[9]{5}} + ", "#color[39]{|3#GT^{#otimes#color[9]{5}}}#color[2]{|4#GT^{#otimes#color[9]{5}}} + ", "|4#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}} + ", " |5#GT^{#otimes#color[9]{5}}|1#GT^{#otimes#color[9]{5}}"},
        {"#color[39]{|6#GT^{#otimes#color[9]{5}}}#color[2]{|4#GT^{#otimes#color[9]{5}}}   + ", "|7#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}} + ", "|8#GT^{#otimes#color[9]{5}}|1#GT^{#otimes#color[9]{5}} + ", "#color[39]{|9#GT^{#otimes#color[9]{5}}}#color[2]{|4#GT^{#otimes#color[9]{5}}} + ", "|10#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}} + ", " |11#GT^{#otimes#color[9]{5}}|1#GT^{#otimes#color[9]{5}}"},
        {"#color[6]{|12#GT^{#otimes#color[9]{5}}}#color[2]{|4#GT^{#otimes#color[9]{5}}} + ", "|13#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}} + ", " |14#GT^{#otimes#color[9]{5}}|1#GT^{#otimes#color[9]{5}} + ", "#color[46]{|15#GT^{#otimes#color[9]{5}}}#color[2]{|4#GT^{#otimes#color[9]{5}}} + ", "|16#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}} + ", " |17#GT^{#otimes#color[9]{5}}|1#GT^{#otimes#color[9]{5}}"},
        {"#color[8]{|18#GT^{#otimes#color[9]{5}}}#color[2]{|4#GT^{#otimes#color[9]{5}}} + ", "|19#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}} + ", " |20#GT^{#otimes#color[9]{5}}|1#GT^{#otimes#color[9]{5}} + ", "#color[7]{|21#GT^{#otimes#color[9]{5}}}#color[2]{|4#GT^{#otimes#color[9]{5}}} + ", "|22#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}} + ", " |23#GT^{#otimes#color[9]{5}}|1#GT^{#otimes#color[9]{5}}"},
        {"#color[39]{|24#GT^{#otimes#color[9]{5}}}#color[2]{|4#GT^{#otimes#color[9]{5}}} + ", "|25#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}} + ", " |26#GT^{#otimes#color[9]{5}}|1#GT^{#otimes#color[9]{5}} + ", "#color[39]{|27#GT^{#otimes#color[9]{5}}}#color[2]{|4#GT^{#otimes#color[9]{5}}} + ", "|28#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}} + ", " |29#GT^{#otimes#color[9]{5}}|1#GT^{#otimes#color[9]{5}}"},
        {"#color[39]{|30#GT^{#otimes#color[9]{5}}}#color[2]{|4#GT^{#otimes#color[9]{5}}} + ", "|31#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}}"}
      };  
        //Posiciones para dibujar la matriz
    	double xMin = 0.03, xMax = 0.90; 
    	double yMin = 0.10, yMax = 0.55; 
    	double dx = (xMax - xMin) / columnas; 
    	double dy = (yMax - yMin) / filas;   
	
	TLatex latex;
	latex.SetTextSize(0.025);
    	for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
        // Posición de cada elemento en el centro de cada celda
        double xPos = xMin + (j + 0.5) * dx;
        double yPos = yMax - (i + 0.5) * dy;
        latex.DrawLatex(xPos, yPos, matriz[i][j]);
        }
       }
        
        //Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.02, 0.08, "Proposed measurement of #font[62]{|w#GT^{#otimes#color[9]{5}}} is #font[62]{#color[2]{|4#GT^{#otimes#color[9]{5}}}}");
	
	//Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso3_Quantum1_Exp->SetTextFont(42);
	Paso3_Quantum1_Exp->SetFillColor(0); 
	Paso3_Quantum1_Exp->SetShadowColor(kGray);
	Paso3_Quantum1_Exp->SetTextAlign(12);
	Paso3_Quantum1_Exp->SetMargin(0.01);
	Paso3_Quantum1_Exp->AddText("The #font[62]{step 3} obtains the #font[62]{resulting matrix} after performing the summation of the equation. This matrix is organized to make it possible to observe");
	Paso3_Quantum1_Exp->AddText("Each record of #font[62]{|w#GT^{#otimes#color[9]{5}}} is used to identify the #font[62]{periodicity} of the function. Then, a random value from #font[62]{|w#GT^{#otimes#color[9]{5}}} is selected, which has been highlighted, and");
	Paso3_Quantum1_Exp->AddText("based on that number, various possible results of #font[62]{|x#GT^{#otimes#color[9]{5}}} are recorded with a #font[62]{normalization depending on the number of possible elements}.");
	Paso3_Quantum1_Exp->AddText("These elements are evaluated in the #font[62]{QFT^{+}} to take advantage of the properties of #font[62]{interference} by eliminating values. The new values will be evaluated");
	Paso3_Quantum1_Exp->AddText("in the next step to complete the factorization.");
 	Paso3_Quantum1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1); 
	}
	
	if(Breakopt==4){
      	//Titulo
        TPaveText *Paso3_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_cuantico->SetTextFont(62);
	Paso3_cuantico->SetFillColor(kMagenta-10); 
	Paso3_cuantico->SetShadowColor(kGray);
	Paso3_cuantico->SetMargin(0);
	Paso3_cuantico->AddText("Step #3");
	Paso3_cuantico->Draw();
	
	//Texto 1
	l1->SetTextFont(42); 
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.80, "#font[62]{Possible results}#font[62]{|x#GT^{#otimes#color[9]{5}}}");
	
	//Texto 2
	l2->SetTextSize(0.04); 
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.01, 0.70, "#font[62]{|x#GT^{#otimes#color[9]{4}}} = #font[62]{#frac{1}{#sqrt{11}} [#color[38]{|0#GT^{#otimes#color[9]{5}}}} + #font[62]{#color[39]{|3#GT^{#otimes#color[9]{5}}}} + #font[62]{#color[39]{|6#GT^{#otimes#color[9]{5}}}} + #font[62]{#color[39]{|9#GT^{#otimes#color[9]{5}}}} + #font[62]{#color[6]{|12#GT^{#otimes#color[9]{5}}}} + #font[62]{#color[46]{|15#GT^{#otimes#color[9]{5}}}} + #font[62]{#color[8]{|18#GT^{#otimes#color[9]{5}}}} + #font[62]{#color[7]{|21#GT^{#otimes#color[9]{5}}}}+ #font[62]{#color[39]{|24#GT^{#otimes#color[9]{5}}}} + #font[62]{#color[39]{|27#GT^{#otimes#color[9]{5}}}} + #font[62]{#color[39]{|30#GT^{#otimes#color[9]{5}}}}]#otimes#color[2]{|4#GT^{#otimes#color[9]{5}}}");
	
	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.01, 0.60, "#font[62]{Apply the QFT^{+} to #font[62]{#color[4]{|x#GT^{#otimes#color[9]{5}}}}}");
	
	//Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.01, 0.45, "QFT^{+}#color[4]{|x#GT^{#otimes#color[9]{5}}} = #frac{1}{#sqrt{32}}#sum_{y=0}^{31} e^{#frac{-2#pi i#color[4]{x}y}{32}}|y#GT^{#otimes#color[9]{5}}");
		
	//Texto 5
	l5->SetTextSize(0.038);
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.01, 0.30, "QFT^{+}#color[1]{|x#GT^{#otimes#color[9]{5}}} = #frac{1}{#sqrt{11}}#frac{1}{#sqrt{32}}#sum_{y=0}^{31}[e^{#frac{-#color[38]{0}#pi iy}{16}} + e^{#frac{-#color[39]{3}#pi iy}{16}} + e^{#frac{-#color[39]{6}#pi iy}{16}} + e^{#frac{-#color[39]{9}#pi iy}{16}} + e^{#frac{-#color[6]{12}#pi iy}{16}} + e^{#frac{-#color[46]{15}#pi iy}{16}}+ e^{#frac{-#color[8]{18}#pi iy}{16}} + e^{#frac{-#color[7]{21}#pi iy}{16}} + e^{#frac{-#color[39]{24}#pi iy}{16}} + e^{#frac{-#color[39]{27}#pi iy}{16}} + e^{#frac{-#color[39]{30}#pi iy}{16}}]|y#GT^{#otimes#color[9]{5}}");

	//Texto 6
	l6->SetTextSize(0.038);
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.01, 0.15, "#font[62]{Values For the next step:} #color[39]{|0#GT^{#otimes#color[9]{5}}}, #color[6]{|9#GT^{#otimes#color[9]{5}}}, #color[6]{|13#GT^{#otimes#color[9]{12}}}, #color[6]{|14#GT^{#otimes#color[9]{5}}}, #color[39]{|15#GT^{#otimes#color[9]{5}}}, #color[39]{|16#GT^{#otimes#color[9]{5}}}, #color[39]{|17#GT^{#otimes#color[9]{5}}}, #color[39]{|18#GT^{#otimes#color[9]{5}}}, #color[39]{|19#GT^{#otimes#color[9]{5}}}, #color[39]{|23#GT^{#otimes#color[9]{5}}}, #color[39]{|24#GT^{#otimes#color[9]{5}}}");
	      
        //Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso3_Quantum1_Exp->SetTextFont(42);
	Paso3_Quantum1_Exp->SetFillColor(0); 
	Paso3_Quantum1_Exp->SetShadowColor(kGray);
	Paso3_Quantum1_Exp->SetTextAlign(12);
	Paso3_Quantum1_Exp->SetMargin(0.01);
	Paso3_Quantum1_Exp->AddText("The #font[62]{step 3} obtains the #font[62]{resulting matrix} after performing the summation of the equation. This matrix is organized to make it possible to observe");
	Paso3_Quantum1_Exp->AddText("Each record of #font[62]{|w#GT^{#otimes#color[9]{5}}} is used to identify the #font[62]{periodicity} of the function. Then, a random value from #font[62]{|w#GT^{#otimes#color[9]{5}}} is selected, which has been highlighted, and");
	Paso3_Quantum1_Exp->AddText("based on that number, various possible results of #font[62]{|x#GT^{#otimes#color[9]{5}}} are recorded with a #font[62]{normalization depending on the number of possible elements}.");
	Paso3_Quantum1_Exp->AddText("These elements are evaluated in the #font[62]{QFT^{+}} to take advantage of the properties of #font[62]{interference} by eliminating values. The new values will be evaluated");
	Paso3_Quantum1_Exp->AddText("in the next step to complete the factorization.");
 	Paso3_Quantum1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1); 
        
        }
        if(Breakopt==5){
        
        //Titulo
	TPaveText *Paso4_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso4_cuantico->SetTextFont(62);
	
	Paso4_cuantico->SetFillColor(kCyan-10); 
	Paso4_cuantico->SetShadowColor(kGray);
	Paso4_cuantico->SetMargin(0);
	Paso4_cuantico->AddText("Step #4");
	Paso4_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
	
	//Resultado 1 Num Fac. p1
	TPaveText *resultado1 = new TPaveText(0.001, 0.55, 0.5, 0.83); 
	resultado1->SetTextFont(42);
	resultado1->SetFillColor(0); 
	resultado1->SetShadowColor(kGray);
	resultado1->SetMargin(0);
	resultado1->AddText("");
	resultado1->AddText("Measured value #font[62]{#color[6]{|9#GT^{#otimes#color[9]{5}}}}");
	resultado1->AddText("");
	resultado1->AddText("Result: #frac{jN*}{r} = M  #frac{j21}{r} = #color[6]{9}  j = 3, r = 7");
	resultado1->AddText("");
	resultado1->AddText("X = 4^{#frac{7}{2}} mod 21 = ?");
	resultado1->AddText("");
	resultado1->AddText("The result is not valid because te value of r is odd");
	resultado1->AddText("");
	resultado1->Draw();
	
	//Resultado 1 Num Fac. q1
	TPaveText *resultado2 = new TPaveText(0.5, 0.55, 0.999, 0.83); 
	resultado2->SetTextFont(42);
	resultado2->SetFillColor(0); 
	resultado2->SetShadowColor(kGray);
	resultado2->SetMargin(0);
	resultado2->AddText("");
	resultado2->AddText("Measured value #font[62]{#color[6]{|9#GT^{#otimes#color[9]{5}}}}");
	resultado2->AddText("");
	resultado2->AddText("Result: #frac{jN*}{r} = M  #frac{j21}{r} = #color[6]{9}  j = 3, r = 7");
	resultado2->AddText("");
	resultado2->AddText("X = 4^{#frac{7}{2}} mod 21 = ?");
	resultado2->AddText("");
	resultado2->AddText("The result is not valid because te value of r is odd");
	resultado2->AddText("");
	resultado2->Draw();

	//Resultado 1 Num Fac. p2
	TPaveText *resultado3 = new TPaveText(0.001, 0.27, 0.5, 0.54); 
	resultado3->SetTextFont(42);
	resultado3->SetFillColor(0); 
	resultado3->SetShadowColor(kGray);
	resultado3->SetMargin(0);
	resultado3->AddText("");
	resultado3->AddText("Measured value #font[62]{#color[6]{|13#GT^{#otimes#color[9]{5}}}}");
	resultado3->AddText("");
	resultado3->AddText("Result: #frac{jN*}{r} = M  #frac{j21}{r} = #color[6]{13}  j = 13, r = 21");
	resultado3->AddText("");
	resultado3->AddText("X = 4^{#frac{21}{2}} mod 21 = ?");
	resultado3->AddText("");
	resultado3->AddText("The result is not valid because te value of r is odd");
	resultado3->AddText("");
	resultado3->Draw();
	
	//Resultado 1 Num Fac. q2
	TPaveText *resultado4 = new TPaveText(0.5, 0.27, 0.999, 0.54); 
	resultado4->SetTextFont(42);
	resultado4->SetFillColor(0); 
	resultado4->SetShadowColor(kGray);
	resultado4->SetMargin(0);
	resultado4->AddText("");
	resultado4->AddText("Measured value #font[62]{#color[6]{|13#GT^{#otimes#color[9]{5}}}}");
	resultado4->AddText("");
	resultado4->AddText("Result: #frac{jN*}{r} = M  #frac{j21}{r} = #color[6]{13}  j = 13, r = 21");
	resultado4->AddText("");
	resultado4->AddText("X = 4^{#frac{21}{2}} mod 21 = ?");
	resultado4->AddText("");
	resultado4->AddText("The result is not valid because te value of r is odd");
	resultado4->AddText("");
	resultado4->Draw();
	
	//Resultado 1 Num Fac. p3
	TPaveText *resultado5 = new TPaveText(0.001, 0.01, 0.5, 0.26);
	resultado5->SetTextFont(42);
	resultado5->SetFillColor(0); 
	resultado5->SetShadowColor(kGray);
	resultado5->SetMargin(0);
	resultado5->AddText("");
	resultado5->AddText("Measured value #font[62]{#color[6]{|14#GT^{#otimes#color[9]{5}}}}");
	resultado5->AddText("");
	resultado5->AddText("Result: #frac{jN*}{r} = M  #frac{j21}{r} = #color[6]{14}  j = 2, r = 3");
	resultado5->AddText("");
	resultado5->AddText("X = 4^{#frac{3}{2}} mod 21 = ?");
	resultado5->AddText("");
	resultado5->AddText("The result is not valid because te value of r is odd");
	resultado5->AddText("");
	resultado5->Draw();
	
	//Resultado 1 Num Fac. q3
	TPaveText *resultado6 = new TPaveText(0.5, 0.01, 0.999, 0.26); 
	resultado6->SetTextFont(42);
	resultado6->SetFillColor(0); 
	resultado6->SetShadowColor(kGray);
	resultado6->SetMargin(0);
	resultado6->AddText("");
	resultado6->AddText("Measured value #font[62]{#color[6]{|14#GT^{#otimes#color[9]{4}}}}");
	resultado6->AddText("");
	resultado6->AddText("Result: #frac{jN*}{r} = M  #frac{j21}{r} = #color[6]{14}  j = 2, r = 3");
	resultado6->AddText("");
	resultado6->AddText("X = 4^{#frac{3}{2}} mod 21 = ?");
	resultado6->AddText("");
	resultado6->AddText("The result is not valid because te value of r is odd");
	resultado6->AddText("");
	resultado6->Draw();
        
        //Segundo canvas    	
     	TCanvas *ExpPaso4 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso4->SetFillColor(0);
	ExpPaso4->SetEditable(1);
	ExpPaso4->Clear();
	ExpPaso4->Update();
	
	TPaveText *Paso4_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso4_Quantum1_Exp->SetTextFont(42);
	Paso4_Quantum1_Exp->SetFillColor(0); 
	Paso4_Quantum1_Exp->SetShadowColor(0);
	Paso4_Quantum1_Exp->SetTextAlign(12);
	Paso4_Quantum1_Exp->SetMargin(0.01);
	
	Paso4_Quantum1_Exp->AddText("For #font[62]{step 4}, the results are evaluated under the condition #font[62]{#frac{jN}{r} = M}, which determines the value of #font[62]{r}. Given the choice of #font[62]{a}, it is observed that");
	
	Paso4_Quantum1_Exp->AddText("the results of the factorization are of #font[62]{trivial} and #font[62]{invalid} types. Therefore, for this selected value of #font[62]{a}, the operations are insufficient, and it becomes");
	
	Paso4_Quantum1_Exp->AddText("necessary to choose another value coprime with #font[62]{N} to repeat the algorithm again and obtain other possible results that factor the given number.");
 	Paso4_Quantum1_Exp->Draw();     	
     	
     	ExpPaso4->Update();
	ExpPaso4->SetEditable(1);
        
        }
      }  
      break;
      case 5:{
	if(Breakopt==1){
        
        //Titulo
	TPaveText *Paso1_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso1_cuantico->SetTextFont(62);
	Paso1_cuantico->SetFillColor(kBlue-10); 
	Paso1_cuantico->SetShadowColor(kGray);
	Paso1_cuantico->SetMargin(0);
	Paso1_cuantico->AddText("Step #1");
	Paso1_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
	
	//Texto 1
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 32 #color[9]{n = 5}");
	
	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "states: #font[62]{#color[1]{|x#GT^{#otimes#color[9]{5}}}}#font[62]{#color[1]{|w#GT^{#otimes#color[9]{5}}}}");
	
	//Flecha 1
	flecha1 = new TArrow(0.23, 0.60, 0.37, 0.60, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	//Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.40, 0.60, "#font[62]{#color[1]{|0#GT^{#otimes#color[9]{5}}}}#font[62]{#color[1]{|0#GT^{#otimes#color[9]{5}}}}");
	
	//Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.03, 0.40, "Applying the #font[62]{#color[2]{Hadamard}} gate to the kets #font[62]{#color[1]{|x#GT^{#otimes#color[9]{5}}}}");
	
	//Texto 6
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.08, 0.25, "[#color[2]{H^{#otimes 5}}#color[1]{|x#GT^{#otimes#color[9]{5}}}]#color[1]{|w#GT^{#otimes#color[9]{5}}} = #frac{1}{#sqrt{32}}[#sum_{x=0}^{31}#color[1]{|x#GT^{#otimes#color[9]{5}}}]#color[1]{|0#GT^{#otimes#color[9]{5}}}");
	
	//Cuadros explicativos
	TPaveText *Estados_example_1 = new TPaveText(0.55, 0.5, 0.99, 0.75); 
	Estados_example_1->SetTextFont(42);
	Estados_example_1->SetFillColor(kRed-10); 
	Estados_example_1->SetShadowColor(kGray);
	Estados_example_1->SetMargin(0);
	Estados_example_1->AddText("");
	Estados_example_1->AddText("The initial states of #font[62]{|x#GT and |w#GT}");
	Estados_example_1->AddText("will always be in #font[62]{|0#GT}");
	Estados_example_1->AddText("");
	Estados_example_1->Draw();
	
	TPaveText *Comp_H = new TPaveText(0.55, 0.4, 0.99, 0.1); 
	Comp_H->SetTextFont(42);
	Comp_H->SetFillColor(kMagenta-10); 
	Comp_H->SetShadowColor(kGray);
	Comp_H->SetMargin(0);
	Comp_H->AddText("");
	Comp_H->AddText("the #font[62]{Hadamard} operation creates");
	Comp_H->AddText("the states in #font[62]{superposition} that are");
	Comp_H->AddText("#font[62]{equiprobable}.");
	Comp_H->AddText("");
	Comp_H->Draw();
	
	//Segundo canvas    	
     	TCanvas *ExpPaso1 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1->SetFillColor(0);
	ExpPaso1->SetEditable(1);
	ExpPaso1->Clear();
	ExpPaso1->Update();
	
	TPaveText *Paso1_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.999, 0.99);
	Paso1_Quantum1_Exp->SetTextFont(42);
	Paso1_Quantum1_Exp->SetFillColor(0); 
	Paso1_Quantum1_Exp->SetShadowColor(kGray);
	Paso1_Quantum1_Exp->SetTextAlign(12);
	Paso1_Quantum1_Exp->SetMargin(0.01);
	Paso1_Quantum1_Exp->AddText("For #font[62]{Step 1}, the #font[62]{number of states} of the denoted system is defined as #font[62]{N*}, where the number of #font[62]{Qubits} #font[62]{n} is determined.");
	Paso1_Quantum1_Exp->AddText("The possible states are written in the form of a #font[62]{summation} due to the #font[62]{Hadamard} gate and the use of #font[62]{Dirac notation with the power}");
	Paso1_Quantum1_Exp->AddText("#font[62]{of the tensor product and the number n} indicates the number of #font[62]{Qubits} used to represent each possible state, thus the representation of a state");
	Paso1_Quantum1_Exp->AddText("random within that interval will be in the form: #font[62]{|x#GT^{#otimes n} = |x#GT#otimes|x#GT#otimes|x#GT#otimes|x#GT ...#otimes|x#GT (n times)}");
 	Paso1_Quantum1_Exp->Draw();     	
     	
     	ExpPaso1->Update();
	ExpPaso1->SetEditable(1);
   
        }
        if(Breakopt==2){
        //Titulo
        TPaveText *Paso2_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso2_cuantico->SetTextFont(62);
	Paso2_cuantico->SetFillColor(kGreen-10); 
	Paso2_cuantico->SetShadowColor(kGray);
	Paso2_cuantico->SetMargin(0);
	Paso2_cuantico->AddText("Step #2");
	Paso2_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
        
        //Texto 1
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 32 #color[9]{n = 5}");
        
        //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.03, 0.65, "By applying the operator #color[2]{U_{a,N}} we obtain:");
        
        //Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.55, "#color[2]{U_{a,N}}(#frac{1}{#sqrt{32}}[#sum_{x=0}^{31}|x#GT^{#otimes#color[9]{5}}]|0#GT^{#otimes#color[9]{5}}) = #frac{1}{#sqrt{32}}[#sum_{x=0}^{31}|x#GT^{#otimes#color[9]{5}}]#color[2]{|0#oplusF_{a,N}#GT^{#otimes#color[9]{5}}}");
        
        //Cuadros explicativos
	TPaveText *Operador_Uf = new TPaveText(0.55, 0.40, 0.99, 0.65); 
	Operador_Uf->SetTextFont(42);
	Operador_Uf->SetFillColor(kMagenta-8); 
	Operador_Uf->SetShadowColor(kGray);
	Operador_Uf->SetMargin(0);
	Operador_Uf->AddText("");
	Operador_Uf->AddText("#font[62]{Modulo 2 Addition Property}");
	Operador_Uf->AddText("");
	Operador_Uf->AddText("#font[62]{|0#oplusF_{a,N}#GT^{#otimes#color[9]{5}} = |F_{a,N}#GT^{#otimes#color[9]{5}} =|a^{r}mod N#GT^{#otimes#color[9]{5}}}");
	Operador_Uf->AddText("");
	Operador_Uf->Draw();
        
        //Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.30, "The final result after substituting the values is:");
        
        //Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.2, 0.20, "#color[2]{U_{a,N}}(#frac{1}{#sqrt{32}}[#sum_{x=0}^{31}|x#GT^{#otimes#color[9]{5}}]|0#GT^{#otimes#color[9]{5}}) = #frac{1}{#sqrt{32}}[#sum_{x=0}^{31}|x#GT^{#otimes#color[9]{5}}]#color[2]{|5^{r}mod 21 #GT^{#otimes#color[9]{5}}}");
        
        //Segundo canvas    	
     	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	
	TPaveText *Paso2_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.999, 0.99);
	Paso2_Quantum1_Exp->SetTextFont(42);
	Paso2_Quantum1_Exp->SetFillColor(0); 
	Paso2_Quantum1_Exp->SetShadowColor(kGray);
	Paso2_Quantum1_Exp->SetTextAlign(12);
	Paso2_Quantum1_Exp->SetMargin(0.01);
	Paso2_Quantum1_Exp->AddText("For #font[62]{step 2}, the unitary operator #font[62]{U_{a,N}} is applied to the previous result. This, in turn, performs the #font[62]{modulo 2 addition} operation");
	Paso2_Quantum1_Exp->AddText("which satisfies an important property because the ket #font[62]{|w#GT} is initialized in the state #font[62]{|0#GT}, as shown in the box.");
	Paso2_Quantum1_Exp->AddText("The final result applies the function #font[62]{F_{a,N} = a^{r}mod N}, which is #font[62]{periodic} and takes the values of #font[62]{r} as #font[62]{1, 2, 3, 4, 5, 6 ...}");
 	Paso2_Quantum1_Exp->Draw();     	
     	
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(1);
        
        }
        if(Breakopt==3){
        
        //Titulo
        TPaveText *Paso3_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_cuantico->SetTextFont(62);
	Paso3_cuantico->SetFillColor(kMagenta-10); 
	Paso3_cuantico->SetShadowColor(kGray);
	Paso3_cuantico->SetMargin(0);
	Paso3_cuantico->AddText("Step #3");
	Paso3_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
       
	//Texto 1
	l1->SetTextFont(42);
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.03, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 32 #color[9]{n = 5}");
        
        //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.03, 0.70, "Equation: #frac{1}{#sqrt{32}}[#sum_{x=0}^{31}|x#GT^{#otimes#color[9]{5}}]#color[1]{|5^{r}mod 21 #GT^{#otimes#color[9]{5}}}");
        
        //Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "Matrix response of the equation with the states: #font[62]{#color[1]{|x#GT^{#otimes#color[9]{5}}}}#font[62]{#color[2]{|w#GT^{#otimes#color[9]{5}}}}");
        
        //Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.02, 0.40, "#frac{1}{#sqrt{32}}");
        
        //Lineas para delimitar la matriz
	lineaV1 = new TLine(0.08, 0.15, 0.08, 0.55);
	lineaV2 = new TLine(0.98, 0.15, 0.98, 0.55);
	
	lineaH1 = new TLine(0.08, 0.55, 0.09, 0.55);
	lineaH2 = new TLine(0.08, 0.15, 0.09, 0.15);
	lineaH3 = new TLine(0.98, 0.55, 0.97, 0.55);
	lineaH4 = new TLine(0.98, 0.15, 0.97, 0.15);
	
	lineaV1->SetLineColor(kBlack);
	lineaV2->SetLineColor(kBlack);
	lineaH1->SetLineColor(kBlack);
	lineaH2->SetLineColor(kBlack);
	lineaH3->SetLineColor(kBlack);
	lineaH4->SetLineColor(kBlack);
	
	lineaV1->Draw();
	lineaV2->Draw();
	lineaH1->Draw();
	lineaH2->Draw();
	lineaH3->Draw();
	lineaH4->Draw();
        
        // Definir la matriz (3x3 en este caso)
   	const int filas = 6;
    	const int columnas = 6;
    	const char* matriz[filas][columnas] = {
        {"|0#GT^{#otimes#color[9]{5}}|5#GT^{#otimes#color[9]{5}}   + ", "#color[38]{|1#GT^{#otimes#color[9]{5}}}#color[2]{|4#GT^{#otimes#color[9]{5}}} + ", "|2#GT^{#otimes#color[9]{5}}|20#GT^{#otimes#color[9]{5}} + ", "|3#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}} + ", "|4#GT^{#otimes#color[9]{5}}|17#GT^{#otimes#color[9]{5}} + ", " |5#GT^{#otimes#color[9]{5}}|1#GT^{#otimes#color[9]{5}}"},
        {"|6#GT^{#otimes#color[9]{5}}|5#GT^{#otimes#color[9]{5}}   + ", "#color[39]{|7#GT^{#otimes#color[9]{5}}}#color[2]{|4#GT^{#otimes#color[9]{5}}} + ", "|8#GT^{#otimes#color[9]{5}}|20#GT^{#otimes#color[9]{5}} + ", "|9#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}} + ", "|10#GT^{#otimes#color[9]{5}}|17#GT^{#otimes#color[9]{5}} + ", " |11#GT^{#otimes#color[9]{5}}|1#GT^{#otimes#color[9]{5}}"},
        {"|12#GT^{#otimes#color[9]{5}}|5#GT^{#otimes#color[9]{5}} + ", "#color[39]{|13#GT^{#otimes#color[9]{5}}}#color[2]{|4#GT^{#otimes#color[9]{5}}} + ", "|14#GT^{#otimes#color[9]{5}}|20#GT^{#otimes#color[9]{5}} + ", " |15#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}} + ", "   |16#GT^{#otimes#color[9]{5}}|17#GT^{#otimes#color[9]{5}} + ", "     |17#GT^{#otimes#color[9]{5}}|1#GT^{#otimes#color[9]{5}}"},
        {"|18#GT^{#otimes#color[9]{5}}|5#GT^{#otimes#color[9]{5}} + ", "#color[39]{|19#GT^{#otimes#color[9]{5}}}#color[2]{|4#GT^{#otimes#color[9]{5}}} + ", "|20#GT^{#otimes#color[9]{5}}|20#GT^{#otimes#color[9]{5}} + ", " |21#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}} + ", "  |22#GT^{#otimes#color[9]{5}}|17#GT^{#otimes#color[9]{5}} + ", "     |23#GT^{#otimes#color[9]{5}}|1#GT^{#otimes#color[9]{5}}"},
        {"|24#GT^{#otimes#color[9]{5}}|5#GT^{#otimes#color[9]{5}} + ", "#color[6]{|25#GT^{#otimes#color[9]{5}}}#color[2]{|4#GT^{#otimes#color[9]{5}}} + ", "|26#GT^{#otimes#color[9]{5}}|20#GT^{#otimes#color[9]{5}} + ", " |27#GT^{#otimes#color[9]{5}}|16#GT^{#otimes#color[9]{5}} + ", "   |28#GT^{#otimes#color[9]{5}}|17#GT^{#otimes#color[9]{5}} + ", "     |29#GT^{#otimes#color[9]{5}}|1#GT^{#otimes#color[9]{5}}"},
        {"|30#GT^{#otimes#color[9]{5}}|5#GT^{#otimes#color[9]{5}} + ", "#color[46]{|31#GT^{#otimes#color[9]{5}}}#color[2]{|4#GT^{#otimes#color[9]{5}}}"}
      };  
        //Posiciones para dibujar la matriz
    	double xMin = 0.03, xMax = 0.85; 
    	double yMin = 0.15, yMax = 0.55; 
    	double dx = (xMax - xMin) / columnas; 
    	double dy = (yMax - yMin) / filas;   
	
	TLatex latex;
    	latex.SetTextSize(0.030);
    	for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
        // Posición de cada elemento en el centro de cada celda
        double xPos = xMin + (j + 0.5) * dx;
        double yPos = yMax - (i + 0.5) * dy;
        latex.DrawLatex(xPos, yPos, matriz[i][j]);
        }
       }
        
        //Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.02, 0.10, "Proposed measurement of #font[62]{|w#GT^{#otimes#color[9]{5}}} is #font[62]{#color[2]{|4#GT^{#otimes#color[9]{5}}}}"); 
        
        //Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso3_Quantum1_Exp->SetTextFont(42);
	Paso3_Quantum1_Exp->SetFillColor(0); 
	Paso3_Quantum1_Exp->SetShadowColor(kGray);
	Paso3_Quantum1_Exp->SetTextAlign(12);
	Paso3_Quantum1_Exp->SetMargin(0.01);
	Paso3_Quantum1_Exp->AddText("The #font[62]{step 3} obtains the #font[62]{resulting matrix} after performing the summation of the equation. This matrix is organized to make it possible to observe");
	Paso3_Quantum1_Exp->AddText("Each record of #font[62]{|w#GT^{#otimes#color[9]{5}}} is used to identify the #font[62]{periodicity} of the function. Then, a random value from #font[62]{|w#GT^{#otimes#color[9]{5}}} is selected, which has been highlighted, and");
	Paso3_Quantum1_Exp->AddText("based on that number, various possible results of #font[62]{|x#GT^{#otimes#color[9]{5}}} are recorded with a #font[62]{normalization depending on the number of possible elements}.");
	Paso3_Quantum1_Exp->AddText("These elements are evaluated in the #font[62]{QFT^{+}} to take advantage of the properties of #font[62]{interference} by eliminating values. The new values will be evaluated");
	Paso3_Quantum1_Exp->AddText("in the next step to complete the factorization.");
 	Paso3_Quantum1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1); 
        }
   
   	if(Breakopt==4){
      	//Titulo
        TPaveText *Paso3_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_cuantico->SetTextFont(62);
	Paso3_cuantico->SetFillColor(kMagenta-10); 
	Paso3_cuantico->SetShadowColor(kGray);
	Paso3_cuantico->SetMargin(0);
	Paso3_cuantico->AddText("Step #3");
	Paso3_cuantico->Draw();
	
	//Texto 1
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.01, 0.80, "#font[62]{Possible results}#font[62]{|x#GT^{#otimes#color[9]{5}}}");
        
        //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.01, 0.70, "#font[62]{|x#GT^{#otimes#color[9]{4}}} = #font[62]{#frac{1}{#sqrt{6}}[#color[38]{|1#GT^{#otimes#color[9]{5}}}} + #font[62]{#color[39]{|7#GT^{#otimes#color[9]{5}}}} + #font[62]{#color[39]{|13#GT^{#otimes#color[9]{5}}}} + #font[62]{#color[39]{|19#GT^{#otimes#color[9]{5}}}} + #font[62]{#color[6]{|25#GT^{#otimes#color[9]{5}}}} + #font[62]{#color[46]{|31#GT^{#otimes#color[9]{5}}}}]#otimes#color[2]{|4#GT^{#otimes#color[9]{5}}}");
        
	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.01, 0.60, "#font[62]{Apply the QFT^{+} to #font[62]{#color[4]{|x#GT^{#otimes#color[9]{5}}}}}");        
        
        //Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.01, 0.50, "QFT^{+}#color[4]{|x#GT^{#otimes#color[9]{5}}} = #frac{1}{#sqrt{32}}#sum_{y=0}^{31} e^{#frac{-2#pi i#color[4]{x}y}{32}}|y#GT^{#otimes#color[9]{5}}");
        
        //Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.01, 0.35, "QFT^{+}#color[1]{|x#GT^{#otimes#color[9]{5}}} = #frac{1}{#sqrt{6}}#frac{1}{#sqrt{32}}#sum_{y=0}^{31}[e^{#frac{-#color[38]{1}#pi iy}{16}} + e^{#frac{-#color[39]{7}#pi iy}{16}} + e^{#frac{-#color[39]{13}#pi iy}{16}} + e^{#frac{-#color[39]{19}#pi iy}{16}} + e^{#frac{-#color[6]{25}#pi iy}{16}} + e^{#frac{-#color[46]{31}#pi iy}{16}}]|y#GT^{#otimes#color[9]{5}}");
	
	//Texto 6
	l6->SetTextSize(0.04);
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.01, 0.20, "#font[62]{Values For the next step:} #color[39]{|0#GT^{#otimes#color[9]{5}}}, #color[39]{|14#GT^{#otimes#color[9]{5}}}, #color[6]{|5#GT^{#otimes#color[9]{5}}}, #color[6]{|6#GT^{#otimes#color[9]{5}}}, #color[39]{|10#GT^{#otimes#color[9]{5}}}, #color[6]{|11#GT^{#otimes#color[9]{5}}}, #color[39]{|12#GT^{#otimes#color[9]{5}}}, #color[39]{|16#GT^{#otimes#color[9]{5}}}, #color[39]{|20#GT^{#otimes#color[9]{5}}}, #color[39]{|21#GT^{#otimes#color[9]{5}}},");
	
	//Texto 7
	l7->SetTextSize(0.04);
	l7->SetTextFont(42); 
	l7->SetTextColor(1); 
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.01, 0.10,"#color[39]{|26#GT^{#otimes#color[9]{5}}}, #color[39]{|27#GT^{#otimes#color[9]{5}}}, #color[39]{|28#GT^{#otimes#color[9]{5}}} ");
        
        //Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	
	Paso3_Quantum1_Exp->SetTextFont(42);
	Paso3_Quantum1_Exp->SetFillColor(0); 
	Paso3_Quantum1_Exp->SetShadowColor(kGray);
	Paso3_Quantum1_Exp->SetTextAlign(12);
	Paso3_Quantum1_Exp->SetMargin(0.01);
	Paso3_Quantum1_Exp->AddText("The #font[62]{step 3} obtains the #font[62]{resulting matrix} after performing the summation of the equation. This matrix is organized to make it possible to observe");
	Paso3_Quantum1_Exp->AddText("Each record of #font[62]{|w#GT^{#otimes#color[9]{5}}} is used to identify the #font[62]{periodicity} of the function. Then, a random value from #font[62]{|w#GT^{#otimes#color[9]{5}}} is selected, which has been highlighted, and");
	Paso3_Quantum1_Exp->AddText("based on that number, various possible results of #font[62]{|x#GT^{#otimes#color[9]{5}}} are recorded with a #font[62]{normalization depending on the number of possible elements}.");
	Paso3_Quantum1_Exp->AddText("These elements are evaluated in the #font[62]{QFT^{+}} to take advantage of the properties of #font[62]{interference} by eliminating values. The new values will be evaluated");
	Paso3_Quantum1_Exp->AddText("in the next step to complete the factorization.");
 	Paso3_Quantum1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1); 
        
        }
        if(Breakopt==5){
        
        //Titulo
	TPaveText *Paso4_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso4_cuantico->SetTextFont(62);
	
	Paso4_cuantico->SetFillColor(kCyan-10); 
	Paso4_cuantico->SetShadowColor(kGray);
	Paso4_cuantico->SetMargin(0);
	Paso4_cuantico->AddText("Step #4");
	Paso4_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
	
	//Resultado 1 Num Fac. p1
	TPaveText *resultado1 = new TPaveText(0.001, 0.55, 0.5, 0.83); 
	resultado1->SetTextFont(42);
	resultado1->SetFillColor(0); 
	resultado1->SetShadowColor(kGray);
	resultado1->SetMargin(0);
	resultado1->AddText("");
	resultado1->AddText("Measured value #font[62]{#color[6]{|5#GT^{#otimes#color[9]{5}}}}");
	resultado1->AddText("");
	resultado1->AddText("Result: #frac{jN*}{r} = M  #frac{j21}{r} = #color[6]{5}  j = 10, r = 42");
	resultado1->AddText("");
	resultado1->AddText("X = 5^{#frac{42}{2}} mod 21 = 20");
	resultado1->AddText("");
	resultado1->AddText("#color[2]{P} = GCD(X+1, N)  #color[2]{P} = GCD(21, 21) = 21  #color[2]{P} = 21");
	resultado1->AddText("");
	resultado1->Draw();
	
	//Resultado 1 Num Fac. q1
	TPaveText *resultado2 = new TPaveText(0.5, 0.55, 0.999, 0.83); 
	resultado2->SetTextFont(42);
	resultado2->SetFillColor(0); 
	resultado2->SetShadowColor(kGray);
	resultado2->SetMargin(0);
	resultado2->AddText("");
	resultado2->AddText("Measured value #font[62]{#color[6]{|5#GT^{#otimes#color[9]{5}}}}");
	resultado2->AddText("");
	resultado2->AddText("Result: #frac{jN*}{r} = M  #frac{j21}{r} = #color[6]{5}  j = 10, r = 42");
	resultado2->AddText("");
	resultado2->AddText("X = 5^{#frac{42}{2}} mod 21 = 20");
	resultado2->AddText("");
	resultado2->AddText("#color[8]{Q} = GCD(X-1, N)  #color[8]{Q} = GCD(19, 21) = 1  #color[8]{Q} = 1  Partial Solution");
	resultado2->AddText("");
	resultado2->Draw();

	//Resultado 1 Num Fac. p2
	TPaveText *resultado3 = new TPaveText(0.001, 0.27, 0.5, 0.54); 
	resultado3->SetTextFont(42);
	resultado3->SetFillColor(0); 
	resultado3->SetShadowColor(kGray);
	resultado3->SetMargin(0);
	resultado3->AddText("");
	resultado3->AddText("Measured value #font[62]{#color[6]{|6#GT^{#otimes#color[9]{5}}}}");
	resultado3->AddText("");
	resultado3->AddText("Result: #frac{jN*}{r} = M  #frac{j21}{r} = #color[6]{6}  j = 4, r = 14");
	resultado3->AddText("");
	resultado3->AddText("X = 5^{#frac{14}{2}} mod 21 = 5");
	resultado3->AddText("");
	resultado3->AddText("#color[2]{P} = GCD(X+1, N)  #color[2]{P} = GCD(6, 21) = 3  #color[2]{P} = 3");
	resultado3->AddText("");
	resultado3->Draw();
	
	//Resultado 1 Num Fac. q2
	TPaveText *resultado4 = new TPaveText(0.5, 0.27, 0.999, 0.54); 
	resultado4->SetTextFont(42);
	resultado4->SetFillColor(0); 
	resultado4->SetShadowColor(kGray);
	resultado4->SetMargin(0);
	resultado4->AddText("");
	resultado4->AddText("Measured value #font[62]{#color[6]{|6#GT^{#otimes#color[9]{5}}}}");
	resultado4->AddText("");
	resultado4->AddText("Result: #frac{jN*}{r} = M  #frac{j21}{r} = #color[6]{6}  j = 4, r = 14");
	resultado4->AddText("");
	resultado4->AddText("X = 5^{#frac{14}{2}} mod 21 = 5");
	resultado4->AddText("");
	resultado4->AddText("#color[8]{Q} = GCD(X-1, N)  #color[8]{Q} = GCD(4, 21) = 1  #color[8]{Q} = 1  Partial Solution");
	resultado4->AddText("");
	resultado4->Draw();
	
	//Resultado 1 Num Fac. p3
	TPaveText *resultado5 = new TPaveText(0.001, 0.01, 0.5, 0.26);
	resultado5->SetTextFont(42);
	resultado5->SetFillColor(0); 
	resultado5->SetShadowColor(kGray);
	resultado5->SetMargin(0);
	resultado5->AddText("");
	resultado5->AddText("Measured value #font[62]{#color[6]{|11#GT^{#otimes#color[9]{5}}}}");
	resultado5->AddText("");
	resultado5->AddText("Result: #frac{jN*}{r} = M  #frac{j21}{r} = #color[6]{11}  j = 12, r = 42");
	resultado5->AddText("");
	resultado5->AddText("X = 5^{#frac{42}{2}} mod 21 = 20");
	resultado5->AddText("");
	resultado5->AddText("#color[2]{P} = GCD(X+1, N)  #color[2]{P} = GCD(21, 21) = 21  #color[2]{P} = 21");
	resultado5->AddText("");
	resultado5->Draw();
	
	//Resultado 1 Num Fac. q3
	TPaveText *resultado6 = new TPaveText(0.5, 0.01, 0.999, 0.26); 
	resultado6->SetTextFont(42);
	resultado6->SetFillColor(0); 
	resultado6->SetShadowColor(kGray);
	resultado6->SetMargin(0);
	resultado6->AddText("");
	resultado6->AddText("Measured value #font[62]{#color[6]{|11#GT^{#otimes#color[9]{4}}}}");
	resultado6->AddText("");
	resultado6->AddText("Result: #frac{jN*}{r} = M  #frac{j21}{r} = #color[6]{11}  j = 12, r = 42");
	resultado6->AddText("");
	resultado6->AddText("X = 5^{#frac{42}{2}} mod 21 = 20");
	resultado6->AddText("");
	resultado6->AddText("#color[8]{Q} = GCD(X-1, N)  #color[8]{Q} = GCD(19, 21) = 1  #color[8]{Q} = 1  Partial Solution");
	resultado6->AddText("");
	resultado6->Draw();
        
        //Segundo canvas    	
     	TCanvas *ExpPaso4 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso4->SetFillColor(0);
	ExpPaso4->SetEditable(1);
	ExpPaso4->Clear();
	ExpPaso4->Update();
	
	TPaveText *Paso4_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	
	Paso4_Quantum1_Exp->SetTextFont(42);
	
	Paso4_Quantum1_Exp->SetFillColor(0); 
	Paso4_Quantum1_Exp->SetShadowColor(0);
	Paso4_Quantum1_Exp->SetTextAlign(12);
	Paso4_Quantum1_Exp->SetMargin(0.01);
	Paso4_Quantum1_Exp->AddText("For #font[62]{step 4}, the results are evaluated under the condition #font[62]{#frac{jN}{r} = M}, which determines the value of #font[62]{r}. Given the choice of #font[62]{a}, it is observed that");
	Paso4_Quantum1_Exp->AddText("the results of the factorization are of #font[62]{trivial} and #font[62]{invalid} types. Therefore, for this selected value of #font[62]{a}, the operations are insufficient, and it becomes");
	Paso4_Quantum1_Exp->AddText("necessary to choose another value coprime with #font[62]{N} to repeat the algorithm again and obtain other possible results that factor the given number.");
 	Paso4_Quantum1_Exp->Draw();     	
     	
     	ExpPaso4->Update();
	ExpPaso4->SetEditable(1); 
        }
      } 
      break;
  }
}
if(Valueopt1 == 35){
  switch(Valueopt2){
     case 1:{
        if(Breakopt==1){
        //Titulo
	TPaveText *Paso1_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso1_cuantico->SetTextFont(62);
	Paso1_cuantico->SetFillColor(kBlue-10); 
	Paso1_cuantico->SetShadowColor(kGray);
	Paso1_cuantico->SetMargin(0);
	Paso1_cuantico->AddText("Step #1");
	Paso1_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
	
	//Texto 1
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 64  #color[9]{n = 6}");
     
	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "states: #font[62]{#color[1]{|x#GT^{#otimes#color[9]{6}}}}#font[62]{#color[1]{|w#GT^{#otimes#color[9]{6}}}}");
	
	//Flecha 1
	flecha1 = new TArrow(0.23, 0.60, 0.37, 0.60, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	//Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.40, 0.60, "#font[62]{#color[1]{|0#GT^{#otimes#color[9]{6}}}}#font[62]{#color[1]{|0#GT^{#otimes#color[9]{6}}}}");
	
	//Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.03, 0.40, "Applying the #font[62]{#color[2]{Hadamard}} gate to the kets #font[62]{#color[1]{|x#GT^{#otimes#color[9]{6}}}}");
	
	//Texto 6
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.08, 0.25, "[#color[2]{H^{#otimes 6}}#color[1]{|x#GT^{#otimes#color[9]{6}}}]#color[1]{|w#GT^{#otimes#color[9]{6}}} = #frac{1}{#sqrt{64}}[#sum_{x=0}^{63}#color[1]{|x#GT^{#otimes#color[9]{6}}}]#color[1]{|0#GT^{#otimes#color[9]{6}}}");
	
	//Cuadros explicativos
	TPaveText *Estados_example_1 = new TPaveText(0.55, 0.5, 0.99, 0.75); 
	Estados_example_1->SetTextFont(42);
	Estados_example_1->SetFillColor(kRed-10); 
	Estados_example_1->SetShadowColor(kGray);
	Estados_example_1->SetMargin(0);
	Estados_example_1->AddText("");
	Estados_example_1->AddText("The initial states of #font[62]{|x#GT and |w#GT}");
	Estados_example_1->AddText("will always be in #font[62]{|0#GT}");
	Estados_example_1->AddText("");
	Estados_example_1->Draw();
	
	TPaveText *Comp_H = new TPaveText(0.55, 0.4, 0.99, 0.1); 
	Comp_H->SetTextFont(42);
	Comp_H->SetFillColor(kMagenta-10); 
	Comp_H->SetShadowColor(kGray);
	Comp_H->SetMargin(0);
	Comp_H->AddText("");
	Comp_H->AddText("the #font[62]{Hadamard} operation creates");
	Comp_H->AddText("the states in #font[62]{superposition} that are");
	Comp_H->AddText("#font[62]{equiprobable}.");
	Comp_H->AddText("");
	Comp_H->Draw();
	
	//Segundo canvas    	
     	TCanvas *ExpPaso1 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1->SetFillColor(0);
	ExpPaso1->SetEditable(1);
	ExpPaso1->Clear();
	ExpPaso1->Update();
	
	TPaveText *Paso1_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.999, 0.99);
	Paso1_Quantum1_Exp->SetTextFont(42);
	Paso1_Quantum1_Exp->SetFillColor(0); 
	Paso1_Quantum1_Exp->SetShadowColor(kGray);
	Paso1_Quantum1_Exp->SetTextAlign(12);
	Paso1_Quantum1_Exp->SetMargin(0.01);
	Paso1_Quantum1_Exp->AddText("For #font[62]{Step 1}, the #font[62]{number of states} of the denoted system is defined as #font[62]{N*}, where the number of #font[62]{Qubits} #font[62]{n} is determined.");
	Paso1_Quantum1_Exp->AddText("The possible states are written in the form of a #font[62]{summation} due to the #font[62]{Hadamard} gate and the use of #font[62]{Dirac notation with the power}");
	Paso1_Quantum1_Exp->AddText("#font[62]{of the tensor product and the number n} indicates the number of #font[62]{Qubits} used to represent each possible state, thus the representation of a state");
	Paso1_Quantum1_Exp->AddText("random within that interval will be in the form: #font[62]{|x#GT^{#otimes n} = |x#GT#otimes|x#GT#otimes|x#GT#otimes|x#GT ...#otimes|x#GT (n times)}");
 	Paso1_Quantum1_Exp->Draw();     	
     	
     	ExpPaso1->Update();
	ExpPaso1->SetEditable(1); 
        
        }
        if(Breakopt==2){
       
        //Titulo
        TPaveText *Paso2_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso2_cuantico->SetTextFont(62);
	Paso2_cuantico->SetFillColor(kGreen-10); 
	Paso2_cuantico->SetShadowColor(kGray);
	Paso2_cuantico->SetMargin(0);
	Paso2_cuantico->AddText("Step #2");
	Paso2_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
        
        //Texto 1
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 64 #color[9]{n = 6}");
        
        //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.03, 0.65, "By applying the operator #color[2]{U_{a,N}} we obtain:");
        
        //Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.55, "#color[2]{U_{a,N}}(#frac{1}{#sqrt{64}}[#sum_{x=0}^{63}|x#GT^{#otimes#color[9]{6}}]|0#GT^{#otimes#color[9]{6}}) = #frac{1}{#sqrt{64}}[#sum_{x=0}^{63}|x#GT^{#otimes#color[9]{6}}]#color[2]{|0#oplusF_{a,N}#GT^{#otimes#color[9]{6}}}");
        
        //Cuadros explicativos
	TPaveText *Operador_Uf = new TPaveText(0.55, 0.40, 0.99, 0.65); 
	Operador_Uf->SetTextFont(42);
	Operador_Uf->SetFillColor(kMagenta-8); 
	Operador_Uf->SetShadowColor(kGray);
	Operador_Uf->SetMargin(0);
	Operador_Uf->AddText("");
	Operador_Uf->AddText("#font[62]{Modulo 2 Addition Property}");
	Operador_Uf->AddText("");
	Operador_Uf->AddText("#font[62]{|0#oplusF_{a,N}#GT^{#otimes#color[9]{6}} = |F_{a,N}#GT^{#otimes#color[9]{6}} =|a^{r}mod N#GT^{#otimes#color[9]{6}}}");
	Operador_Uf->AddText("");
	Operador_Uf->Draw();
        
        //Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.30, "The final result after substituting the values is:");
        
        //Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.2, 0.20, "#color[2]{U_{a,N}}(#frac{1}{#sqrt{64}}[#sum_{x=0}^{63}|x#GT^{#otimes#color[9]{6}}]|0#GT^{#otimes#color[9]{6}}) = #frac{1}{#sqrt{64}}[#sum_{x=0}^{63}|x#GT^{#otimes#color[9]{6}}]#color[2]{|2^{r}mod 35#GT^{#otimes#color[9]{6}}}");
        
        //Segundo canvas    	
     	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	
	TPaveText *Paso2_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.999, 0.99);
	Paso2_Quantum1_Exp->SetTextFont(42);
	Paso2_Quantum1_Exp->SetFillColor(0); 
	Paso2_Quantum1_Exp->SetShadowColor(kGray);
	Paso2_Quantum1_Exp->SetTextAlign(12);
	Paso2_Quantum1_Exp->SetMargin(0.01);
	Paso2_Quantum1_Exp->AddText("For #font[62]{step 2}, the unitary operator #font[62]{U_{a,N}} is applied to the previous result. This, in turn, performs the #font[62]{modulo 2 addition} operation");
	Paso2_Quantum1_Exp->AddText("which satisfies an important property because the ket #font[62]{|w#GT} is initialized in the state #font[62]{|0#GT}, as shown in the box.");
	Paso2_Quantum1_Exp->AddText("The final result applies the function #font[62]{F_{a,N} = a^{r}mod N}, which is #font[62]{periodic} and takes the values of #font[62]{r} as #font[62]{1, 2, 3, 4, 5, 6 ...}");
	Paso2_Quantum1_Exp->Draw();     	
     	
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(1); 
        
        }
        if(Breakopt==3){

        //Titulo
        TPaveText *Paso3_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_cuantico->SetTextFont(62);
	
	Paso3_cuantico->SetFillColor(kMagenta-10); 
	Paso3_cuantico->SetShadowColor(kGray);
	Paso3_cuantico->SetMargin(0);
	Paso3_cuantico->AddText("Step #3");
	Paso3_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
        
        //Texto 1
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.03, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 64 #color[9]{n = 6}"); 
        
        //Texto 2
	
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.03, 0.70, "Equation: #frac{1}{#sqrt{64}}[#sum_{x=0}^{63}|x#GT^{#otimes#color[9]{6}}]#color[1]{|2^{r}mod 35#GT^{#otimes#color[9]{6}}}");
	
	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "Matrix response of the equation with the states: #font[62]{#color[1]{|x#GT^{#otimes#color[9]{6}}}}#font[62]{#color[2]{|w#GT^{#otimes#color[9]{6}}}}");
	
	//Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.02, 0.40, "#frac{1}{#sqrt{64}} ");
	
        //Lineas para delimitar la matriz
	lineaV1 = new TLine(0.07, 0.11, 0.07, 0.55);
	lineaV2 = new TLine(0.98, 0.11, 0.98, 0.55);
	
	lineaH1 = new TLine(0.07, 0.55, 0.08, 0.55);
	lineaH2 = new TLine(0.07, 0.11, 0.08, 0.11);
	lineaH3 = new TLine(0.98, 0.55, 0.97, 0.55);
	lineaH4 = new TLine(0.98, 0.11, 0.97, 0.11);
	
	lineaV1->SetLineColor(kBlack);
	lineaV2->SetLineColor(kBlack);
	lineaH1->SetLineColor(kBlack);
	lineaH2->SetLineColor(kBlack);
	lineaH3->SetLineColor(kBlack);
	lineaH4->SetLineColor(kBlack);
	
	lineaV1->Draw();
	lineaV2->Draw();
	lineaH1->Draw();
	lineaH2->Draw();
	lineaH3->Draw();
	lineaH4->Draw();
        
        // Definir la matriz (3x3 en este caso)
   	const int filas = 6;
    	const int columnas = 12;
    	const char* matriz[filas][columnas] = {
        {"|0#GT^{#otimes#color[9]{6}}|2#GT^{#otimes#color[9]{6}} + ", "|1#GT^{#otimes#color[9]{6}}|4#GT^{#otimes#color[9]{6}} + ", "#color[4]{|2#GT^{#otimes#color[9]{6}}}#color[2]{|8#GT^{#otimes#color[9]{6}}} + ", "|3#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|4#GT^{#otimes#color[9]{6}}|32 #GT^{#otimes#color[9]{6}} + ", "|5#GT^{#otimes#color[9]{6}}|29#GT^{#otimes#color[9]{6}} + ", "|6#GT^{#otimes#color[9]{6}}|23#GT^{#otimes#color[9]{6}} + ", "|7#GT^{#otimes#color[9]{6}}|11#GT^{#otimes#color[9]{6}} + ", "|8#GT^{#otimes#color[9]{6}}|22#GT^{#otimes#color[9]{6}} + ", "|9#GT^{#otimes#color[9]{6}}|9#GT^{#otimes#color[9]{6}} + ", "|10#GT^{#otimes#color[9]{6}}|18#GT^{#otimes#color[9]{6}} + ", "|11#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}}"},
        {"|12#GT^{#otimes#color[9]{6}}|2#GT^{#otimes#color[9]{6}} + ", "|13#GT^{#otimes#color[9]{6}}|4#GT^{#otimes#color[9]{6}} + ", "#color[4]{|14#GT^{#otimes#color[9]{6}}}#color[2]{|8#GT^{#otimes#color[9]{6}}} + ", "|15#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|16#GT^{#otimes#color[9]{6}}|32 #GT^{#otimes#color[9]{6}} + ", "|17#GT^{#otimes#color[9]{6}}|29#GT^{#otimes#color[9]{6}} + ", "|18#GT^{#otimes#color[9]{6}}|23#GT^{#otimes#color[9]{6}} + ", "|19#GT^{#otimes#color[9]{6}}|11#GT^{#otimes#color[9]{6}} + ", "|20#GT^{#otimes#color[9]{6}}|22#GT^{#otimes#color[9]{6}} + ", "|21#GT^{#otimes#color[9]{6}}|9#GT^{#otimes#color[9]{6}} + ", "|22#GT^{#otimes#color[9]{6}}|18#GT^{#otimes#color[9]{6}} + ", "|23#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}}"},
        {"|24#GT^{#otimes#color[9]{6}}|2#GT^{#otimes#color[9]{6}} + ", "|25#GT^{#otimes#color[9]{6}}|4#GT^{#otimes#color[9]{6}} + ", "#color[4]{|26#GT^{#otimes#color[9]{6}}}#color[2]{|8#GT^{#otimes#color[9]{6}}} + ", "|27#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|28#GT^{#otimes#color[9]{6}}|32 #GT^{#otimes#color[9]{6}} + ", "|29#GT^{#otimes#color[9]{6}}|29#GT^{#otimes#color[9]{6}} + ", "|30#GT^{#otimes#color[9]{6}}|23#GT^{#otimes#color[9]{6}} + ", "|31#GT^{#otimes#color[9]{6}}|11#GT^{#otimes#color[9]{6}} + ", "|32 #GT^{#otimes#color[9]{6}}|22#GT^{#otimes#color[9]{6}} + ", "|33#GT^{#otimes#color[9]{6}}|9#GT^{#otimes#color[9]{6}} + ", "|34#GT^{#otimes#color[9]{6}}|18#GT^{#otimes#color[9]{6}} + ", "|35#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}}"},
        {"|36#GT^{#otimes#color[9]{6}}|2#GT^{#otimes#color[9]{6}} + ", "|37#GT^{#otimes#color[9]{6}}|4#GT^{#otimes#color[9]{6}} + ", "#color[4]{|38#GT^{#otimes#color[9]{6}}}#color[2]{|8#GT^{#otimes#color[9]{6}}} + ", "|39#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|40#GT^{#otimes#color[9]{6}}|32 #GT^{#otimes#color[9]{6}} + ", "|41#GT^{#otimes#color[9]{6}}|29#GT^{#otimes#color[9]{6}} + ", "|42#GT^{#otimes#color[9]{6}}|23#GT^{#otimes#color[9]{6}} + ", "|43#GT^{#otimes#color[9]{6}}|11#GT^{#otimes#color[9]{6}} + ", "|44#GT^{#otimes#color[9]{6}}|22#GT^{#otimes#color[9]{6}} + ", "|45#GT^{#otimes#color[9]{6}}|9#GT^{#otimes#color[9]{6}} + ", "|46#GT^{#otimes#color[9]{6}}|18#GT^{#otimes#color[9]{6}} + ", "|47#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}}"},
        {"|48#GT^{#otimes#color[9]{6}}|2#GT^{#otimes#color[9]{6}} + ", "|49#GT^{#otimes#color[9]{6}}|4#GT^{#otimes#color[9]{6}} + ", "#color[4]{|50#GT^{#otimes#color[9]{6}}}#color[2]{|8#GT^{#otimes#color[9]{6}}} + ", "|51#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|52#GT^{#otimes#color[9]{6}}|32 #GT^{#otimes#color[9]{6}} + ", "|53#GT^{#otimes#color[9]{6}}|29#GT^{#otimes#color[9]{6}} + ", "|54#GT^{#otimes#color[9]{6}}|23#GT^{#otimes#color[9]{6}} + ", "|55#GT^{#otimes#color[9]{6}}|11#GT^{#otimes#color[9]{6}} + ", "|56#GT^{#otimes#color[9]{6}}|22#GT^{#otimes#color[9]{6}} + ", "|57#GT^{#otimes#color[9]{6}}|9#GT^{#otimes#color[9]{6}} + ", "|58#GT^{#otimes#color[9]{6}}|18#GT^{#otimes#color[9]{6}} + ", "|59#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}}"},
        {"|60#GT^{#otimes#color[9]{6}}|2#GT^{#otimes#color[9]{6}} + ", "|61#GT^{#otimes#color[9]{6}}|4#GT^{#otimes#color[9]{6}} + ", "#color[4]{|62#GT^{#otimes#color[9]{6}}}#color[2]{|8#GT^{#otimes#color[9]{6}}} + ", "|63#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} "},
    	};
    	
    	//Posiciones para dibujar la matriz
    	double xMin = 0.045, xMax = 0.90; 
    	double yMin = 0.1, yMax = 0.55; 
    	double dx = (xMax - xMin) / columnas; 
    	double dy = (yMax - yMin) / filas;   
	
	TLatex latex;
    	latex.SetTextSize(0.022); 
    	for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
        // Posición de cada elemento en el centro de cada celda
        double xPos = xMin + (j + 0.55) * dx;
        double yPos = yMax - (i + 0.55) * dy;
        latex.DrawLatex(xPos, yPos, matriz[i][j]);
        }
       }
       
        //Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.02, 0.08, "Proposed measurement of #font[62]{|w#GT^{#otimes#color[9]{6}}} is #font[62]{#color[2]{|8#GT^{#otimes#color[9]{6}}}}");
        
        //Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso3_Quantum1_Exp->SetTextFont(42);
	Paso3_Quantum1_Exp->SetFillColor(0); 
	Paso3_Quantum1_Exp->SetShadowColor(kGray);
	Paso3_Quantum1_Exp->SetTextAlign(12);
	Paso3_Quantum1_Exp->SetMargin(0.01);
	Paso3_Quantum1_Exp->AddText("The #font[62]{step 3} obtains the #font[62]{resulting matrix} after performing the summation of the equation. This matrix is organized to make it possible to observe");
	Paso3_Quantum1_Exp->AddText("Each record of #font[62]{|w#GT^{#otimes#color[9]{6}}} is used to identify the #font[62]{periodicity} of the function. Then, a random value from #font[62]{|w#GT^{#otimes#color[9]{6}}} is selected, which has been highlighted, and");
	Paso3_Quantum1_Exp->AddText("based on that number, various possible results of #font[62]{|x#GT^{#otimes#color[9]{6}}} are recorded with a #font[62]{normalization depending on the number of possible elements}.");
	Paso3_Quantum1_Exp->AddText("These elements are evaluated in the #font[62]{QFT^{+}} to take advantage of the properties of #font[62]{interference} by eliminating values. The new values will be evaluated");
	Paso3_Quantum1_Exp->AddText("in the next step to complete the factorization.");
 	Paso3_Quantum1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1); 
        }
        
        if(Breakopt==4){
      	//Titulo
        TPaveText *Paso3_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_cuantico->SetTextFont(62);
	Paso3_cuantico->SetFillColor(kMagenta-10); 
	Paso3_cuantico->SetShadowColor(kGray);
	Paso3_cuantico->SetMargin(0);
	Paso3_cuantico->AddText("Step #3");
	Paso3_cuantico->Draw();
        
        //Texto 1
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.02, 0.80, "Proposed measurement of #font[62]{|w#GT^{#otimes#color[9]{6}}} is #font[62]{#color[2]{|8#GT^{#otimes#color[9]{6}}}}");
        
        //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.01, 0.70, "#font[62]{Apply the QFT^{+} to #font[62]{#color[4]{|x#GT^{#otimes#color[9]{6}}}}}");
        
        //Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.01, 0.60, "QFT^{+}#color[4]{|x#GT^{#otimes#color[9]{6}}} = #frac{1}{#sqrt{64}}#sum_{y=0}^{63} e^{#frac{-2#pi i#color[4]{x}y}{64}}|y#GT^{#otimes#color[9]{6}}");
        
        //Texto 4
        l4->SetTextSize(0.04);
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.01, 0.50, "#font[62]{Values For the next step:} #color[39]{|0#GT^{#otimes#color[9]{6}}}, #color[6]{|4#GT^{#otimes#color[9]{6}}}, #color[39]{|5#GT^{#otimes#color[9]{6}}}, #color[39]{|6#GT^{#otimes#color[9]{6}}}, #color[6]{|10#GT^{#otimes#color[9]{6}}},");
	
	
        //Texto 5
        l5->SetTextSize(0.04);
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.01, 0.35, "#color[39]{|11#GT^{#otimes#color[9]{6}}}, #color[39]{|12#GT^{#otimes#color[9]{6}}}, #color[39]{|16#GT^{#otimes#color[9]{6}}}, #color[6]{|20#GT^{#otimes#color[9]{6}}}, #color[39]{|21#GT^{#otimes#color[9]{6}}}, #color[39]{|22#GT^{#otimes#color[9]{6}}}, #color[39]{|26#GT^{#otimes#color[9]{6}}}, #color[39]{|27#GT^{#otimes#color[9]{6}}}#color[39]{|28#GT^{#otimes#color[9]{6}}}, #color[39]{|36#GT^{#otimes#color[9]{6}}},");
	
	//Texto 6
	l6->SetTextSize(0.04);
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.01, 0.20, "#color[39]{|37#GT^{#otimes#color[9]{6}}}, #color[39]{|38#GT^{#otimes#color[9]{6}}}, #color[39]{|42#GT^{#otimes#color[9]{6}}}, #color[39]{|43#GT^{#otimes#color[9]{6}}}, #color[39]{|44#GT^{#otimes#color[9]{6}}}, #color[39]{|48#GT^{#otimes#color[9]{6}}}, #color[39]{|52#GT^{#otimes#color[9]{6}}}, #color[39]{|53#GT^{#otimes#color[9]{6}}}, #color[39]{|54#GT^{#otimes#color[9]{6}}}, #color[39]{|58#GT^{#otimes#color[9]{6}}}, #color[39]{|59#GT^{#otimes#color[9]{6}}}, #color[39]{|60#GT^{#otimes#color[9]{6}}}");
	
        //Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso3_Quantum1_Exp->SetTextFont(42);
	Paso3_Quantum1_Exp->SetFillColor(0); 
	Paso3_Quantum1_Exp->SetShadowColor(kGray);
	Paso3_Quantum1_Exp->SetTextAlign(12);
	Paso3_Quantum1_Exp->SetMargin(0.01);
	Paso3_Quantum1_Exp->AddText("The #font[62]{step 3} obtains the #font[62]{resulting matrix} after performing the summation of the equation. This matrix is organized to make it possible to observe");
	Paso3_Quantum1_Exp->AddText("Each record of #font[62]{|w#GT^{#otimes#color[9]{6}}} is used to identify the #font[62]{periodicity} of the function. Then, a random value from #font[62]{|w#GT^{#otimes#color[9]{6}}} is selected, which has been highlighted, and");
	Paso3_Quantum1_Exp->AddText("based on that number, various possible results of #font[62]{|x#GT^{#otimes#color[9]{6}}} are recorded with a #font[62]{normalization depending on the number of possible elements}.");
	Paso3_Quantum1_Exp->AddText("These elements are evaluated in the #font[62]{QFT^{+}} to take advantage of the properties of #font[62]{interference} by eliminating values. The new values will be evaluated");
	Paso3_Quantum1_Exp->AddText("in the next step to complete the factorization.");
 	Paso3_Quantum1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1); 
        
        }
        if(Breakopt==5){
        
        //Titulo
	TPaveText *Paso4_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso4_cuantico->SetTextFont(62);
	
	Paso4_cuantico->SetFillColor(kCyan-10); 
	Paso4_cuantico->SetShadowColor(kGray);
	Paso4_cuantico->SetMargin(0);
	Paso4_cuantico->AddText("Step #4");
	Paso4_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
	
	//Resultado 1 Num Fac. p1
	TPaveText *resultado1 = new TPaveText(0.001, 0.55, 0.5, 0.83); 
	resultado1->SetTextFont(42);
	resultado1->SetFillColor(0); 
	resultado1->SetShadowColor(kGray);
	resultado1->SetMargin(0);
	resultado1->AddText("");
	resultado1->AddText("Measured value #font[62]{#color[6]{|4#GT^{#otimes#color[9]{6}}}}");
	resultado1->AddText("");
	resultado1->AddText("Result: #frac{jN*}{r} = M  #frac{j35}{r} = #color[6]{4}  j = 4, r = 35");
	resultado1->AddText("");
	resultado1->AddText("X = 2^{#frac{35}{2}} mod 35 = ?");
	resultado1->AddText("");
	resultado1->AddText("The result is not valid because the value of r is odd");
	resultado1->AddText("");
	resultado1->Draw();
	
	//Resultado 1 Num Fac. q1
	TPaveText *resultado2 = new TPaveText(0.5, 0.55, 0.999, 0.83); 
	resultado2->SetTextFont(42);
	resultado2->SetFillColor(0); 
	resultado2->SetShadowColor(kGray);
	resultado2->SetMargin(0);
	resultado2->AddText("");
	resultado2->AddText("Measured value #font[62]{#color[6]{|4#GT^{#otimes#color[9]{6}}}}");
	resultado2->AddText("");
	resultado2->AddText("Result: #frac{jN*}{r} = M  #frac{j35}{r} = #color[6]{4}  j = 4, r = 35");
	resultado2->AddText("");
	resultado2->AddText("X = 2^{#frac{35}{2}} mod 35 = ?");
	resultado2->AddText("");
	resultado2->AddText("The result is not valid because the value of r is odd");
	resultado2->AddText("");
	resultado2->Draw();

	//Resultado 1 Num Fac. p2
	TPaveText *resultado3 = new TPaveText(0.001, 0.27, 0.5, 0.54); 
	resultado3->SetTextFont(42);
	resultado3->SetFillColor(0); 
	resultado3->SetShadowColor(kGray);
	resultado3->SetMargin(0);
	resultado3->AddText("");
	resultado3->AddText("Measured value #font[62]{#color[6]{|10#GT^{#otimes#color[9]{6}}}}");
	resultado3->AddText("");
	resultado3->AddText("Result: #frac{jN*}{r} = M  #frac{j35}{r} = #color[6]{10}  j = 2, r = 7");
	resultado3->AddText("");
	resultado3->AddText("X = 2^{#frac{7}{2}} mod 35 = ?");
	resultado3->AddText("");
	resultado3->AddText("The result is not valid because the value of r is odd");
	resultado3->AddText("");
	resultado3->Draw();
	
	//Resultado 1 Num Fac. q2
	TPaveText *resultado4 = new TPaveText(0.5, 0.27, 0.999, 0.54); 
	resultado4->SetTextFont(42);
	resultado4->SetFillColor(0); 
	resultado4->SetShadowColor(kGray);
	resultado4->SetMargin(0);
	resultado4->AddText("");
	resultado4->AddText("Measured value #font[62]{#color[6]{|10#GT^{#otimes#color[9]{6}}}}");
	resultado4->AddText("");
	resultado4->AddText("Result: #frac{jN*}{r} = M  #frac{j35}{r} = #color[6]{10}  j = 2, r = 7");
	resultado4->AddText("");
	resultado4->AddText("X = 2^{#frac{7}{2}} mod 35 = ?");
	resultado4->AddText("");
	resultado4->AddText("The result is not valid because the value of r is odd");
	resultado4->AddText("");
	resultado4->Draw();
	
	//Resultado 1 Num Fac. p3
	TPaveText *resultado5 = new TPaveText(0.001, 0.01, 0.5, 0.26);
	resultado5->SetTextFont(42);
	resultado5->SetFillColor(0); 
	resultado5->SetShadowColor(kGray);
	resultado5->SetMargin(0);
	resultado5->AddText("");
	resultado5->AddText("Measured value #font[62]{#color[6]{|20#GT^{#otimes#color[9]{6}}}}");
	resultado5->AddText("");
	resultado5->AddText("Result: #frac{jN*}{r} = M  #frac{j35}{r} = #color[6]{20}  j = 32, r = 56");
	resultado5->AddText("");
	resultado5->AddText("X = 2^{#frac{56}{2}} mod 35 = 16");
	resultado5->AddText("");
	resultado5->AddText("#color[2]{P} = GCD(X+1, N)  #color[2]{P} = GCD(7, 35) = 1  #color[2]{P} = 1  Partial Solution");
	resultado5->AddText("");
	resultado5->Draw();
	
	//Resultado 1 Num Fac. q3
	TPaveText *resultado6 = new TPaveText(0.5, 0.01, 0.999, 0.26); 
	resultado6->SetTextFont(42);
	resultado6->SetFillColor(0); 
	resultado6->SetShadowColor(kGray);
	resultado6->SetMargin(0);
	resultado6->AddText("");
	resultado6->AddText("Measured value #font[62]{#color[6]{|20#GT^{#otimes#color[9]{6}}}}");
	resultado6->AddText("");
	resultado6->AddText("Result: #frac{jN*}{r} = M  #frac{j35}{r} = #color[6]{20}  j = 32, r = 56");
	resultado6->AddText("");
	resultado6->AddText("X = 2^{#frac{56}{2}} mod 35 = 16");
	resultado6->AddText("");
	resultado6->AddText("#color[8]{Q} = GCD(X-1, N)  #color[8]{Q} = GCD(15, 35) = 5  #color[8]{Q} = 5");
	resultado6->AddText("");
	resultado6->Draw();
        
        //Segundo canvas    	
     	TCanvas *ExpPaso4 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso4->SetFillColor(0);
	ExpPaso4->SetEditable(1);
	ExpPaso4->Clear();
	ExpPaso4->Update();
	
	TPaveText *Paso4_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	
	Paso4_Quantum1_Exp->SetTextFont(42);
	Paso4_Quantum1_Exp->SetFillColor(0); 
	Paso4_Quantum1_Exp->SetShadowColor(0);
	Paso4_Quantum1_Exp->SetTextAlign(12);
	Paso4_Quantum1_Exp->SetMargin(0.01);
	Paso4_Quantum1_Exp->AddText("For #font[62]{step 4}, the results are evaluated to ensure they meet the condition #font[62]{#frac{jN}{r} = M}, which determines the period value for defining the");
	Paso4_Quantum1_Exp->AddText("value #font[62]{X} and perform the greatest common divisor operation to determine the values of #font[62]{P} and #font[62]{Q}. The results are found highlighted for each possible");
	Paso4_Quantum1_Exp->AddText("value from the previous step.");
	
 	Paso4_Quantum1_Exp->Draw();     	
     	
     	ExpPaso4->Update();
	ExpPaso4->SetEditable(1);
        }
        }
     break;
     case 11:{
	if(Breakopt==1){
        
        //Titulo
	TPaveText *Paso1_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso1_cuantico->SetTextFont(62);
	
	Paso1_cuantico->SetFillColor(kBlue-10); 
	Paso1_cuantico->SetShadowColor(kGray);
	Paso1_cuantico->SetMargin(0);
	Paso1_cuantico->AddText("Step #1");
	Paso1_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
	
	//Texto 1
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 64  #color[9]{n = 6}");
	
	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "states: #font[62]{#color[1]{|x#GT^{#otimes#color[9]{6}}}}#font[62]{#color[1]{|w#GT^{#otimes#color[9]{6}}}}");
	
	//Flecha 1
	flecha1 = new TArrow(0.23, 0.60, 0.37, 0.60, 0.01, ">");
	flecha1->SetLineColor(kRed);
     	flecha1->SetLineWidth(1);
     	flecha1->SetLineStyle(1);
     	flecha1->Draw();
	
	//Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.40, 0.60, "#font[62]{#color[1]{|0#GT^{#otimes#color[9]{6}}}}#font[62]{#color[1]{|0#GT^{#otimes#color[9]{6}}}}");
	
	//Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.03, 0.40, "Applying the #font[62]{#color[2]{Hadamard}} gate to the kets #font[62]{#color[1]{|x#GT^{#otimes#color[9]{6}}}}");
	
	//Texto 6
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.08, 0.25, "[#color[2]{H^{#otimes 6}}#color[1]{|x#GT^{#otimes#color[9]{6}}}]#color[1]{|w#GT^{#otimes#color[9]{6}}} = #frac{1}{#sqrt{64}}[#sum_{x=0}^{63}#color[1]{|x#GT^{#otimes#color[9]{6}}}]#color[1]{|0#GT^{#otimes#color[9]{6}}}");
	
	//Cuadros explicativos
	TPaveText *Estados_example_1 = new TPaveText(0.55, 0.5, 0.99, 0.75); 
	Estados_example_1->SetTextFont(42);
	Estados_example_1->SetFillColor(kRed-10); 
	Estados_example_1->SetShadowColor(kGray);
	Estados_example_1->SetMargin(0);
	Estados_example_1->AddText("");
	Estados_example_1->AddText("The initial states of #font[62]{|x#GT and |w#GT}");
	Estados_example_1->AddText("will always be in #font[62]{|0#GT}");
	Estados_example_1->AddText("");
	Estados_example_1->Draw();
	
	TPaveText *Comp_H = new TPaveText(0.55, 0.4, 0.99, 0.1); 
	Comp_H->SetTextFont(42);
	Comp_H->SetFillColor(kMagenta-10); 
	Comp_H->SetShadowColor(kGray);
	Comp_H->SetMargin(0);
	Comp_H->AddText("");
	Comp_H->AddText("The #font[62]{Hadamard} operation creates");
	Comp_H->AddText("the states in #font[62]{superposition} that are");
	Comp_H->AddText("#font[62]{equiprobable}.");
	Comp_H->AddText("");
	Comp_H->Draw();
	
	//Segundo canvas    	
     	TCanvas *ExpPaso1 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso1->SetFillColor(0);
	ExpPaso1->SetEditable(1);
	ExpPaso1->Clear();
	ExpPaso1->Update();
	
	TPaveText *Paso1_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.999, 0.99);
	Paso1_Quantum1_Exp->SetTextFont(42);
	Paso1_Quantum1_Exp->SetFillColor(0); 
	Paso1_Quantum1_Exp->SetShadowColor(kGray);
	Paso1_Quantum1_Exp->SetTextAlign(12);
	Paso1_Quantum1_Exp->SetMargin(0.01);
	Paso1_Quantum1_Exp->AddText("For #font[62]{Step 1}, the #font[62]{number of states} of the denoted system is defined as #font[62]{N*}, where the number of #font[62]{Qubits} #font[62]{n} is determined.");
	Paso1_Quantum1_Exp->AddText("The possible states are written in the form of a #font[62]{summation} due to the #font[62]{Hadamard} gate and the use of #font[62]{Dirac notation with the power}");
	Paso1_Quantum1_Exp->AddText("#font[62]{of the tensor product and the number n} indicates the number of #font[62]{Qubits} used to represent each possible state, thus the representation of a state");
	Paso1_Quantum1_Exp->AddText("random within that interval will be in the form: #font[62]{|x#GT^{#otimes n} = |x#GT#otimes|x#GT#otimes|x#GT#otimes|x#GT ...#otimes|x#GT (n times)}");
 	Paso1_Quantum1_Exp->Draw();     	
     	
     	ExpPaso1->Update();
	ExpPaso1->SetEditable(1); 
        
        }
        if(Breakopt==2){
        //Titulo
        TPaveText *Paso2_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso2_cuantico->SetTextFont(62);
	Paso2_cuantico->SetFillColor(kGreen-10); 
	Paso2_cuantico->SetShadowColor(kGray);
	Paso2_cuantico->SetMargin(0);
	Paso2_cuantico->AddText("Step #2");
	Paso2_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
        
        //Texto 1
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.05, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 64 #color[9]{n = 6}");
        
        //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.03, 0.65, "By applying the operator #color[2]{U_{a,N}} we obtain:");
        
        //Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.55, "#color[2]{U_{a,N}}(#frac{1}{#sqrt{64}}[#sum_{x=0}^{63}|x#GT^{#otimes#color[9]{6}}]|0#GT^{#otimes#color[9]{6}}) = #frac{1}{#sqrt{64}}[#sum_{x=0}^{63}|x#GT^{#otimes#color[9]{6}}]#color[2]{|0#oplusF_{a,N}#GT^{#otimes#color[9]{6}}}");
        
        //Cuadros explicativos
	TPaveText *Operador_Uf = new TPaveText(0.55, 0.40, 0.99, 0.65); 
	Operador_Uf->SetTextFont(42);
	Operador_Uf->SetFillColor(kMagenta-8); 
	Operador_Uf->SetShadowColor(kGray);
	Operador_Uf->SetMargin(0);
	Operador_Uf->AddText("");
	Operador_Uf->AddText("#font[62]{Modulo 2 Addition Property}");
	Operador_Uf->AddText("");
	Operador_Uf->AddText("#font[62]{|0#oplusF_{a,N}#GT^{#otimes#color[9]{6}} = |F_{a,N}#GT^{#otimes#color[9]{6}} =|a^{r}mod N#GT^{#otimes#color[9]{6}}}");
	Operador_Uf->AddText("");
	Operador_Uf->Draw();
        
        //Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.03, 0.30, "The final result after substituting the values is:");
        
        //Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.2, 0.20, "#color[2]{U_{a,N}}(#frac{1}{#sqrt{64}}[#sum_{x=0}^{63}|x#GT^{#otimes#color[9]{6}}]|0#GT^{#otimes#color[9]{6}}) = #frac{1}{#sqrt{64}}[#sum_{x=0}^{63}|x#GT^{#otimes#color[9]{6}}]#color[2]{|11^{r}mod 35#GT^{#otimes#color[9]{6}}}");
        
        //Segundo canvas    	
     	TCanvas *ExpPaso2 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso2->SetFillColor(0);
	ExpPaso2->SetEditable(1);
	ExpPaso2->Clear();
	ExpPaso2->Update();
	
	TPaveText *Paso2_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.999, 0.99);
	Paso2_Quantum1_Exp->SetTextFont(42);
	Paso2_Quantum1_Exp->SetFillColor(0); 
	Paso2_Quantum1_Exp->SetShadowColor(kGray);
	Paso2_Quantum1_Exp->SetTextAlign(12);
	Paso2_Quantum1_Exp->SetMargin(0.01);
	Paso2_Quantum1_Exp->AddText("For #font[62]{step 2}, the unitary operator #font[62]{U_{a,N}} is applied to the previous result. This, in turn, performs the #font[62]{modulo 2 addition} operation");
	Paso2_Quantum1_Exp->AddText("which satisfies an important property because the ket #font[62]{|w#GT} is initialized in the state #font[62]{|0#GT}, as shown in the box.");
	Paso2_Quantum1_Exp->AddText("The final result applies the function #font[62]{F_{a,N} = a^{r}mod N}, which is #font[62]{periodic} and takes the values of #font[62]{r} as #font[62]{1, 2, 3, 4, 5, 6 ...}");
	Paso2_Quantum1_Exp->Draw();     	
  
     	ExpPaso2->Update();
	ExpPaso2->SetEditable(1);
             
        }
        if(Breakopt==3){
        
        //Titulo
        TPaveText *Paso3_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_cuantico->SetTextFont(62);
	Paso3_cuantico->SetFillColor(kMagenta-10); 
	Paso3_cuantico->SetShadowColor(kGray);
	Paso3_cuantico->SetMargin(0);
	Paso3_cuantico->AddText("Step #3");
	Paso3_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
        
        //Texto 1
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.03, 0.80, "#font[62]{Number of qubits states:} N* = 2^{#color[9]{n}} = 64 #color[9]{n = 6}"); 
        
        //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.03, 0.70, "Equation: #frac{1}{#sqrt{64}}[#sum_{x=0}^{63}|x#GT^{#otimes#color[9]{6}}]#color[1]{|11 ^{r}mod 35#GT^{#otimes#color[9]{6}}}");
	
	//Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.03, 0.60, "Matrix response of the equation with the states: #font[62]{#color[1]{|x#GT^{#otimes#color[9]{6}}}}#font[62]{#color[2]{|w#GT^{#otimes#color[9]{6}}}}");
	
	//Texto 4
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.02, 0.40, "#frac{1}{#sqrt{64}}");
	
        //Lineas para delimitar la matriz
	lineaV1 = new TLine(0.07, 0.11, 0.07, 0.55);
	lineaV2 = new TLine(0.98, 0.11, 0.98, 0.55);
	
	lineaH1 = new TLine(0.07, 0.55, 0.08, 0.55);
	lineaH2 = new TLine(0.07, 0.11, 0.08, 0.11);
	lineaH3 = new TLine(0.98, 0.55, 0.97, 0.55);
	lineaH4 = new TLine(0.98, 0.11, 0.97, 0.11);
	
	lineaV1->SetLineColor(kBlack);
	lineaV2->SetLineColor(kBlack);
	lineaH1->SetLineColor(kBlack);
	lineaH2->SetLineColor(kBlack);
	lineaH3->SetLineColor(kBlack);
	lineaH4->SetLineColor(kBlack);
	
	lineaV1->Draw();
	lineaV2->Draw();
	lineaH1->Draw();
	lineaH2->Draw();
	lineaH3->Draw();
	lineaH4->Draw();
        
        // Definir la matriz (3x3 en este caso)
   	const int filas = 6;
    	const int columnas = 12;
    	const char* matriz[filas][columnas] = {
        {"#color[4]{|0#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|1#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|2#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}} + ", "#color[4]{|3#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|4#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|5#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}} + ", "#color[4]{|6#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|7#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|8#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}} + ", "#color[4]{|9#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|10#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|11#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}}"},
        {"#color[4]{|12#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|13#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|14#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}} + ", "#color[4]{|15#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|16#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|17#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}} + ", "#color[4]{|18#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|19#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|20#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}} + ", "#color[4]{|21#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|22#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|23#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}}"},
        {"#color[4]{|24#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|25#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|26#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}} + ", "#color[4]{|27#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|28#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|29#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}} + ", "#color[4]{|30#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|31#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|32 #GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}} + ", "#color[4]{|33#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|34#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|35#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}}"},
        {"#color[4]{|36#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|37#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|38#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}} + ", "#color[4]{|39#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|40#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|41#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}} + ", "#color[4]{|42#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|43#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|44#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}} + ", "#color[4]{|45#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|46#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|47#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}}"},
        {"#color[4]{|48#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|49#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|50#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}} + ", "#color[4]{|51#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|52#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|53#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}} + ", "#color[4]{|54#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|55#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|56#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}} + ", "#color[4]{|57#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|58#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|59#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}}"},
        {"#color[4]{|60#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} + ", "|61#GT^{#otimes#color[9]{6}}|16#GT^{#otimes#color[9]{6}} + ", "|62#GT^{#otimes#color[9]{6}}|1#GT^{#otimes#color[9]{6}} + ", "#color[4]{|63#GT^{#otimes#color[9]{6}}}#color[2]{|11#GT^{#otimes#color[9]{6}}} "},
    	};
    	
    	//Posiciones para dibujar la matriz
    	double xMin = 0.045, xMax = 0.90; 
    	double yMin = 0.1, yMax = 0.55; 
    	double dx = (xMax - xMin) / columnas; 
    	double dy = (yMax - yMin) / filas;   
	
	TLatex latex;
    	latex.SetTextSize(0.022); 
    	for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
        // Posición de cada elemento en el centro de cada celda
        double xPos = xMin + (j + 0.55) * dx;
        double yPos = yMax - (i + 0.55) * dy;
        latex.DrawLatex(xPos, yPos, matriz[i][j]);
        }
       }
        
        //Texto 5
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.02, 0.08, "Proposed measurement of #font[62]{|w#GT^{#otimes#color[9]{6}}} is #font[62]{#color[2]{|11#GT^{#otimes#color[9]{6}}}}");
	
	//Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso3_Quantum1_Exp->SetTextFont(42);
	Paso3_Quantum1_Exp->SetFillColor(0); 
	Paso3_Quantum1_Exp->SetShadowColor(kGray);
	Paso3_Quantum1_Exp->SetTextAlign(12);
	Paso3_Quantum1_Exp->SetMargin(0.01);
	Paso3_Quantum1_Exp->AddText("The #font[62]{step 3} obtains the #font[62]{resulting matrix} after performing the summation of the equation. This matrix is organized to make it possible to observe");
	Paso3_Quantum1_Exp->AddText("Each record of #font[62]{|w#GT^{#otimes#color[9]{6}}} is used to identify the #font[62]{periodicity} of the function. Then, a random value from #font[62]{|w#GT^{#otimes#color[9]{6}}} is selected, which has been highlighted, and");
	Paso3_Quantum1_Exp->AddText("based on that number, various possible results of #font[62]{|x#GT^{#otimes#color[9]{6}}} are recorded with a #font[62]{normalization depending on the number of possible elements}.");
	Paso3_Quantum1_Exp->AddText("These elements are evaluated in the #font[62]{QFT^{+}} to take advantage of the properties of #font[62]{interference} by eliminating values. The new values will be evaluated");
	Paso3_Quantum1_Exp->AddText("in the next step to complete the factorization.");
 	Paso3_Quantum1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1); 
        }
        
        if(Breakopt==4){
      	//Titulo
        TPaveText *Paso3_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso3_cuantico->SetTextFont(62);
	Paso3_cuantico->SetFillColor(kMagenta-10); 
	Paso3_cuantico->SetShadowColor(kGray);
	Paso3_cuantico->SetMargin(0);
	Paso3_cuantico->AddText("Step #3");
	Paso3_cuantico->Draw();
        
        //Texto 1
	l1->SetTextColor(1); 
	l1->SetTextAlign(12); 
	l1->DrawLatex(0.02, 0.80, "Proposed measurement of #font[62]{|w#GT^{#otimes#color[9]{6}}} is #font[62]{#color[2]{|11#GT^{#otimes#color[9]{6}}}}");
        
        //Texto 2
	l2->SetTextFont(42); 
	l2->SetTextColor(1); 
	l2->SetTextAlign(12); 
	l2->DrawLatex(0.01, 0.70, "#font[62]{Apply the QFT^{+} to #font[62]{#color[4]{|x#GT^{#otimes#color[9]{6}}}}}");
        
        //Texto 3
	l3->SetTextFont(42); 
	l3->SetTextColor(1); 
	l3->SetTextAlign(12); 
	l3->DrawLatex(0.01, 0.58, "QFT^{+}#color[4]{|x#GT^{#otimes#color[9]{6}}} = #frac{1}{#sqrt{64}}#sum_{y=0}^{63} e^{#frac{-2#pi i#color[4]{x}y}{64}}|y#GT^{#otimes#color[9]{6}}");
        
        //Texto 4
        l4->SetTextSize(0.04);
	l4->SetTextFont(42); 
	l4->SetTextColor(1); 
	l4->SetTextAlign(12); 
	l4->DrawLatex(0.01, 0.45, "QFT^{+}#color[4]{|x#GT^{#otimes#color[9]{6}}} = #frac{1}{#sqrt{22}}#frac{1}{#sqrt{64}}#sum_{y=0}^{63}[e^{#frac{-2#pi i#color[4]{0}y}{64}}+e^{#frac{-2#pi i#color[4]{3}y}{64}}+e^{#frac{-2#pi i#color[4]{6}y}{64}}+e^{#frac{-2#pi i#color[4]{9}y}{64}}+e^{#frac{-2#pi i#color[4]{12}y}{64}}+e^{#frac{-2#pi i#color[4]{15}y}{64}}+e^{#frac{-2#pi i#color[4]{18}y}{64}}+e^{#frac{-2#pi i#color[4]{21}y}{64}}+e^{#frac{-2#pi i#color[4]{24}y}{64}}+e^{#frac{-2#pi i#color[4]{27}y}{64}}+");
        
        //Texto 5
        l5->SetTextSize(0.04);
	l5->SetTextFont(42); 
	l5->SetTextColor(1); 
	l5->SetTextAlign(12); 
	l5->DrawLatex(0.01, 0.28, "e^{#frac{-2#pi i#color[4]{30}y}{64}}+e^{#frac{-2#pi i#color[4]{33}y}{64}}+e^{#frac{-2#pi i#color[4]{36}y}{64}}+e^{#frac{-2#pi i#color[4]{39}y}{64}}+e^{#frac{-2#pi i#color[4]{42}y}{64}}+e^{#frac{-2#pi i#color[4]{45}y}{64}}+e^{#frac{-2#pi i#color[4]{48}y}{64}}+e^{#frac{-2#pi i#color[4]{51}y}{64}}+e^{#frac{-2#pi i#color[4]{54}y}{64}}+e^{#frac{-2#pi i#color[4]{57}y}{64}}+e^{#frac{-2#pi i#color[4]{60}y}{64}}+e^{#frac{-2#pi i#color[4]{63}y}{64}}]|y#GT^{#otimes#color[9]{6}}");
        
        //Texto 6
        l6->SetTextSize(0.04);
	l6->SetTextFont(42); 
	l6->SetTextColor(1); 
	l6->SetTextAlign(12); 
	l6->DrawLatex(0.01, 0.15, "#font[62]{Values For the next step:} #color[39]{|0#GT^{#otimes#color[9]{6}}}, #color[6]{|5#GT^{#otimes#color[9]{6}}}, #color[6]{|6#GT^{#otimes#color[9]{6}}}, #color[6]{|7#GT^{#otimes#color[9]{6}}}, #color[39]{|8#GT^{#otimes#color[9]{6}}}, #color[39]{|9#GT^{#otimes#color[9]{6}}}, #color[39]{|12#GT^{#otimes#color[9]{6}}}, #color[39]{|13#GT^{#otimes#color[9]{6}}}, #color[39]{|14#GT^{#otimes#color[9]{6}}}, #color[39]{|15#GT^{#otimes#color[9]{6}}},");
  
  	//Texto 7
  	l7->SetTextSize(0.04);
	l7->SetTextFont(42); 
	l7->SetTextColor(1); 
	l7->SetTextAlign(12); 
	l7->DrawLatex(0.01, 0.05, "#color[39]{|24#GT^{#otimes#color[9]{6}}}, #color[39]{|32#GT^{#otimes#color[9]{6}}},#color[39]{|40#GT^{#otimes#color[9]{6}}}, #color[39]{|56#GT^{#otimes#color[9]{6}}}, #color[39]{|57#GT^{#otimes#color[9]{6}}}, #color[39]{|58#GT^{#otimes#color[9]{6}}}, #color[39]{|59#GT^{#otimes#color[9]{6}}}");
       
       
        //Segundo canvas    	
     	TCanvas *ExpPaso3 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso3->SetFillColor(0);
	ExpPaso3->SetEditable(1);
	ExpPaso3->Clear();
	ExpPaso3->Update();
	
	TPaveText *Paso3_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso3_Quantum1_Exp->SetTextFont(42);
	Paso3_Quantum1_Exp->SetFillColor(0); 
	Paso3_Quantum1_Exp->SetShadowColor(kGray);
	Paso3_Quantum1_Exp->SetTextAlign(12);
	Paso3_Quantum1_Exp->SetMargin(0.01);
	Paso3_Quantum1_Exp->AddText("The #font[62]{step 3} obtains the #font[62]{resulting matrix} after performing the summation of the equation. This matrix is organized to make it possible to observe");
	Paso3_Quantum1_Exp->AddText("Each record of #font[62]{|w#GT^{#otimes#color[9]{6}}} is used to identify the #font[62]{periodicity} of the function. Then, a random value from #font[62]{|w#GT^{#otimes#color[9]{6}}} is selected, which has been highlighted, and");
	Paso3_Quantum1_Exp->AddText("based on that number, various possible results of #font[62]{|x#GT^{#otimes#color[9]{6}}} are recorded with a #font[62]{normalization depending on the number of possible elements}.");
	Paso3_Quantum1_Exp->AddText("These elements are evaluated in the #font[62]{QFT^{+}} to take advantage of the properties of #font[62]{interference} by eliminating values. The new values will be evaluated");
	Paso3_Quantum1_Exp->AddText("in the next step to complete the factorization.");
	
 	Paso3_Quantum1_Exp->Draw();     	
     	
     	ExpPaso3->Update();
	ExpPaso3->SetEditable(1); 
        
        }
        if(Breakopt==5){
       
        //Titulo
	TPaveText *Paso4_cuantico = new TPaveText(0.01, 0.85, 0.99, 0.99); 
	Paso4_cuantico->SetTextFont(62);
	
	Paso4_cuantico->SetFillColor(kCyan-10); 
	Paso4_cuantico->SetShadowColor(kGray);
	Paso4_cuantico->SetMargin(0);
	Paso4_cuantico->AddText("Step #4");
	Paso4_cuantico->Draw();
	
	//Lineas de texto
	l1 = new TLatex();
     	l2 = new TLatex();
     	l3 = new TLatex();
     	l4 = new TLatex();
     	l5 = new TLatex();
     	l6 = new TLatex();
     	l7 = new TLatex();
     	l8 = new TLatex();
     	l9 = new TLatex();
     	l10 = new TLatex();
     	l11 = new TLatex();
     	l12 = new TLatex();
     	l13 = new TLatex();
     	l14 = new TLatex();
     	l15 = new TLatex();
	
	//Resultado 1 Num Fac. p1
	TPaveText *resultado1 = new TPaveText(0.001, 0.55, 0.5, 0.83); 
	resultado1->SetTextFont(42);
	resultado1->SetFillColor(0); 
	resultado1->SetShadowColor(kGray);
	resultado1->SetMargin(0);
	resultado1->AddText("");
	resultado1->AddText("Measured value #font[62]{#color[6]{|5#GT^{#otimes#color[9]{6}}}}");
	resultado1->AddText("");
	resultado1->AddText("Result: #frac{jN*}{r} = M  #frac{j35}{r} = #color[6]{5}  j = 1, r = 14");
	resultado1->AddText("");
	resultado1->AddText("X = 11^{#frac{14}{2}} mod 35 = 11");
	resultado1->AddText("");
	resultado1->AddText("#color[2]{P} = GCD(X+1, N)  #color[2]{P} = GCD(12, 35) = 1  #color[2]{P} = 1  Partial Solution");
	resultado1->AddText("");
	resultado1->Draw();
	
	//Resultado 1 Num Fac. q1
	TPaveText *resultado2 = new TPaveText(0.5, 0.55, 0.999, 0.83); 
	resultado2->SetTextFont(42);
	resultado2->SetFillColor(0); 
	resultado2->SetShadowColor(kGray);
	resultado2->SetMargin(0);
	resultado2->AddText("");
	resultado2->AddText("Measured value #font[62]{#color[6]{|5#GT^{#otimes#color[9]{6}}}}");
	resultado2->AddText("");
	resultado2->AddText("Result: #frac{jN*}{r} = M  #frac{j35}{r} = #color[6]{5}  j = 1, r = 14");
	resultado2->AddText("");
	resultado2->AddText("X = 11^{#frac{14}{2}} mod 35 = 11");
	resultado2->AddText("");
	resultado2->AddText("#color[8]{Q} = GCD(X-1, N)  #color[8]{Q} = GCD(10, 35) = 5  #color[8]{Q} = 5");
	resultado2->AddText("");
	resultado2->Draw();

	//Resultado 1 Num Fac. p2
	TPaveText *resultado3 = new TPaveText(0.001, 0.27, 0.5, 0.54); 
	resultado3->SetTextFont(42);
	resultado3->SetFillColor(0); 
	resultado3->SetShadowColor(kGray);
	resultado3->SetMargin(0);
	resultado3->AddText("");
	resultado3->AddText("Measured value #font[62]{#color[6]{|6#GT^{#otimes#color[9]{6}}}}");
	resultado3->AddText("");
	resultado3->AddText("Result: #frac{jN*}{r} = M  #frac{j35}{r} = #color[6]{6}  j = 12, r = 70");
	resultado3->AddText("");
	resultado3->AddText("X = 11^{#frac{70}{2}} mod 35 = 16");
	resultado3->AddText("");
	resultado3->AddText("#color[2]{P} = GCD(X+1, N)  #color[2]{P} = GCD(17, 35) = 1  #color[2]{P} = 1  Partial Solution");
	resultado3->AddText("");
	resultado3->Draw();
	
	//Resultado 1 Num Fac. q2
	TPaveText *resultado4 = new TPaveText(0.5, 0.27, 0.999, 0.54); 
	resultado4->SetTextFont(42);
	resultado4->SetFillColor(0); 
	resultado4->SetShadowColor(kGray);
	resultado4->SetMargin(0);
	resultado4->AddText("");
	resultado4->AddText("Measured value #font[62]{#color[6]{|6#GT^{#otimes#color[9]{6}}}}");
	resultado4->AddText("");
	resultado4->AddText("Result: #frac{jN*}{r} = M  #frac{j35}{r} = #color[6]{6}  j = 12, r = 70");
	resultado4->AddText("");
	resultado4->AddText("X = 11^{#frac{70}{2}} mod 35 = 16");
	resultado4->AddText("");
	resultado4->AddText("#color[8]{Q} = GCD(X-1, N)  #color[8]{Q} = GCD(15, 35) = 5  #color[8]{Q} = 5");
	resultado4->AddText("");
	resultado4->Draw();
	
	//Resultado 1 Num Fac. p3
	TPaveText *resultado5 = new TPaveText(0.001, 0.01, 0.5, 0.26);
	resultado5->SetTextFont(42);
	resultado5->SetFillColor(0); 
	resultado5->SetShadowColor(kGray);
	resultado5->SetMargin(0);
	resultado5->AddText("");
	resultado5->AddText("Measured value #font[62]{#color[6]{|7#GT^{#otimes#color[9]{6}}}}");
	resultado5->AddText("");
	resultado5->AddText("Result: #frac{jN*}{r} = M  #frac{j35}{r} = #color[6]{7}  j = 1, r = 35");
	resultado5->AddText("");
	resultado5->AddText("X = 11^{#frac{35}{2}} mod 35 = ?");
	resultado5->AddText("");
	resultado5->AddText("The result is not valid because the value of r is odd");
	resultado5->AddText("");
	resultado5->Draw();
	
	//Resultado 1 Num Fac. q3
	TPaveText *resultado6 = new TPaveText(0.5, 0.01, 0.999, 0.26); 
	resultado6->SetTextFont(42);
	resultado6->SetFillColor(0); 
	resultado6->SetShadowColor(kGray);
	resultado6->SetMargin(0);
	resultado6->AddText("");
	resultado6->AddText("Measured value #font[62]{#color[6]{|7#GT^{#otimes#color[9]{6}}}}");
	resultado6->AddText("");
	resultado6->AddText("Result: #frac{jN*}{r} = M  #frac{j35}{r} = #color[6]{7}  j = 1, r = 35");
	resultado6->AddText("");
	resultado6->AddText("X = 11^{#frac{35}{2}} mod 35 = ?");
	resultado6->AddText("");
	resultado6->AddText("The result is not valid because the value of r is odd");
	resultado6->AddText("");
	resultado6->Draw();

        //Segundo canvas    	
     	TCanvas *ExpPaso4 = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpPaso4->SetFillColor(0);
	ExpPaso4->SetEditable(1);
	ExpPaso4->Clear();
	ExpPaso4->Update();
	
	TPaveText *Paso4_Quantum1_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99);
	Paso4_Quantum1_Exp->SetTextFont(42);
	Paso4_Quantum1_Exp->SetFillColor(0); 
	Paso4_Quantum1_Exp->SetShadowColor(0);
	Paso4_Quantum1_Exp->SetTextAlign(12);
	Paso4_Quantum1_Exp->SetMargin(0.01);
	Paso4_Quantum1_Exp->AddText("For #font[62]{step 4}, the results are evaluated to ensure they meet the condition #font[62]{#frac{jN}{r} = M}, which determines the period value for defining the");
	Paso4_Quantum1_Exp->AddText("value #font[62]{X} and perform the greatest common divisor operation to determine the values of #font[62]{P} and #font[62]{Q}. The results are found highlighted for each possible");
	Paso4_Quantum1_Exp->AddText("value from the previous step.");
 	Paso4_Quantum1_Exp->Draw();     	
     	
     	ExpPaso4->Update();
	ExpPaso4->SetEditable(1); 
        
        }
	}
     break;
  }
}
canvas3->Update();
}
/*************************************************************/
void MyMainFrame::CambioTab(Int_t id){
id = fTabAll->GetCurrent();
Int_t id1 = fTabAll->GetCurrent();

if(CTab){
 	TCanvas *ExplConceptos = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
 	ExplConceptos->SetFixedAspectRatio();
 	ExplConceptos->cd();
 	ExplConceptos->Clear(); 
	
 	ExplConceptos->SetEditable(1);
	switch(id){
 	case 0:{
 	DoConceptsClassical();
 	TCanvas *ConceptosClasicos = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
 	ConceptosClasicos->SetFixedAspectRatio();
	ConceptosClasicos->SetFillColor(0);
	ConceptosClasicos->SetEditable(1);
	ConceptosClasicos->Clear();
	ConceptosClasicos->Update();
 	
 	TPaveText *ConcpetosClass = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC"); 
 	ConcpetosClass->SetTextFont(42);
	ConcpetosClass->SetShadowColor(kGray);
	ConcpetosClass->SetTextAlign(12);
	ConcpetosClass->SetMargin(0.01);
	ConcpetosClass->AddText("the #font[62]{concepts of the classical method} are explained in each box in such a way that they are related to the #font[62]{Shor's algorithm}, each mathematical");
	ConcpetosClass->AddText("process is described to facilitate the Interface-User interaction.");
	ConcpetosClass->AddText("Advance through the #font[62]{CIRCUIT} and #font[62]{QUANTUM} tabs to observe the concepts used in these areas.");
	ConcpetosClass->AddText("Press #font[62]{CLEAR} to return to the home screen or select a value to factor #font[62]{NUM. FACTOR} and then the value of #font[62]{Value a}.");
 	ConcpetosClass->Draw();
 	
 	ConceptosClasicos->Update();
	ConceptosClasicos->SetEditable(1);
 	}
 	break;
 	case 1:{
 	DoConceptsCircuit();
 	TCanvas *ConceptosCircuito = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
 	ConceptosCircuito->SetFixedAspectRatio();
	ConceptosCircuito->SetFillColor(0);
	ConceptosCircuito->SetEditable(1);
	ConceptosCircuito->Clear();
	ConceptosCircuito->Update();
 	
 	TPaveText *ConcpetosCircuit = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
 	ConcpetosCircuit->SetTextFont(42); 
	ConcpetosCircuit->SetShadowColor(kGray);
	ConcpetosCircuit->SetTextAlign(12);
	ConcpetosCircuit->SetMargin(0.01);
	ConcpetosCircuit->AddText("The concepts of the circuit are explained in the boxes. Each four contains information about the structure and functionality of the #font[62]{gates} implemented in");
	ConcpetosCircuit->AddText("the #font[62]{Shor's algorithm} to facilitate understanding.");
	ConcpetosCircuit->AddText("Advance through the #font[62]{CLASSICAL} and #font[62]{QUANTUM} tabs to observe the concepts used in these areas.");
	ConcpetosCircuit->AddText("Press #font[62]{CLEAR} to return to the home screen or select a value to factor #font[62]{NUM. FACTOR} and then the value of #font[62]{Value a}.");
 	ConcpetosCircuit->Draw();
 	
 	ConceptosCircuito->Update();
	ConceptosCircuito->SetEditable(1);
 	}
 	break;
 	case 2:{
 	DoConceptsQuantum();
 	TCanvas *ConceptosCuanticos = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
 	ConceptosCuanticos->SetFixedAspectRatio();
	ConceptosCuanticos->SetFillColor(0);
	ConceptosCuanticos->SetEditable(1);
	ConceptosCuanticos->Clear();
	ConceptosCuanticos->Update();
 	
 	TPaveText *ConcpetosCuanticos = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
 	ConcpetosCuanticos->SetTextFont(42); 
	ConcpetosCuanticos->SetShadowColor(kGray);
	ConcpetosCuanticos->SetTextAlign(12);
	ConcpetosCuanticos->SetMargin(0.01);
	ConcpetosCuanticos->AddText("The #font[62]{concepts of the quantum method} are explained in each box in such a way that they are related to the #font[62]{Shor's algorithm}, each mathematical process is described to facilitate the Interface-User interaction.");
	ConcpetosCuanticos->AddText("It is recommended that the user have basic knowledge of #font[62]{quantum mechanics} and #font[62]{quantum computing} to enhance the learning process with the interface.");
	ConcpetosCuanticos->AddText("Advance through the #font[62]{CLASSICAL} and #font[62]{CIRCUIT} tabs to observe the concepts used in these areas.");
	ConcpetosCuanticos->AddText("Press #font[62]{CLEAR} to return to the home screen or select a value to factor #font[62]{NUM. FACTOR} and then the value of #font[62]{Value a}.");
 	ConcpetosCuanticos->Draw();
 	
 	ConceptosCuanticos->Update();
	ConceptosCuanticos->SetEditable(1);
 	}
 	break;
 }
	ExplConceptos->Update();
	ExplConceptos->SetEditable(0);
}
else{	
	
 	TCanvas *Cambio= fRootEmbeddedCanvasEXPLINATION->GetCanvas();
 	Cambio->SetFixedAspectRatio();
 	Cambio->cd();
 	Cambio->Clear(); 
 	Cambio->SetEditable(1);
 	
switch(id1){
	case 0:{
	//Segundo Canvas
	TCanvas *ExpClasica = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpClasica->SetFixedAspectRatio();
	ExpClasica->SetFillColor(0);
	ExpClasica->SetEditable(1);
	ExpClasica->Clear();
	ExpClasica->Update();
	
	TPaveText *Pasos_Clasicos_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Pasos_Clasicos_Exp->SetTextFont(42);  
	Pasos_Clasicos_Exp->SetShadowColor(kGray);
	Pasos_Clasicos_Exp->SetTextAlign(12);
	Pasos_Clasicos_Exp->SetMargin(0.01);
	Pasos_Clasicos_Exp->AddText("This space contains the main steps to solve #font[62]{Shor's algorithm in classical form.}");
	Pasos_Clasicos_Exp->AddText("Each step contains explanations that will be detailed by pressing the #font[62]{NEXT} button and previous steps by pressing the #font[62]{BACK} ");
	Pasos_Clasicos_Exp->AddText("button. ");
	Pasos_Clasicos_Exp->AddText("If you need to clear the screen, press the #font[62]{CLEAR} button. To start again, select a value to factor and the coprime value");
	Pasos_Clasicos_Exp->AddText("in the upper left options of the screen.");
 	Pasos_Clasicos_Exp->Draw();
	
	ExpClasica->Update();
	ExpClasica->SetEditable(1);
	
	if(Breakopt==0){
	DoClassical();
	}
	if(Breakopt==1){
        CondClassical();
        fTextButtonBACK->SetState(kButtonUp, kTRUE);
        }
	if(Breakopt==2){
        CondClassical();
        fTextButtonBACK->SetState(kButtonUp, kTRUE);
        }
        if(Breakopt==3){
        CondClassical();
        fTextButtonBACK->SetState(kButtonUp, kTRUE);
        }
        if(Breakopt==4){
        CondClassical();
        fTextButtonBACK->SetState(kButtonUp, kTRUE);
        fTextButtonNEXT->SetState(kButtonUp, kTRUE);
        }
        if(Breakopt==5){
        DoClassical();
        fTextButtonBACK->SetState(kButtonUp, kTRUE);
        fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
        }
	break;
	}
	case 1:{
	TCanvas *ExpCircuito = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpCircuito->SetFixedAspectRatio();
	ExpCircuito->SetFillColor(0);
	ExpCircuito->SetEditable(1);
	ExpCircuito->Clear();
	ExpCircuito->Update();
	
	TPaveText *Pasos_Circuito_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Pasos_Circuito_Exp->SetTextFont(42);  
	Pasos_Circuito_Exp->SetShadowColor(kGray);
	Pasos_Circuito_Exp->SetTextAlign(12);
	Pasos_Circuito_Exp->SetMargin(0.01);
	Pasos_Circuito_Exp->AddText("This space contains the main steps to solve #font[62]{Shor's algorithm circuit.}");
	Pasos_Circuito_Exp->AddText("Each step contains explanations that will be detailed by pressing the #font[62]{NEXT} button and previous steps by pressing the #font[62]{BACK}");
	Pasos_Circuito_Exp->AddText("button. In case of doubt, press the #font[62]{CLEAR} button and then #font[62]{CONCEPTS} for a more detailed explanation about the #font[62]{gates}.");
	Pasos_Circuito_Exp->AddText("To start again, select a value to factor and the coprime value in the upper left options of the screen. To view the mathematical steps,");
	Pasos_Circuito_Exp->AddText("go to the #font[62]{CLASSICAL and QUANTUM tabs}."); 
 	Pasos_Circuito_Exp->Draw();
	
	ExpCircuito->Update();
	ExpCircuito->SetEditable(1);
	
	if(Breakopt==0){
	DoCircuit();
	}
	if(Breakopt==1){
        CondCircuit();
        fTextButtonBACK->SetState(kButtonUp, kTRUE);
        }
	if(Breakopt==2){
        CondCircuit();
        fTextButtonBACK->SetState(kButtonUp, kTRUE);
        }
        if(Breakopt==3){
        CondCircuit();
        fTextButtonBACK->SetState(kButtonUp, kTRUE);
        }
        if(Breakopt==4){
        CondCircuit();
        fTextButtonBACK->SetState(kButtonUp, kTRUE);
        }
        if(Breakopt==5){
        DoCircuit();
        fTextButtonBACK->SetState(kButtonUp, kTRUE);
        fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
        }
	break;
	}
	case 2:{
	TCanvas *ExpCuantica = fRootEmbeddedCanvasEXPLINATION->GetCanvas();
	ExpCuantica->SetFixedAspectRatio();
	ExpCuantica->SetFillColor(0);
	ExpCuantica->SetEditable(1);
	ExpCuantica->Clear();
	ExpCuantica->Update();
	
	TPaveText *Pasos_Cuanticos_Exp = new TPaveText(0.01, 0.01, 0.99, 0.99, "NDC");
	Pasos_Cuanticos_Exp->SetTextFont(42);   
	Pasos_Cuanticos_Exp->SetShadowColor(kGray);
	Pasos_Cuanticos_Exp->SetTextAlign(12);
	Pasos_Cuanticos_Exp->SetMargin(0.01);
	Pasos_Cuanticos_Exp->AddText("This space contains the main steps to solve #font[62]{Shor's algorithm in quantum form.}");
	Pasos_Cuanticos_Exp->AddText("Each step contains explanations that will be detailed by pressing the #font[62]{NEXT} button and previous steps by pressing the #font[62]{BACK}");
	Pasos_Cuanticos_Exp->AddText("button.");
	Pasos_Cuanticos_Exp->AddText("If you need to clear the screen, press the #font[62]{CLEAR} button. To start again, select a value to factor and the coprime value");
	Pasos_Cuanticos_Exp->AddText("in the upper left options of the screen.");
 	Pasos_Cuanticos_Exp->Draw();
	
	if(Breakopt==0){
	DoQuantum();
	}
	if(Breakopt==1){
        CondQuantum();
        fTextButtonBACK->SetState(kButtonUp, kTRUE);
        }
	if(Breakopt==2){
        CondQuantum();
        fTextButtonBACK->SetState(kButtonUp, kTRUE);
        }
        if(Breakopt==3){
        CondQuantum();
        fTextButtonBACK->SetState(kButtonUp, kTRUE);
        }
        if(Breakopt==4){
        CondQuantum();
        fTextButtonBACK->SetState(kButtonUp, kTRUE);
        fTextButtonNEXT->SetState(kButtonUp, kTRUE);
        }
         if(Breakopt==5){
        CondQuantum();
        fTextButtonBACK->SetState(kButtonUp, kTRUE);
        fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
        }
	
	ExpCuantica->Update();
	ExpCuantica->SetEditable(1);
	}
	break;
	}
Cambio->Update();
Cambio->SetEditable(0);
}
}
/*************************************************************/
void MyMainFrame::DoClear(){
	CTab = false;
	fTabAll->SetTab(0);
	Breakopt=0;
	fComboBoxVALUESA->SetEnabled(false);
	fComboBoxNUMSFACTORS->SetEnabled(true);
	DoWelcome(); 
}
/*************************************************************/
void MyMainFrame::DoNext(){
Breakopt++;
Int_t id = fTabAll->GetCurrent();

	switch(id){
	case 0:{
	if(Breakopt < 5){
	CondClassical();
	fTextButtonBACK->SetState(kButtonUp, kTRUE); 
	}
	else if(Breakopt == 5){
	CondClassical();
	fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
	}
	break;
	}
	case 1:{
	if(Breakopt < 5){
	CondCircuit();
	fTextButtonBACK->SetState(kButtonUp, kTRUE); 
	}
	else if(Breakopt == 5){
	CondCircuit();
	fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
	}
	break;
	}
	case 2:{
	if(Breakopt < 5){
	CondQuantum();
	fTextButtonBACK->SetState(kButtonUp, kTRUE); 
	} 
	else if(Breakopt == 5){
	CondQuantum();
	fTextButtonNEXT->SetState(kButtonDisabled, kTRUE);
	}
	break;
	}
	}
}
/**************************************************************/
void MyMainFrame::DoBack(){
Breakopt--;
Int_t id = fTabAll->GetCurrent();

	switch(id){
	case 0:{
	if(Breakopt == 0){
	fTextButtonBACK->SetState(kButtonDisabled, kTRUE);
        fTextButtonNEXT->SetState(kButtonUp, kTRUE); 
        CambioTab(0);
        DoClassical(); 
	}
	else if(Breakopt < 5){
	CondClassical();
	fTextButtonNEXT->SetState(kButtonUp, kTRUE);
	}
	break;
	}
	case 1:{
	if(Breakopt == 0){
	fTextButtonBACK->SetState(kButtonDisabled, kTRUE);
        fTextButtonNEXT->SetState(kButtonUp, kTRUE); 
        CambioTab(1);
        DoCircuit();
	}
	else if(Breakopt < 5){
	CondCircuit();
	fTextButtonNEXT->SetState(kButtonUp, kTRUE);
	}
	break;
	}
	case 2:{
	if(Breakopt == 0){
	fTextButtonBACK->SetState(kButtonUp, kTRUE);
        fTextButtonNEXT->SetState(kButtonUp, kTRUE); 
        CambioTab(2);
        DoQuantum();
	}
	else if(Breakopt < 5){
	CondQuantum();
	fTextButtonNEXT->SetState(kButtonUp, kTRUE);
	}
	break;
	}
	}
}   
/**********Destructor******/
MyMainFrame::~MyMainFrame(){
   fMain->Cleanup();
   delete fMain;
 }  
/**************************************************************/
void SoftEduQSA(){
  new MyMainFrame(gClient->GetRoot(),1100,700);
}

int main(int argc, char **argv) {
   TApplication theApp("App",&argc,argv);
   SoftEduQSA();
   theApp.Run();
   return 0;
}


