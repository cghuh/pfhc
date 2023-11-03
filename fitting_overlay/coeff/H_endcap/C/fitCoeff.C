void fitCoeff()
{
    gROOT->SetStyle("Modern"); //classic, modern, Default
    gStyle->SetOptStat(kTRUE);
    gStyle->SetOptFit(1111);
    
    TFile *_f = new TFile("../../../../coeffC_endcap.root");
    
    TGraphErrors *coeff = (TGraphErrors*)_f->Get("Graph");
    
    TCanvas *c1 = new TCanvas("c1","c1",800,600);
    
    //TF1 *functionEndcapHcalC = new TF1("functionEndcapHcalC","[0] + [1]*( [2]*x+[3]/( [4]*sqrt([5]*x) ) )*exp([6]*x) + [7]*exp([8]*x*x)", 1.0, 550);
    TF1 *functionEndcapHcalC = new TF1("functionEndcapHcalC","[0]+((([1]+([2]/sqrt(x)))*exp(-(x^[6]/[3])))-([4]*exp(-(x^[7]/[5]))))", 0.1, 550);
    functionEndcapHcalC->SetLineColor(2);
    functionEndcapHcalC->SetLineWidth(2);
    functionEndcapHcalC->SetNpx(10000);

    //coeff->RemovePoint(31);
    
/*
    functionEndcapHcalC->SetParameter(0,  1.04741e+00);
    functionEndcapHcalC->SetParameter(1, -4.70599e-04);
    functionEndcapHcalC->SetParameter(2, -1.41861e+02);
    functionEndcapHcalC->SetParameter(3,  1.72497e+01);
    functionEndcapHcalC->SetParameter(4,  2.47057e-02);
    functionEndcapHcalC->SetParameter(5,  2.68674e-02);
    functionEndcapHcalC->SetParameter(6, -1.14542e-01);
    functionEndcapHcalC->SetParameter(7,  4.03805e-02);
    functionEndcapHcalC->SetParameter(8, -5.15065e-05);
*/
    
     functionEndcapHcalC->SetParameter(0,  5.92140e-01);
     functionEndcapHcalC->SetParameter(1,  3.85624e+01);
     functionEndcapHcalC->SetParameter(2,  1.05598e+00);
     functionEndcapHcalC->SetParameter(3,  8.14872e-02);
     functionEndcapHcalC->SetParameter(4,  3.82629e+01);
     functionEndcapHcalC->SetParameter(5,  7.74271e-02);
     functionEndcapHcalC->SetParameter(6, -1.86445e+00);
     functionEndcapHcalC->SetParameter(7, -1.87155e+00);
    
    
    coeff->Draw("AP");
    coeff->Fit("functionEndcapHcalC","QR","same");
    coeff->Fit("functionEndcapHcalC","QR","same");
    coeff->Fit("functionEndcapHcalC","QR","same");
    coeff->Fit("functionEndcapHcalC","QR","same");
    coeff->Fit("functionEndcapHcalC","QR","same");
    coeff->Fit("functionEndcapHcalC","QR","same");
    coeff->Fit("functionEndcapHcalC","QR","same");
    coeff->Fit("functionEndcapHcalC","QR","same");
    coeff->Fit("functionEndcapHcalC","QR","same");
    coeff->Fit("functionEndcapHcalC","QR","same");
    coeff->Fit("functionEndcapHcalC","R","same");
    
    functionEndcapHcalC->SetRange(0,550);
    functionEndcapHcalC->Draw("same");
    cout << functionEndcapHcalC->GetMinimum() << endl;
    cout << functionEndcapHcalC->GetMaximum() << endl;
    
    c1->SaveAs("coeffC.eps");
    
    //delete c1;
}
