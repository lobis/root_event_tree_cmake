
#ifndef ROOT_EVENT_TREE_CMAKE_DATAMODEL_H
#define ROOT_EVENT_TREE_CMAKE_DATAMODEL_H

#include <TObject.h>

class Step {
public:
    Int_t fStepID;

    Step() {}
    ~Step() {}

    ClassDefInline(Step, 1);
};

class Track {
public:
    Int_t fTrackID;
    std::vector<Step> fSteps;

    Track() {}
    ~Track() {}

    ClassDefInline(Track, 1);
};

class Event : public TObject {

public:
    Int_t fEventID;

    Event() {}
    ~Event() {}

    std::vector<Track> fTracks;

    ClassDefInline(Event, 1);
};


#endif//ROOT_EVENT_TREE_CMAKE_DATAMODEL_H
