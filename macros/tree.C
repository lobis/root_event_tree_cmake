#include <TTree.h>

class Track {
public:
    Int_t fTrackID;
    TString fParticleName;
};

class Event {
public:
    Int_t fEventID;
    std::vector<Track> fTracks;

    ClassDef(Event, 1);
};


void tree() {

    TTree *tree = new TTree("tree", "My Tree");
    Event *event = new Event;

    tree->Branch("Event", &event);

    for (int i = 0; i < 100; i++) {
        event->fEventID = i;

        for (int j = 0; j < 10; j++) {
            Track track;
            track.fParticleName = "testParticle";
            track.fTrackID = j;

            event->fTracks.push_back(track);
        }

        tree->Fill();
    }

    //tree->StartViewer();

    auto file = new TFile("tree.root", "RECREATE");
    tree->Write();
    file->Close();
    delete file;
}