
#ifndef ROOT_EVENT_TREE_CMAKE_DATAMODEL_H
#define ROOT_EVENT_TREE_CMAKE_DATAMODEL_H

#include <TObject.h>

class Steps {
public:
    std::vector<Int_t> fStepID;
    std::vector<TString> fProcessName;

    Steps() {}
    ~Steps() {}

    inline void InsertStep(Int_t i, const TString &processName) {
        fStepID.push_back(i);
        fProcessName.emplace_back(processName);
    }

    ClassDefInline(Steps, 1);// is this really necessary?
};

class Track {
public:
    Int_t fTrackID;
    Steps fSteps;

    Track() {
        fSteps = Steps();
    }
    ~Track() {}

    ClassDefInline(Track, 1);// is this really necessary?
};

class Event {

public:
    Int_t fEventID;

    Event() {}
    ~Event() {}

    std::vector<Track> fTracks;

    ClassDefInline(Event, 1);
};


#endif//ROOT_EVENT_TREE_CMAKE_DATAMODEL_H
