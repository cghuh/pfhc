void fitCoeff()
{
    gROOT->SetStyle("Modern"); //classic, modern, Default
    gStyle->SetOptStat(kTRUE);
    gStyle->SetOptFit(1111);
    
    TFile *_f = new TFile("../../../../coeffAlpha_H_endcap.root");
    
    TGraphErrors *coeff = (TGraphErrors*)_f->Get("Graph");
    //coeff->RemovePoint(4);
    
    TCanvas *c1 = new TCanvas("c1","c1",800,600);
    
    //TF1 *functionEndcapAlphaEcalHcal = new TF1("functionEndcapAlphaEcalHcal","[0]+[1]*exp(-x/[2])", 1, 550);
    //TF1 *functionEndcapAlphaEcalHcal = new TF1("functionEndcapAlphaEcalHcal","[0]+[1]*x", 2, 550);
    TF1 *functionEndcapAlphaEcalHcal = new TF1("functionEndcapAlphaEcalHcal","[0]+((([1]+([2]/sqrt(x)))*exp(-(x^[6]/[3])))-([4]*exp(-(x^[7]/[5]))))", 0.1, 550);

    functionEndcapAlphaEcalHcal->SetLineColor(2);
    functionEndcapAlphaEcalHcal->SetLineWidth(2);
    functionEndcapAlphaEcalHcal->SetNpx(10000);
    
    //functionEndcapAlphaEcalHcal->SetParameters(0.02, -0.1, 200);
    
    
    /*
    functionEndcapAlphaEcalHcal->FixParameter(0, 5.46970e-02);
    functionEndcapAlphaEcalHcal->FixParameter(1, -9.06528e-02);
    functionEndcapAlphaEcalHcal->FixParameter(2, 9.28602e+01);
    
    
     functionEndcapAlphaEcalHcal->SetParameter(0, -1.62485e-04);
     functionEndcapAlphaEcalHcal->SetParameter(1, -3.37685e-02);
     functionEndcapAlphaEcalHcal->SetParameter(2, 3.51113e+01);
    */

    functionEndcapAlphaEcalHcal->SetParameter(0, -2.09543e+01);
    functionEndcapAlphaEcalHcal->SetParameter(1,  1.51665e+00);
    functionEndcapAlphaEcalHcal->SetParameter(2, -1.76311e+00);
    functionEndcapAlphaEcalHcal->SetParameter(3, -2.39415e-01);
    functionEndcapAlphaEcalHcal->SetParameter(4, -1.92766e+01);
    functionEndcapAlphaEcalHcal->SetParameter(5,  1.24591e+00);
    functionEndcapAlphaEcalHcal->SetParameter(6, -3.85750e-01);
    functionEndcapAlphaEcalHcal->SetParameter(7, -5.78789e-01);

    //functionEndcapAlphaEcalHcal->SetParLimits(2,-2.3,2.3);
    
    coeff->Draw("AP");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","QR","same");
    coeff->Fit("functionEndcapAlphaEcalHcal","R","same");
    functionEndcapAlphaEcalHcal->SetRange(0,550);
    functionEndcapAlphaEcalHcal->Draw("same");
    
    //cout << functionEndcapAlphaEcalHcal->GetMaximum() << endl;
    cout << functionEndcapAlphaEcalHcal->GetMinimum() << endl;

    c1->SaveAs("coeff_alpha.eps");
    
    //delete c1;
}
