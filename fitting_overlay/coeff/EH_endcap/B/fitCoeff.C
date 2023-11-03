void fitCoeff()
{
    gROOT->SetStyle("Modern"); //classic, modern, Default
    gStyle->SetOptStat(kTRUE);
    gStyle->SetOptFit(1111);
    
    TFile *_f = new TFile("../../../../coeffB_endcap.root");
    
    TGraphErrors *coeff = (TGraphErrors*)_f->Get("Graph");
    
    TCanvas *c1 = new TCanvas("c1","c1",800,600);
    
    //TF1 *functionEndcapEcalHcalC = new TF1("functionEndcapEcalHcalC","[0] + [1]*( [2]*x+[3]/( [4]*sqrt([5]*x) ) )*exp([6]*x) + [7]*exp([8]*x*x)", 1.1, 220);
    //TF1 *functionEndcapEcalHcalC = new TF1("functionEndcapEcalHcalC","[0] + [1]*([2]+[3]*x^[4]/( [5]*sqrt([6]*x) ) )*exp([7]*x^[8]) + [9]*exp([10]*x^[11])", 0, 220);
    TF1 *functionEndcapEcalHcalC = new TF1("functionEndcapEcalHcalC","[0]+((([1]+([2]/sqrt(x)))*exp(-(x^[6]/[3])))-([4]*exp(-(x^[7]/[5]))))", 0.1, 950);
    
    functionEndcapEcalHcalC->SetLineColor(2);
    functionEndcapEcalHcalC->SetLineWidth(2);
    functionEndcapEcalHcalC->SetNpx(10000);
    
    //coeff->RemovePoint(32);
    //coeff->RemovePoint(33);
    //coeff->RemovePoint(34);

    /*
    functionEndcapEcalHcalC->SetParameter(0,  1.21459e+00);
    functionEndcapEcalHcalC->SetParameter(1, -3.21725e-04);
    functionEndcapEcalHcalC->SetParameter(2,  2.58167e+02);
    functionEndcapEcalHcalC->SetParameter(3,  4.13983e+00);
    functionEndcapEcalHcalC->SetParameter(4,  1.42424e-02);
    functionEndcapEcalHcalC->SetParameter(5,  1.35958e-02);
    functionEndcapEcalHcalC->SetParameter(6, -8.89138e-02);
    functionEndcapEcalHcalC->SetParameter(7, -6.35791e-01);
    functionEndcapEcalHcalC->SetParameter(8, -5.65347e-05);
    */
    
     functionEndcapEcalHcalC->SetParameter(0, -2.73687e+01);
     functionEndcapEcalHcalC->SetParameter(1,  2.60279e+01);
     functionEndcapEcalHcalC->SetParameter(2,  3.49678e+01);
     functionEndcapEcalHcalC->SetParameter(3,  1.17310e+00);
     functionEndcapEcalHcalC->SetParameter(4, -2.45636e+00);
     functionEndcapEcalHcalC->SetParameter(5,  1.61974e-03);
     functionEndcapEcalHcalC->SetParameter(6, -4.45843e-01);
     functionEndcapEcalHcalC->SetParameter(7, -2.82269e+00);
    
    coeff->Draw("AP");
    
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","QR","same");
    coeff->Fit("functionEndcapEcalHcalC","R","same");

    cout << functionEndcapEcalHcalC->GetMinimum() << endl;
    cout << functionEndcapEcalHcalC->GetMaximum() << endl;
    
    functionEndcapEcalHcalC->Draw("same");
    
    c1->SaveAs("coeffB.eps");
    
    //delete c1;
}
