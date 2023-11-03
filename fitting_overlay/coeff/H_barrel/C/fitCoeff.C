void fitCoeff()
{
    gROOT->SetStyle("Modern"); //classic, modern, Default
    gStyle->SetOptStat(kTRUE);
    gStyle->SetOptFit(1111);
    
    TFile *_f = new TFile("../../../../coeffC_barrel.root");
    
    TGraphErrors *coeff = (TGraphErrors*)_f->Get("Graph");
    
    TCanvas *c1 = new TCanvas("c1","c1",800,600);
    
    TF1 *functionBarrelHcalC = new TF1("functionBarrelHcalC","[0]+((([1]+([2]/sqrt(x)))*exp(-(x^[6]/[3])))-([4]*exp(-(x^[7]/[5]))))", 0.1, 550);
    //TF1 *functionBarrelHcalC = new TF1("functionBarrelHcalC","[0] + [1]*( [2]*x+[3]/( [4]*sqrt([5]*x) ) )*exp([6]*x) + [7]*exp([8]*x*x)", 0.1, 550);
    
    functionBarrelHcalC->SetLineColor(2);
    functionBarrelHcalC->SetLineWidth(2);
    functionBarrelHcalC->SetNpx(10000);

    //coeff->RemovePoint(13);
    //coeff->RemovePoint(12);
    
    /*
    functionBarrelHcalC->SetParameter(0, -4.35517e+01);
    functionBarrelHcalC->SetParameter(1,  6.04706e-05);
    functionBarrelHcalC->SetParameter(2,  1.26137e+04);
    functionBarrelHcalC->SetParameter(3,  3.62885e-03);
    functionBarrelHcalC->SetParameter(4, -8.37593e-08);
    functionBarrelHcalC->SetParameter(5,  1.46103e-02);
    functionBarrelHcalC->SetParameter(6, -1.59642e-01);
    functionBarrelHcalC->SetParameter(7,  1.45366e+01);
    functionBarrelHcalC->SetParameter(8, -1.98386e-08);
    */
    
    /*
    functionBarrelHcalC->FixParameter(0, 1.00573e+00);
    functionBarrelHcalC->FixParameter(1, -1.78467e-03);
    functionBarrelHcalC->FixParameter(2, 2.06221e+00);
    functionBarrelHcalC->FixParameter(3, 2.21548e+01);
    functionBarrelHcalC->FixParameter(4, 5.20985e-02);
    functionBarrelHcalC->FixParameter(5, 6.41895e-02);
    functionBarrelHcalC->FixParameter(6, -2.55431e-01);
    functionBarrelHcalC->FixParameter(7, 2.01823e-02);
    functionBarrelHcalC->FixParameter(8, -7.10823e-05);
    */
    
     functionBarrelHcalC->SetParameter(0, -1.16923e+00);
     functionBarrelHcalC->SetParameter(1,  3.39556e+01);
     functionBarrelHcalC->SetParameter(2,  4.00452e+01);
     functionBarrelHcalC->SetParameter(3,  2.04623e-01);
     functionBarrelHcalC->SetParameter(4,  3.20877e+01);
     functionBarrelHcalC->SetParameter(5,  2.06855e-01);
     functionBarrelHcalC->SetParameter(6, -6.50582e-01);
     functionBarrelHcalC->SetParameter(7, -7.51471e-01);
    
    /*
    functionBarrelHcalC->SetParameter(0, -1.01256e+00);
    functionBarrelHcalC->SetParameter(1, -1.40879e+00);
    functionBarrelHcalC->SetParameter(2, -1.57720e+00);
    functionBarrelHcalC->SetParameter(3, 2.92263e+00);
    functionBarrelHcalC->SetParameter(4, -1.97614e+04);
    functionBarrelHcalC->SetParameter(5, 1.07003e-04);
    functionBarrelHcalC->SetParameter(6, 1.01446e+00);
    functionBarrelHcalC->SetParameter(7, -7.21621e-01);
    */
    
    
    coeff->Draw("AP");
    coeff->Fit("functionBarrelHcalC","QR","same");
    coeff->Fit("functionBarrelHcalC","QR","same");
    coeff->Fit("functionBarrelHcalC","QR","same");
    coeff->Fit("functionBarrelHcalC","QR","same");
    coeff->Fit("functionBarrelHcalC","QR","same");
    coeff->Fit("functionBarrelHcalC","QR","same");
    coeff->Fit("functionBarrelHcalC","QR","same");
    coeff->Fit("functionBarrelHcalC","QR","same");
    coeff->Fit("functionBarrelHcalC","QR","same");
    coeff->Fit("functionBarrelHcalC","QR","same");
    coeff->Fit("functionBarrelHcalC","R","same");
    
    functionBarrelHcalC->Draw("same");
    cout << functionBarrelHcalC->GetMinimum() << endl;
    
    c1->SaveAs("coeffC.eps");
    
    //delete c1;
}
