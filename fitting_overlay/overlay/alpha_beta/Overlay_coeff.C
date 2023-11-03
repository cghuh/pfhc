void draw(TString region) {
    gROOT->SetStyle("Modern"); //classic, modern, Default
    gStyle->SetOptStat(kFALSE);
    //gStyle->SetOptFit(1111);
    gStyle->SetOptTitle(0);
    
    TFile *_f1 = new TFile("../../../../coeffAlpha_EH_"+region+".root");
    TFile *_f2 = new TFile("../../../../coeffBeta_EH_"+region+".root");
    TFile *_f3 = new TFile("../../../../coeffAlpha_H_"+region+".root");
    TFile *_f4 = new TFile("../../../../coeffBeta_H_"+region+".root");
    
    TGraphErrors *coeffAEH = (TGraphErrors*)_f1->Get("Graph");
    TGraphErrors *coeffBEH = (TGraphErrors*)_f2->Get("Graph");
    TGraphErrors *coeffAH = (TGraphErrors*)_f3->Get("Graph");
    TGraphErrors *coeffBH = (TGraphErrors*)_f4->Get("Graph");
    
    TCanvas *c1 = new TCanvas("c1","c1",1200,900);
    c1->SetGridx(1);
    c1->SetGridy(1);
    c1->SetLogx(1);
    
    coeffAEH->SetMarkerColor(2);
    coeffBEH->SetMarkerColor(4);
    coeffAH->SetMarkerColor(3);
    coeffBH->SetMarkerColor(6);
    
    coeffAEH->SetLineColor(2);
    coeffBEH->SetLineColor(4);
    coeffAH->SetLineColor(3);
    coeffBH->SetLineColor(6);
    
    coeffAEH->SetMarkerStyle(22);
    coeffBEH->SetMarkerStyle(23);
    coeffBH->SetMarkerStyle(23);
    coeffBH->SetMarkerStyle(23);
    
    coeffAEH->SetMinimum(-2.0);
    coeffAEH->SetMaximum(1.0);
    coeffAEH->GetXaxis()->SetRangeUser(4,1000);
    coeffAEH->SetPoint(coeffAEH->GetN(), 900,100);
    
    coeffAEH->Draw("AP");
    coeffBEH->Draw("P");
    coeffAH->Draw("P");
    coeffBH->Draw("P");
    
  /*  
    TF1 *functionBarrelAlphaEcalHcal = new TF1("functionBarrelAlphaEcalHcal","[0]+[1]*exp(-x/[2])", 1, 220);
   
    functionBarrelAlphaEcalHcal->SetLineColor(2);
    functionBarrelAlphaEcalHcal->SetLineWidth(2);
    functionBarrelAlphaEcalHcal->SetNpx(10000);
    
    functionBarrelAlphaEcalHcal->FixParameter(0, 5.62379e-02);
    functionBarrelAlphaEcalHcal->FixParameter(1, -1.58344e-01);
    functionBarrelAlphaEcalHcal->FixParameter(2, 6.51778e+01);
    
    functionBarrelAlphaEcalHcal->Draw("same");
    
    
    TF1 *functionBarrelBetaEcalHcal = new TF1("functionBarrelBetaEcalHcal","[0]+[1]*exp(-x/[2])", 1, 220);
    
    functionBarrelBetaEcalHcal->SetLineColor(4);
    functionBarrelBetaEcalHcal->SetLineWidth(2);
    functionBarrelBetaEcalHcal->SetNpx(10000);
    
    functionBarrelBetaEcalHcal->FixParameter(0, 4.96915e-02);
    functionBarrelBetaEcalHcal->FixParameter(1, 9.77473e-02);
    functionBarrelBetaEcalHcal->FixParameter(2, 7.84473e+01);
    
    functionBarrelBetaEcalHcal->Draw("same");
*/
    
    
    TLegend *leg = new TLegend(0.58,0.13,0.88,0.38);
    leg->SetFillColor(0);
    
    leg->SetLineWidth(1);
    leg->SetTextSize(0.04);
    leg->SetTextFont(132);
    
    leg->SetHeader(region);
    leg->AddEntry(coeffAEH, "#alpha for EH-hadron", "lpe");
    leg->AddEntry(coeffBEH, "#beta for EH-hadron", "lpe");
    leg->AddEntry(coeffAH, "#alpha for H-hadron", "lpe");
    leg->AddEntry(coeffBH, "#beta for H-hadron", "lpe");
    
    leg->Draw("same");
    
    c1->SaveAs("../../../../coeff_alphabeta_"+region+".png");
    
    delete c1;
}
void Overlay_coeff() {
  draw("barrel");
  draw("endcap");
}
