void fitCoeff()
{
    gROOT->SetStyle("Modern"); //classic, modern, Default
    gStyle->SetOptStat(kTRUE);
    gStyle->SetOptFit(1111);
    
    TFile *_f = new TFile("../../../../coeffAlpha_EH_endcap.root");
    
    TGraphErrors *coeff = (TGraphErrors*)_f->Get("Graph");
    
    TCanvas *c1 = new TCanvas("c1","c1",800,600);

    //coeff->RemovePoint(0);
    //coeff->RemovePoint(1);
    //coeff->RemovePoint(2);
    //coeff->RemovePoint(3);
    
    //TF1 *functionEndcapAlphaEcalHcal = new TF1("functionEndcapAlphaEcalHcal","[0]+[1]*exp(-x/[2])", 1, 450);
    //TF1 *functionEndcapAlphaEcalHcal = new TF1("functionEndcapAlphaEcalHcal","[0]+[1]*x", 2, 550);
    TF1 *functionEndcapAlphaEcalHcal = new TF1("functionEndcapAlphaEcalHcal","[0]+((([1]+([2]/sqrt(x)))*exp(-(x^[6]/[3])))-([4]*exp(-(x^[7]/[5]))))", 2.1, 900);

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

    functionEndcapAlphaEcalHcal->SetParameter(0, -9.67378e-01);
    functionEndcapAlphaEcalHcal->SetParameter(1,  4.05581e+01);
    functionEndcapAlphaEcalHcal->SetParameter(2, -1.62321e-01);
    functionEndcapAlphaEcalHcal->SetParameter(3,  7.31830e-04);
    functionEndcapAlphaEcalHcal->SetParameter(4,  3.95861e+01);
    functionEndcapAlphaEcalHcal->SetParameter(5,  7.37024e-04);
    functionEndcapAlphaEcalHcal->SetParameter(6, -3.67952e+00);
    functionEndcapAlphaEcalHcal->SetParameter(7, -3.65751e+00);
    
/*
    functionEndcapAlphaEcalHcal->SetParameter(0,  1.60481e+02);
    functionEndcapAlphaEcalHcal->SetParameter(1,  4.30789e+02);
    functionEndcapAlphaEcalHcal->SetParameter(2,  6.76167e+02);
    functionEndcapAlphaEcalHcal->SetParameter(3,  4.12615e-01);
    functionEndcapAlphaEcalHcal->SetParameter(4,  5.99381e+02);
    functionEndcapAlphaEcalHcal->SetParameter(5,  1.18503e+00);
    functionEndcapAlphaEcalHcal->SetParameter(6, -3.60915e-01);
    functionEndcapAlphaEcalHcal->SetParameter(7, -2.80150e-01);
*/    


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

    functionEndcapAlphaEcalHcal->Draw("same");
  
    cout << functionEndcapAlphaEcalHcal->GetMaximum() << endl;
    cout << functionEndcapAlphaEcalHcal->GetMinimum() << endl;
    
    c1->SaveAs("coeff_alpha.eps");
    
    //delete c1;
}
