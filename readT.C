void readT()
{
    TFile* f = TFile::Open("output0.root", "READ");
    if (f->IsZombie())
    {
        cerr << "file READ error!" << endl;
        return;
    }
    TTree* treeA = (TTree*)f->Get("alpha");
    TTree* treeN = (TTree*)f->Get("neutron");
    if (!treeA && !treeN)
    {
        cerr << "Tree read error!" << endl;
        return;
    }
    //TCanvas* canv = new TCanvas("canv", "canv");

    double edep, time_alpha, time_neutron;

    treeA->SetBranchAddress("deposit_E", &edep);
    treeA->SetBranchAddress("t", &time_alpha);
    treeN->SetBranchAddress("t", &time_neutron);

    int entriesA = treeA->GetEntries();
    int entriesN = treeN->GetEntries();
    

    TH1F* hist = new TH1F("hist", "time_alpha", 4098, -1, 16385);
    TH1F* hist2 = new TH1F("hist2", "time_neutron", 4098, -1, 16385);
    TH1F* hist_Edep_A = new TH1F("hist_Edep_A", "hist_Edep_A", 600, 1300, 1900);
    //TH1F* hist3 = new TH1F("hist3", "Histogram", 100, -10, 10);
    int beforet = 0, aftert = 0, beforee = 0, aftere = 0;
    int beforetN = 0, aftertN = 0;
    for (int i = 0; i < entriesA; i++) {
        treeA->GetEntry(i);
        if (edep < 0) beforee++;
        else if (edep > 10000) aftere++;
        else hist_Edep_A->Fill(edep);
        //cout << time_alpha << endl;
        if (time_alpha < 0) beforet++;
        else if (time_alpha > 16384) aftert++;
        else hist->Fill(time_alpha);
        
        //hist2->Fill(edep);
        //cout << edep << endl;
        //;
        //hist3->Fill(in);
    }
    for (int i = 0; i < entriesN; i++) {
        treeN->GetEntry(i);
        //cout << time_alpha << endl;
        if (time_neutron < 0) beforetN++;
        else if (time_neutron > 16384) aftertN++;
        else hist2->Fill(time_neutron);

        //hist2->Fill(edep);
        //cout << edep << endl;
        //;
        //hist3->Fill(in);
    }
    
    //hist->Draw();
    //cout << "entries = " << entries << endl;
    cout << "before t = " << beforet << endl;
    cout << "after t = " << aftert << endl;
    cout << "before t N = " << beforetN << endl;
    cout << "after t N = " << aftertN << endl;
    cout << "entries A " << entriesA << endl;
    cout << "entries N" << entriesN << endl << endl;
    cout << "before 1300 kev = " << beforee << endl;
    cout << "after 1900 kev = " << aftere << endl;
    //hist2->Draw();
    //cout << "before e = " << beforee << endl;
    //cout << "after e = " << aftere << endl;
    //hist3->Draw("same");*/

    hist->GetXaxis()->SetTitle("Time, ns");
    hist->GetYaxis()->SetTitle("N");
    hist2->GetXaxis()->SetTitle("Time, ns");
    hist2->GetYaxis()->SetTitle("N");
    hist_Edep_A->GetXaxis()->SetTitle("Energy, KeV");
    hist_Edep_A->GetYaxis()->SetTitle("N");

    TCanvas* canv2 = new TCanvas("canvN", "canvN");
    canv2->Divide(1, 2);
    canv2->cd(1);
    gPad->SetLogy();
    hist2->Draw();
    canv2->cd(2);
    gPad->SetLogy();
    hist->Draw();

    // 
    // 
    // 
    //canv2->cd(3);

    TCanvas* canvE = new TCanvas("canvE", "canvE");
    canvE->SetLogy();
    hist_Edep_A->Draw();






    //tree->Draw("intN");

    //canv2->cd(4);
    /*THStack* hstack = new THStack();
    hstack->Add(hist);
    hstack->Add(hist2);
    hstack->Add(hist3);
    hstack->Draw();*/

}