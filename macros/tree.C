#include <TTree.h>

class Event : public TObject {

public:
    Int_t fEventID;

    ClassDef(Event, 1);
};


void tree() {

    TTree *tree = new TTree("tree", "My Tree");
    Event *event = new Event;

    tree->Branch("Event", &event);

    for (int i = 0; i < 100; i++) {
        event->fEventID = i;
        tree->Fill();
    }

    //tree->StartViewer();


    auto file = new TFile("tree.root", "RECREATE");
    tree->Write();
    file->Close();
    delete file;
}