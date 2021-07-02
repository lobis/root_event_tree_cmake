
#ifndef ROOT_EVENT_TREE_CMAKE_DATAMODEL_H
#define ROOT_EVENT_TREE_CMAKE_DATAMODEL_H

#include <TObject.h>

class Track {
public:
    Int_t fTrackID;

    Track() {}
    ~Track() {}
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
