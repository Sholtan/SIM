void Read(TString w = "") {
	TFile* file = new TFile("output" + w + ".root", "READ");
	TH1F* hist = (TH1F*)file->Get("fE");
	hist->Draw("hist");
}