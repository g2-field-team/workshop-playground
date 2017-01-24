// Example that plots the times for events in simulated fixed probe data.

#include "TH1.h"
#include "TCanvas.h"

#include "fid.h"

int main(void)
{
  int N = 10000;
  double dt = 10.0 / N;

  fid::FidFactory ff;
  std::vector<double> wf(N, 0.0);
  std::vector<double> tm = fid::construct_linspace(0.0, 10.0 - dt, N);

  ff.IdealFid(wf, tm);

  TCanvas c1;
  TH1D *ph1 = new TH1D("h1", "", N, 0, tm[N-1]);
  ph1->SetTitle("Ideal Fid; Time; Amplitude;");

  for (int i = 0; i < tm.size(); ++i) {
    printf("%0.6f, %0.6f\n", tm[i], wf[i]);
    ph1->SetBinContent(i, wf[i]);
  }

  ph1->Draw("l");
  c1.Print("output/ideal_fid_plot.png");

  return 0;
}
