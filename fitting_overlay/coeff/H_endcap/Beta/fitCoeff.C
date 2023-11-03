void fitCoeff()
{
    gROOT->SetStyle("Modern"); //classic, modern, Default
    gStyle->SetOptStat(kTRUE);
    gStyle->SetOptFit(1111);
    
    TFile *_f = new TFile("../../../../coeffBeta_H_endcap.root");
    
    TGraphErrors *coeff = (TGraphErrors*)_f->Get("Graph");
    
    TCanvas *c1 = new TCanvas("c1","c1",800,600);
    
    //TF1 *functionEndcapBetaEcalHcal = new TF1("functionEndcapBetaEcalHcal","[0]+[1]*exp(-x/[2])", 1, 1000);
    //TF1 *functionEndcapBetaEcalHcal = new TF1("functionEndcapBetaEcalHcal","[0] + [1]*( [2]*x+[3]/( [4]*sqrt([5]*x) ) )*exp([6]*x) + [7]*exp([8]*x*x)", 0, 550);
    TF1 *functionEndcapBetaEcalHcal = new TF1("functionEndcapBetaEcalHcal","[0]+((([1]+([2]/sqrt(x)))*exp(-(x^[6]/[3])))-([4]*exp(-(x^[7]/[5]))))", 3.1, 550);
    
    functionEndcapBetaEcalHcal->SetLineColor(2);
    functionEndcapBetaEcalHcal->SetLineWidth(2);
    functionEndcapBetaEcalHcal->SetNpx(10000);

    //coeff->RemovePoint(1);
    //coeff->RemovePoint(8);
    
    /*
    functionEndcapBetaEcalHcal->SetParameter(0, -0.0231157);
    functionEndcapBetaEcalHcal->SetParameter(1, 0.0883841);
    functionEndcapBetaEcalHcal->SetParameter(2, 42.5061);
    */
    
    
    /*
     functionEndcapBetaEcalHcal->FixParameter(0, 9.72900e-01);
     functionEndcapBetaEcalHcal->FixParameter(1, -5.96078e-01);
     functionEndcapBetaEcalHcal->FixParameter(2, -1.07993e+00);
     functionEndcapBetaEcalHcal->FixParameter(3, 1.19324e+02);
     functionEndcapBetaEcalHcal->FixParameter(4, 1.09460e+00);
     functionEndcapBetaEcalHcal->FixParameter(5, 3.03339e-02);
     functionEndcapBetaEcalHcal->FixParameter(6, 1.02834e+00);
     functionEndcapBetaEcalHcal->FixParameter(7, -8.98741e-01);
    */
    
    
     functionEndcapBetaEcalHcal->SetParameter(0, -3.54097e+00);
     functionEndcapBetaEcalHcal->SetParameter(1,  9.85132e+01);
     functionEndcapBetaEcalHcal->SetParameter(2, -5.33002e+01);
     functionEndcapBetaEcalHcal->SetParameter(3,  3.02042e+00);
     functionEndcapBetaEcalHcal->SetParameter(4,  9.48173e+01);
     functionEndcapBetaEcalHcal->SetParameter(5,  1.00634e+00);
     functionEndcapBetaEcalHcal->SetParameter(6, -5.46652e-01);
     functionEndcapBetaEcalHcal->SetParameter(7, -5.36725e-01);
    
    coeff->Draw("AP");
    
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","QR","same");
    coeff->Fit("functionEndcapBetaEcalHcal","R","same");
    functionEndcapBetaEcalHcal->SetRange(0,550); 
    functionEndcapBetaEcalHcal->Draw("same");

    cout << functionEndcapBetaEcalHcal->GetMaximum() << endl;
    cout << functionEndcapBetaEcalHcal->GetMinimum() << endl;
    
    c1->SaveAs("coeff_beta.eps");
    
    //delete c1;
}
