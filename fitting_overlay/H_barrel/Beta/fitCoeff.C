void fitCoeff()
{
    gROOT->SetStyle("Modern"); //classic, modern, Default
    gStyle->SetOptStat(kTRUE);
    gStyle->SetOptFit(1111);
    
    TFile *_f = new TFile("../../../../coeffBeta_H_barrel.root");
    
    TGraphErrors *coeff = (TGraphErrors*)_f->Get("Graph");
    
    TCanvas *c1 = new TCanvas("c1","c1",800,600);
    
    //TF1 *functionBarrelBetaEcalHcal = new TF1("functionBarrelBetaEcalHcal","[0]+[1]*exp(-x/[2])", 1, 1000);
    //TF1 *functionBarrelBetaEcalHcal = new TF1("functionBarrelBetaEcalHcal","[0] + [1]*( [2]*x+[3]/( [4]*sqrt([5]*x) ) )*exp([6]*x) + [7]*exp([8]*x*x)", 0, 550);
    TF1 *functionBarrelBetaEcalHcal = new TF1("functionBarrelBetaEcalHcal","[0]+((([1]+([2]/sqrt(x)))*exp(-(x^[6]/[3])))-([4]*exp(-(x^[7]/[5]))))", 1, 550);
    
    functionBarrelBetaEcalHcal->SetLineColor(2);
    functionBarrelBetaEcalHcal->SetLineWidth(2);
    functionBarrelBetaEcalHcal->SetNpx(10000);
    
    //functionBarrelBetaEcalHcal->SetParameters(1.17842e-01,1.71167e-01,5.88921e+00);
    /*
    functionBarrelBetaEcalHcal->SetParameter(0, 5.45881e-02);
    functionBarrelBetaEcalHcal->SetParameter(1, 7.11096e-02);
    functionBarrelBetaEcalHcal->SetParameter(2, 1.02441e+02);
    
    functionBarrelBetaEcalHcal->FixParameter(0, 4.96915e-02);
    functionBarrelBetaEcalHcal->FixParameter(1, 9.77473e-02);
    functionBarrelBetaEcalHcal->FixParameter(2, 7.84473e+01);
    */
    
    
    /*
    functionBarrelBetaEcalHcal->FixParameter(0, 9.86190e-03);
    functionBarrelBetaEcalHcal->FixParameter(1, 2.27992e-01);
    functionBarrelBetaEcalHcal->FixParameter(2, -4.13328e-01);
    functionBarrelBetaEcalHcal->FixParameter(3, 3.46763e+04);
    functionBarrelBetaEcalHcal->FixParameter(4, 2.47729e-01);
    functionBarrelBetaEcalHcal->FixParameter(5, 7.15015e-02);
    functionBarrelBetaEcalHcal->FixParameter(6, 1.32877);
    functionBarrelBetaEcalHcal->FixParameter(7, -9.50550e-01);
    */
    
    /*
    functionBarrelBetaEcalHcal->FixParameter(0, -2.62750e+01);
    functionBarrelBetaEcalHcal->FixParameter(1,  2.65960e+01);
    functionBarrelBetaEcalHcal->FixParameter(2, 1.74068e+01);
    functionBarrelBetaEcalHcal->FixParameter(3, 1.88071e+00);
    functionBarrelBetaEcalHcal->FixParameter(4, 9.39792e-02);
    functionBarrelBetaEcalHcal->FixParameter(5, 1.71326e-03);
    functionBarrelBetaEcalHcal->FixParameter(6, -4.35232e-01);
    functionBarrelBetaEcalHcal->FixParameter(7, -1.29297e+00);
    */
    
    functionBarrelBetaEcalHcal->SetParameter(0, -2.61338e+01);
    functionBarrelBetaEcalHcal->SetParameter(1,  2.68222e+01);
    functionBarrelBetaEcalHcal->SetParameter(2,  3.00249e+01);
    functionBarrelBetaEcalHcal->SetParameter(3,  1.23400e+00);
    functionBarrelBetaEcalHcal->SetParameter(4,  9.87990e-02);
    functionBarrelBetaEcalHcal->SetParameter(5,  4.35646e-05);
    functionBarrelBetaEcalHcal->SetParameter(6, -4.02126e-01);
    functionBarrelBetaEcalHcal->SetParameter(7, -2.04324e+00);
    
    coeff->Draw("AP");
    
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    coeff->Fit("functionBarrelBetaEcalHcal","QR","same");
    
    coeff->Fit("functionBarrelBetaEcalHcal","R","same");
    functionBarrelBetaEcalHcal->Draw("same");
    cout << functionBarrelBetaEcalHcal->GetMaximum() << endl;
    cout << functionBarrelBetaEcalHcal->GetMinimum() << endl;
    
    c1->SaveAs("coeff_beta.eps");
    
    //delete c1;
}
