void draw(TString region) {
    gROOT->SetStyle("Modern"); //classic, modern, Default
    gStyle->SetOptStat(kFALSE);
    gStyle->SetOptTitle(0);
    //gStyle->SetOptFit(1111);
    
    TFile *_f1 = new TFile("../../../../coeffA_"+region+".root");
    TFile *_f2 = new TFile("../../../../coeffB_"+region+".root");
    TFile *_f3 = new TFile("../../../../coeffC_"+region+".root");
    
    TGraphErrors *coeffA = (TGraphErrors*)_f1->Get("Graph");
    TGraphErrors *coeffB = (TGraphErrors*)_f2->Get("Graph");
    TGraphErrors *coeffC = (TGraphErrors*)_f3->Get("Graph");
    
    TCanvas *c1 = new TCanvas("c1","c1",1200,900);
    c1->SetGridx(1);
    c1->SetGridy(1);
    c1->SetLogx(1);
    
    //coeffA->SetTitle("Calibration Coefficients vs E_{true} for Barrel;E_{true} (GeV); Calibration coefficient");
    
    coeffA->SetMarkerColor(2);
    coeffB->SetMarkerColor(4);
    coeffC->SetMarkerColor(8);
    
    coeffA->SetLineColor(2);
    coeffB->SetLineColor(4);
    coeffC->SetLineColor(8);
    
    coeffA->SetMarkerStyle(22);
    coeffB->SetMarkerStyle(23);
    coeffC->SetMarkerStyle(23);

    coeffA->SetMinimum(-0.5);
    coeffA->SetMaximum(2.0);
    coeffA->GetXaxis()->SetRangeUser(4,1000);
    coeffA->SetPoint(coeffA->GetN(), 900,100);
    
    coeffA->Draw("AP");
    coeffB->Draw("P");
    coeffC->Draw("P");
    
  /*  
    TF1 *functionBarrelEcalHcalA = new TF1("functionBarrelEcalHcalA","[0] + [1]*( [2]*x+[3]/( [4]*sqrt([5]*x) ) )*exp([6]*x) + [7]*exp([8]*x*x)", 0, 250);
    functionBarrelEcalHcalA->SetLineColor(2);
    functionBarrelEcalHcalA->SetLineWidth(2);
    functionBarrelEcalHcalA->SetNpx(10000);
    
    functionBarrelEcalHcalA->FixParameter(0, 1.25494e+00);
    functionBarrelEcalHcalA->FixParameter(1, -7.95574e-04);
    functionBarrelEcalHcalA->FixParameter(2, 1.62079e+01);
    functionBarrelEcalHcalA->FixParameter(3, 2.62978e+01);
    functionBarrelEcalHcalA->FixParameter(4, 3.23307e-02);
    functionBarrelEcalHcalA->FixParameter(5, 1.07942e-02);
    functionBarrelEcalHcalA->FixParameter(6, -2.48366e-01);
    functionBarrelEcalHcalA->FixParameter(7, 1.55694e-01);
    functionBarrelEcalHcalA->FixParameter(8, -7.27705e-05);
    
    functionBarrelEcalHcalA->Draw("same");
    
    
    TF1 *functionBarrelEcalHcalB = new TF1("functionBarrelEcalHcalB","[0]+((([1]+([2]/sqrt(x)))*exp(-(x^[6]/[3])))-([4]*exp(-(x^[7]/[5]))))", 0, 250);
    functionBarrelEcalHcalB->SetLineColor(4);
    functionBarrelEcalHcalB->SetLineWidth(2);
    functionBarrelEcalHcalB->SetNpx(10000);
    
    functionBarrelEcalHcalB->FixParameter(0, -2.63951e+01);
    functionBarrelEcalHcalB->FixParameter(1, 2.71683e+01);
    functionBarrelEcalHcalB->FixParameter(2, 1.10794e+01);
    functionBarrelEcalHcalB->FixParameter(3, 2.08963e+00);
    functionBarrelEcalHcalB->FixParameter(4, -1.20948e-01);
    functionBarrelEcalHcalB->FixParameter(5, 2.22751e-02);
    functionBarrelEcalHcalB->FixParameter(6, -6.02536e-01);
    functionBarrelEcalHcalB->FixParameter(7, -7.38905e-01);
    
    functionBarrelEcalHcalB->Draw("same");
    
    
    TF1 *functionBarrelHcalC = new TF1("functionBarrelHcalC","[0] + [1]*( [2]*x+[3]/( [4]*sqrt([5]*x) ) )*exp([6]*x) + [7]*exp([8]*x*x)", 0, 1000);
    functionBarrelHcalC->SetLineColor(8);
    functionBarrelHcalC->SetLineWidth(2);
    functionBarrelHcalC->SetNpx(10000);
    
    functionBarrelHcalC->FixParameter(0, 1.00573e+00);
    functionBarrelHcalC->FixParameter(1, -1.78467e-03);
    functionBarrelHcalC->FixParameter(2, 2.06221e+00);
    functionBarrelHcalC->FixParameter(3, 2.21548e+01);
    functionBarrelHcalC->FixParameter(4, 5.20985e-02);
    functionBarrelHcalC->FixParameter(5, 6.41895e-02);
    functionBarrelHcalC->FixParameter(6, -2.55431e-01);
    functionBarrelHcalC->FixParameter(7, 2.01823e-02);
    functionBarrelHcalC->FixParameter(8, -7.10823e-05);
    
    functionBarrelHcalC->Draw("same");
*/
    
    
    TLegend *leg = new TLegend(0.48,0.13,0.88,0.38);
    leg->SetFillColor(0);
    
    leg->SetLineWidth(1);
    leg->SetTextSize(0.04);
    leg->SetTextFont(132);
    
    leg->SetHeader(region);
    leg->AddEntry(coeffA, "a for EH-hadron", "lpe");
    leg->AddEntry(coeffB, "b for EH-hadron", "lpe");
    leg->AddEntry(coeffC, "c for H-hadron", "lpe");
    
    leg->Draw("same");
    
    c1->SaveAs("../../../../coeff_abc_"+region+".png");
}
void Overlay_coeff() {
  draw("barrel");
  draw("endcap");
}
