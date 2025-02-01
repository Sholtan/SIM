void draw_both()
{
	TFile* file = (TFile*)TFile::Open("Fe-56.root", "READ");

	if (file->IsZombie())
	{
		cerr << "file read EROR" << endl;
		return;
	}

	auto steps_tree = (TTree*)file->Get("steps_info");
	auto alpha_tree = (TTree*)file->Get("alpha_born");

	if (!steps_tree || !alpha_tree)
	{
		cerr << "Can't find steps_tree" << endl;
		return;
	}


	double steps_deposite_energy_MeV, alpha_deposite_energy_MeV;
	double steps_time_ns, alpha_time_ns;
	int pdg;
	int steps_Event_id, alpha_Event_id;



	steps_tree->SetBranchAddress("Deposite_Energy_MeV", &steps_deposite_energy_MeV);
	steps_tree->SetBranchAddress("time_ns", &steps_time_ns);
	steps_tree->SetBranchAddress("pdg", &pdg);

	steps_tree->SetBranchAddress("Event_id", &steps_Event_id);
	alpha_tree->SetBranchAddress("Event_id", &alpha_Event_id);

	alpha_tree->SetBranchAddress("Deposite_Energy_MeV", &alpha_deposite_energy_MeV);
	alpha_tree->SetBranchAddress("time_ns", &alpha_time_ns);
	

	int steps_entries = steps_tree->GetEntries();
	int alpha_entries = alpha_tree->GetEntries();

	cout << "steps_entries: " << steps_entries << endl;
	cout << "alpha_entries: " << alpha_entries << endl;

	double max_time = 16000;

	TH1D *steps_hist = new TH1D("Deposite E all particles", "all particles", 100, 0., max_time);   // Deposite E all particles
	TH1D *alpha_hist = new TH1D("Deposite E alpha", "alpha", 100, 0., max_time);   // Deposite E all particles

	int steps_count = 0;
	int alpha_count = 0;


	int id = 2;

	for (int i = 0; i < steps_entries; i++)
	{
		//if (i % (int)(steps_entries/100) == 0) cout << 100. * i/steps_entries << " %" << endl;
		steps_tree->GetEntry(i);

		//if (i < 100) cout << "steps_Event_id: " << steps_Event_id << endl;
		//if (steps_Event_id != id)
		//{
		//	continue;
		//}

		if (steps_time_ns > 1000. && steps_time_ns < max_time && pdg != 1000020040)
		{
			steps_hist->Fill(steps_time_ns, steps_deposite_energy_MeV);
			steps_count++;
		}
	}
	cout << "steps_count: " << steps_count << endl;

	for (int i = 0; i < alpha_entries; i++)
	{
		//if (i % (int)(alpha_entries/100) == 0) cout << 100. * i/alpha_entries << " %" << endl;
		alpha_tree->GetEntry(i);

		//if (alpha_Event_id != id)
		//{
		//	continue;
		//}

		if (alpha_time_ns > 1000. && alpha_time_ns < max_time)
		{
			alpha_hist->Fill(alpha_time_ns, alpha_deposite_energy_MeV);
			alpha_count++;
		}

	}
	cout << "alpha_count: " << alpha_count << endl;


	TCanvas *c1 = new TCanvas("canvas title 1", "canvas title 2", 800, 800);

	c1->SetLogy();

	gStyle->SetOptStat(1110);
	gStyle->SetStatFontSize(0.08);
	
	TPaveStats* stat1 = (TPaveStats*)alpha_hist->GetListOfFunctions()->FindObject("stats");
	if (stat1) 
	{
		cout << "stat1" << endl;
		stat1->SetX1NDC(0.6);
		stat1->SetX2NDC(0.84);
		stat1->SetY1NDC(0.76);
		stat1->SetY2NDC(0.88);
	}


	TPaveStats* stat2 = (TPaveStats*)alpha_hist->GetListOfFunctions()->FindObject("stats");
	if (stat2) 
	{
		cout << "stat2" << endl;
		stat2->SetX1NDC(0.6);
		stat2->SetX2NDC(0.84);
		stat2->SetY1NDC(0.64);
		stat2->SetY2NDC(0.76);
	}

	alpha_hist->Draw("HIST;SAMES");
	steps_hist->Draw("HIST;SAMES");
	
	



	gPad->Update();

	c1->BuildLegend();
	gPad->Update();


}