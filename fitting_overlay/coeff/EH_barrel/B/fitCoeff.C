void fitCoeff()
{
    gROOT->SetStyle("Modern"); //classic, modern, Default
    gStyle->SetOptStat(kTRUE);
    gStyle->SetOptFit(1111);
    
    TFile *_f = new TFile("../../../../coeffB_barrel.root");
    
    TGraphErrors *coeff = (TGraphErrors*)_f->Get("Graph");
    
    TCanvas *c1 = new TCanvas("c1","c1",800,600);
    
    //TF1 *functionBarrelEcalHcalC = new TF1("functionBarrelEcalHcalC","[0] + [1]*( [2]*x+[3]/( [4]*sqrt([5]*x) ) )*exp([6]*x) + [7]*exp([8]*x*x)", 0.1, 550);
    TF1 *functionBarrelEcalHcalC = new TF1("functionBarrelEcalHcalC","[0]+((([1]+([2]/sqrt(x)))*exp(-(x^[6]/[3])))-([4]*exp(-(x^[7]/[5]))))", 2.5, 1000);
    functionBarrelEcalHcalC->SetLineColor(2);
    functionBarrelEcalHcalC->SetLineWidth(2);
    functionBarrelEcalHcalC->SetNpx(10000);

    //coeff->RemovePoint(6);
    
/*
    functionBarrelEcalHcalC->SetParameter(0,  6.61814e+01);
    functionBarrelEcalHcalC->SetParameter(1,  2.10705e-03);
    functionBarrelEcalHcalC->SetParameter(2, -1.89079e+02);
    functionBarrelEcalHcalC->SetParameter(3, -2.14370e+07);
    functionBarrelEcalHcalC->SetParameter(4,  1.07759e+02);
    functionBarrelEcalHcalC->SetParameter(5,  1.14902e+05);
    functionBarrelEcalHcalC->SetParameter(6, -1.70378e-01);
    functionBarrelEcalHcalC->SetParameter(7, -6.50502e+01);
    functionBarrelEcalHcalC->SetParameter(8, -1.61750e-08);
*/

    functionBarrelEcalHcalC->SetParameter(0, -2.56481e+01);
    functionBarrelEcalHcalC->SetParameter(1,  2.79744e+01);
    functionBarrelEcalHcalC->SetParameter(2,  5.83661e-01);
    functionBarrelEcalHcalC->SetParameter(3,  6.14428e+00);
    functionBarrelEcalHcalC->SetParameter(4,  1.42487e+00);
    functionBarrelEcalHcalC->SetParameter(5,  1.75955e-01);
    functionBarrelEcalHcalC->SetParameter(6, -4.49716e-01);
    functionBarrelEcalHcalC->SetParameter(7, -4.91731e-01);
    
    /*
    functionBarrelEcalHcalC->FixParameter(0, -2.63951e+01);
    functionBarrelEcalHcalC->FixParameter(1, 2.71683e+01);
    functionBarrelEcalHcalC->FixParameter(2, 1.10794e+01);
    functionBarrelEcalHcalC->FixParameter(3, 2.08963e+00);
    functionBarrelEcalHcalC->FixParameter(4, -1.20948e-01);
    functionBarrelEcalHcalC->FixParameter(5, 2.22751e-02);
    functionBarrelEcalHcalC->FixParameter(6, -6.02536e-01);
    functionBarrelEcalHcalC->FixParameter(7, -7.38905e-01);
    */
    
    
    coeff->Draw("AP");
    coeff->Fit("functionBarrelEcalHcalC","QR","same");
    coeff->Fit("functionBarrelEcalHcalC","QR","same");
    coeff->Fit("functionBarrelEcalHcalC","QR","same");
    coeff->Fit("functionBarrelEcalHcalC","QR","same");
    coeff->Fit("functionBarrelEcalHcalC","QR","same");
    coeff->Fit("functionBarrelEcalHcalC","QR","same");
    coeff->Fit("functionBarrelEcalHcalC","QR","same");
    coeff->Fit("functionBarrelEcalHcalC","QR","same");
    coeff->Fit("functionBarrelEcalHcalC","QR","same");
    coeff->Fit("functionBarrelEcalHcalC","QR","same");
    coeff->Fit("functionBarrelEcalHcalC","R","same");
    
    functionBarrelEcalHcalC->Draw("same");
    cout << functionBarrelEcalHcalC->GetMinimum() << endl;
    
    c1->SaveAs("coeffB.eps");
    
    //delete c1;
}
