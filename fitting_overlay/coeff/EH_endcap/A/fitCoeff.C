void fitCoeff()
{
    gROOT->SetStyle("Modern"); //classic, modern, Default
    gStyle->SetOptStat(kTRUE);
    gStyle->SetOptFit(1111);
    
    TFile *_f = new TFile("../../../../coeffA_endcap.root");
    
    TGraphErrors *coeff = (TGraphErrors*)_f->Get("Graph");
    
    TCanvas *c1 = new TCanvas("c1","c1",800,600);

    //TF1 *functionEndcapEcalHcalB = new TF1("functionEndcapEcalHcalB","[0] + [1]*( [2]*x+[3]/( [4]*sqrt([5]*x) ) )*exp([6]*x) + [7]*exp([8]*x*x)", 0.1, 550);
    TF1 *functionEndcapEcalHcalB = new TF1("functionEndcapEcalHcalB","[0]+((([1]+([2]/sqrt(x)))*exp(-(x^[6]/[3])))-([4]*exp(-(x^[7]/[5]))))", 0.1, 550);
    
    functionEndcapEcalHcalB->SetLineColor(2);
    functionEndcapEcalHcalB->SetLineWidth(2);
    functionEndcapEcalHcalB->SetNpx(10000);

    //coeff->RemovePoint(24);
    
    /*
    functionEndcapEcalHcalB->SetParameter(0,  1.21459e+00);
    functionEndcapEcalHcalB->SetParameter(1, -3.21725e-04);
    functionEndcapEcalHcalB->SetParameter(2,  2.58167e+02);
    functionEndcapEcalHcalB->SetParameter(3,  4.13983e+00);
    functionEndcapEcalHcalB->SetParameter(4,  1.42424e-02);
    functionEndcapEcalHcalB->SetParameter(5,  1.35958e-02);
    functionEndcapEcalHcalB->SetParameter(6, -8.89138e-02);
    functionEndcapEcalHcalB->SetParameter(7, -6.35791e-01);
    functionEndcapEcalHcalB->SetParameter(8, -5.65347e-05);
    */
    
    functionEndcapEcalHcalB->SetParameter(0, -2.66345e+01);
    functionEndcapEcalHcalB->SetParameter(1,  2.69692e+01);
    functionEndcapEcalHcalB->SetParameter(2,  6.72558e+00);
    functionEndcapEcalHcalB->SetParameter(3,  4.98899e-01);
    functionEndcapEcalHcalB->SetParameter(4, -7.37051e-01);
    functionEndcapEcalHcalB->SetParameter(5,  9.54939e-02);
    functionEndcapEcalHcalB->SetParameter(6, -1.82503e+00);
    functionEndcapEcalHcalB->SetParameter(7, -6.26214e-01);
    
    
    coeff->Draw("AP");
    
    coeff->Fit("functionEndcapEcalHcalB","QR","same");
    coeff->Fit("functionEndcapEcalHcalB","QR","same");
    coeff->Fit("functionEndcapEcalHcalB","QR","same");
    coeff->Fit("functionEndcapEcalHcalB","QR","same");
    coeff->Fit("functionEndcapEcalHcalB","QR","same");
    coeff->Fit("functionEndcapEcalHcalB","QR","same");
    coeff->Fit("functionEndcapEcalHcalB","QR","same");
    coeff->Fit("functionEndcapEcalHcalB","QR","same");
    coeff->Fit("functionEndcapEcalHcalB","QR","same");
    coeff->Fit("functionEndcapEcalHcalB","QR","same");
    coeff->Fit("functionEndcapEcalHcalB","QR","same");
    coeff->Fit("functionEndcapEcalHcalB","QR","same");
    coeff->Fit("functionEndcapEcalHcalB","QR","same");
    coeff->Fit("functionEndcapEcalHcalB","QR","same");
    coeff->Fit("functionEndcapEcalHcalB","QR","same");
    coeff->Fit("functionEndcapEcalHcalB","QR","same");
    coeff->Fit("functionEndcapEcalHcalB","QR","same");
    coeff->Fit("functionEndcapEcalHcalB","QR","same");
    coeff->Fit("functionEndcapEcalHcalB","R","same");
    functionEndcapEcalHcalB->Draw("same");

    cout << functionEndcapEcalHcalB->GetMinimum() << endl;
    
    c1->SaveAs("coeffA.eps");
    
    //delete c1;
}
