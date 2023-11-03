void fitCoeff()
{
    gROOT->SetStyle("Modern"); //classic, modern, Default
    gStyle->SetOptStat(kTRUE);
    gStyle->SetOptFit(1111);
    
    TFile *_f = new TFile("../../../../coeffAlpha_EH_barrel.root");
    
    TGraphErrors *coeff = (TGraphErrors*)_f->Get("Graph");
    
    TCanvas *c1 = new TCanvas("c1","c1",800,600);
    
    //TF1 *functionBarrelAlphaEcalHcal = new TF1("functionBarrelAlphaEcalHcal","[0]+[1]*exp(-x/[2])", 1, 550);
    TF1 *functionBarrelAlphaEcalHcal = new TF1("functionBarrelAlphaEcalHcal","[0]+((([1]+([2]/sqrt(x)))*exp(-(x^[6]/[3])))-([4]*exp(-(x^[7]/[5]))))", 0.1, 1000);
    functionBarrelAlphaEcalHcal->SetLineColor(2);
    functionBarrelAlphaEcalHcal->SetLineWidth(2);
    functionBarrelAlphaEcalHcal->SetNpx(10000);
    
    
    //functionBarrelAlphaEcalHcal->SetParameters(0.02, -0.1, 200);
    
    /*
    functionBarrelAlphaEcalHcal->SetParameter(0, 1.29860e-02);
    functionBarrelAlphaEcalHcal->SetParameter(1, -8.07722e-02);
    functionBarrelAlphaEcalHcal->SetParameter(2, 3.15339e+01);
    
    functionBarrelAlphaEcalHcal->FixParameter(0, 5.62379e-02);
    functionBarrelAlphaEcalHcal->FixParameter(1, -1.58344e-01);
    functionBarrelAlphaEcalHcal->FixParameter(2, 6.51778e+01);
    */
    
    
    /*
    functionBarrelAlphaEcalHcal->FixParameter(0, -2.63808e+01);
    functionBarrelAlphaEcalHcal->FixParameter(1,  2.64942e+01);
    functionBarrelAlphaEcalHcal->FixParameter(2, 1.46505e+01);
    functionBarrelAlphaEcalHcal->FixParameter(3, 2.04955e+00);
    functionBarrelAlphaEcalHcal->FixParameter(4, 2.99757e-02);
    functionBarrelAlphaEcalHcal->FixParameter(5, 1.42295e-16);
    functionBarrelAlphaEcalHcal->FixParameter(6, -4.63144e-01);
    functionBarrelAlphaEcalHcal->FixParameter(7, -6.87217e+00);
    */
    
    functionBarrelAlphaEcalHcal->SetParameter(0, -1.01818e+00);
    functionBarrelAlphaEcalHcal->SetParameter(1,  4.04071e+01);
    functionBarrelAlphaEcalHcal->SetParameter(2,  7.13033e+00);
    functionBarrelAlphaEcalHcal->SetParameter(3,  2.56828e-03);
    functionBarrelAlphaEcalHcal->SetParameter(4,  3.97428e+01);
    functionBarrelAlphaEcalHcal->SetParameter(5,  1.66618e-03);
    functionBarrelAlphaEcalHcal->SetParameter(6, -2.24057e+00);
    functionBarrelAlphaEcalHcal->SetParameter(7, -2.36582e+00);
    
    coeff->Draw("AP");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","QR","same");
    coeff->Fit("functionBarrelAlphaEcalHcal","R","same");
    functionBarrelAlphaEcalHcal->Draw("same");
    
    cout << functionBarrelAlphaEcalHcal->GetMinimum() << endl;
    c1->SaveAs("coeff_alpha.eps");
    
    //delete c1;
}
