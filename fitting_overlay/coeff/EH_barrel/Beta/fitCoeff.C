void fitCoeff()
{
    gROOT->SetStyle("Modern"); //classic, modern, Default
    gStyle->SetOptStat(kTRUE);
    gStyle->SetOptFit(1111);
    
    TFile *_f = new TFile("../../../../coeffBeta_EH_barrel.root");
    
    TGraphErrors *coeff = (TGraphErrors*)_f->Get("Graph");
    //coeff->RemovePoint(4);
    
    TCanvas *c1 = new TCanvas("c1","c1",800,600);
    
    //TF1 *functionBarrelBetaEcalHcal = new TF1("functionBarrelBetaEcalHcal","[0]+[1]*exp(-x/[2])", 1, 1000);
    //TF1 *functionBarrelBetaEcalHcal = new TF1("functionBarrelBetaEcalHcal","[0] + [1]*( [2]*x+[3]/( [4]*sqrt([5]*x) ) )*exp([6]*x) + [7]*exp([8]*x*x)", 8.0, 550);
    TF1 *functionBarrelBetaEcalHcal = new TF1("functionBarrelBetaEcalHcal","[0]+((([1]+([2]/sqrt(x)))*exp(-(x^[6]/[3])))-([4]*exp(-(x^[7]/[5]))))", 5.1, 550);
    
    functionBarrelBetaEcalHcal->SetLineColor(2);
    functionBarrelBetaEcalHcal->SetLineWidth(2);
    functionBarrelBetaEcalHcal->SetNpx(10000);
    //coeff->RemovePoint(2);

    functionBarrelBetaEcalHcal->SetParameter(0,  7.31823e-02);
    functionBarrelBetaEcalHcal->SetParameter(1,  1.19792e+02);
    functionBarrelBetaEcalHcal->SetParameter(2, -7.31083e+00);
    functionBarrelBetaEcalHcal->SetParameter(3,  1.76734e-02);
    functionBarrelBetaEcalHcal->SetParameter(4,  1.19456e+02);
    functionBarrelBetaEcalHcal->SetParameter(5,  1.87185e-02);
    functionBarrelBetaEcalHcal->SetParameter(6, -1.40489e+00);
    functionBarrelBetaEcalHcal->SetParameter(7, -1.38142e+00);
    
/*
    functionBarrelBetaEcalHcal->SetParameter(0,  8.92115e-01);
    functionBarrelBetaEcalHcal->SetParameter(1,  1.41923e-03);
    functionBarrelBetaEcalHcal->SetParameter(2, -1.04482e+01);
    functionBarrelBetaEcalHcal->SetParameter(3, -1.95109e+01);
    functionBarrelBetaEcalHcal->SetParameter(4,  5.51698e-02);
    functionBarrelBetaEcalHcal->SetParameter(5,  6.00565e-02);
    functionBarrelBetaEcalHcal->SetParameter(6, -1.72024e-01);
    functionBarrelBetaEcalHcal->SetParameter(7,  2.73305e-02);
    //functionBarrelBetaEcalHcal->SetParameter(8, -5.49169e-05);
*/
    

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
    functionBarrelBetaEcalHcal->SetRange(0,550);
    functionBarrelBetaEcalHcal->Draw("same");
    cout << functionBarrelBetaEcalHcal->GetMaximum() << endl;
    cout << functionBarrelBetaEcalHcal->GetMinimum() << endl;
    
    c1->SaveAs("coeff_beta.eps");
    
    //delete c1;
}
