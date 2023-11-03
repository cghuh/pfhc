void fitCoeff()
{
    gROOT->SetStyle("Modern"); //classic, modern, Default
    gStyle->SetOptStat(kTRUE);
    gStyle->SetOptFit(1111);
    
    TFile *_f = new TFile("../../../../coeffA_barrel.root");
    
    TGraphErrors *coeff = (TGraphErrors*)_f->Get("Graph");
    
    TCanvas *c1 = new TCanvas("c1","c1",800,600);
    
    //TF1 *functionBarrelEcalHcalB = new TF1("functionBarrelEcalHcalB","[0] + [1]*( [2]*x+[3]/( [4]*sqrt([5]*x) ) )*exp([6]*x) + [7]*exp([8]*x*x)", 0.1, 250);
    TF1 *functionBarrelEcalHcalB = new TF1("functionBarrelEcalHcalB","[0]+((([1]+([2]/sqrt(x)))*exp(-(x^[6]/[3])))-([4]*exp(-(x^[7]/[5]))))", 0.1, 500);
    functionBarrelEcalHcalB->SetLineColor(2);
    functionBarrelEcalHcalB->SetLineWidth(2);
    functionBarrelEcalHcalB->SetNpx(10000);

    functionBarrelEcalHcalB->SetParameter(0, -1.55852e-01);
    functionBarrelEcalHcalB->SetParameter(1,  1.18371e+00);
    functionBarrelEcalHcalB->SetParameter(2,  3.47463e+00);
    functionBarrelEcalHcalB->SetParameter(3,  1.98627e-02);
    functionBarrelEcalHcalB->SetParameter(4, -4.92830e+06);
    functionBarrelEcalHcalB->SetParameter(5,  3.79226e-02);
    functionBarrelEcalHcalB->SetParameter(6, -2.13485e+00);
    functionBarrelEcalHcalB->SetParameter(7, -5.68106e-02);

/*
    functionBarrelEcalHcalB->SetParameter(0,  6.61814e+01);
    functionBarrelEcalHcalB->SetParameter(1,  2.10705e-03);
    functionBarrelEcalHcalB->SetParameter(2, -1.89079e+02);
    functionBarrelEcalHcalB->SetParameter(3, -2.14370e+07);
    functionBarrelEcalHcalB->SetParameter(4,  1.07759e+02);
    functionBarrelEcalHcalB->SetParameter(5,  1.14902e+05);
    functionBarrelEcalHcalB->SetParameter(6, -1.70378e-01);
    functionBarrelEcalHcalB->SetParameter(7, -6.50502e+01);
    functionBarrelEcalHcalB->SetParameter(8, -1.61750e-08);
*/
    
/*
    functionBarrelEcalHcalB->FixParameter(0,  6.61814e+01);
    functionBarrelEcalHcalB->FixParameter(1,  2.10705e-03);
    functionBarrelEcalHcalB->FixParameter(2, -1.89079e+02);
    functionBarrelEcalHcalB->FixParameter(3, -2.14370e+07);
    functionBarrelEcalHcalB->FixParameter(4,  1.07759e+02);
    functionBarrelEcalHcalB->FixParameter(5,  1.14902e+05);
    functionBarrelEcalHcalB->FixParameter(6, -1.70378e-01);
    functionBarrelEcalHcalB->FixParameter(7, -6.50502e+01);
    functionBarrelEcalHcalB->FixParameter(8, -1.61750e-08);
*/
    
    coeff->Draw("AP");
    coeff->Fit("functionBarrelEcalHcalB","QR","same");
    coeff->Fit("functionBarrelEcalHcalB","QR","same");
    coeff->Fit("functionBarrelEcalHcalB","QR","same");
    coeff->Fit("functionBarrelEcalHcalB","QR","same");
    coeff->Fit("functionBarrelEcalHcalB","QR","same");
    coeff->Fit("functionBarrelEcalHcalB","QR","same");
    coeff->Fit("functionBarrelEcalHcalB","QR","same");
    coeff->Fit("functionBarrelEcalHcalB","QR","same");
    coeff->Fit("functionBarrelEcalHcalB","QR","same");
    coeff->Fit("functionBarrelEcalHcalB","QR","same");
    coeff->Fit("functionBarrelEcalHcalB","QR","same");
    coeff->Fit("functionBarrelEcalHcalB","QR","same");
    coeff->Fit("functionBarrelEcalHcalB","QR","same");
    coeff->Fit("functionBarrelEcalHcalB","QR","same");
    coeff->Fit("functionBarrelEcalHcalB","QR","same");
    coeff->Fit("functionBarrelEcalHcalB","R","same");

    functionBarrelEcalHcalB->SetRange(0,250);
    functionBarrelEcalHcalB->Draw("same");
  
    cout << functionBarrelEcalHcalB->GetMinimum() << endl;
    
    c1->SaveAs("coeffA.eps");
    
    //delete c1;
}
