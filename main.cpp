#include <TFile.h>
#include <TTree.h>

#include "DataModel.h"

int main() {
    TTree *tree = new TTree("tree", "My Tree");
    auto event = new Event();

    tree->Branch("Event", &event);

    for (int i = 0; i < 100; i++) {
        event->fEventID = i;
        tree->Fill();
    }

    auto file = new TFile("tree.root", "RECREATE");
    tree->Write();
    file->Close();
    delete file;
}
