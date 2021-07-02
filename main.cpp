#include <TFile.h>
#include <TInterpreter.h>
#include <TTree.h>

#include <iostream>

#include "DataModel.h"

using namespace std;

int main() {
    TString filename = "tree.root";
    TString treeName = "tree";

    gInterpreter->Declare("#include \"DataModel.h\"");

    auto tree = new TTree(treeName, "My Tree");
    auto event = new Event();

    tree->Branch("fEvents", &event);

    for (int i = 0; i < 100; i++) {
        event->fEventID = i;

        for (int j = 0; j < 10; j++) {
            Track track;
            track.fTrackID = j;

            for (int k = 0; k < 20; k++) {
                Step step;
                step.fStepID = k;
                track.fSteps.push_back(step);
            }

            event->fTracks.push_back(track);
        }
        tree->Fill();
    }


    auto file = new TFile(filename, "RECREATE");
    tree->Write();
    file->Close();
    delete file;

    cout << "READING TREE..." << endl;

    file = new TFile(filename);
    file->ls();

    file->GetObject(treeName, tree);

    tree->Print();
    tree->Show(0);
}
