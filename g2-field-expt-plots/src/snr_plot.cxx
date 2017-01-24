// Example that plots the times for events in simulated fixed probe data.

#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TCanvas.h"

#include "g2field/core/field_structs.hh"

int main(void)
{
  TFile *pf = new TFile("data/fixed_run_00002.root");
  TTree *pt = (TTree *)pf->Get("t_fxpr");
  int N = pt->GetEntries();

  g2field::fixed_t data;
  pt->SetBranchAddress("fixed_probes", &data.sys_clock[0]);

  TCanvas c1;
  TH1D *ph1 = new TH1D("h1", "", N, 0, N);
  ph1->SetTitle("Fixed Probe Signal to Noise; Entry; SNR;");

  for (int i = 0; i < pt->GetEntries(); ++i) {
    pt->GetEntry(i);
    ph1->SetBinContent(i, data.snr[0]);
  }

  ph1->Draw("l");
  c1.Print("output/fixed_probe_times.png");

  return 0;
}
