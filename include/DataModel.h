
#ifndef ROOT_EVENT_TREE_CMAKE_DATAMODEL_H
#define ROOT_EVENT_TREE_CMAKE_DATAMODEL_H

#include <TObject.h>

class Event : public TObject {
public:
    Int_t fEventID;

    ClassDef(Event, 1);
};


#endif//ROOT_EVENT_TREE_CMAKE_DATAMODEL_H
