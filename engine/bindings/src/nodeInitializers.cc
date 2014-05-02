#include "project.h"
#include "boxCreators.cc"
#include "boxManagers.cc"

using namespace std;
using namespace v8;


// declare value function pointer type as ValueFunc
typedef Handle<Value> (*ValueFunc) (const Arguments& args);

namespace nodeInitializers {

    map <
      const char*
    , ValueFunc
    > valueExportables = 
    // these are the Value functions which are exposed to the javascript
    {
          {"CreateWorld"            , boxCreators::CreateWorld}
         ,{"CreateDynamicBody"      , boxCreators::CreateDynamicBody}
         ,{"CreateFixedBody"        , boxCreators::CreateFixedBody}
         ,{"AttachDynamicBoxFixture", boxCreators::AttachDynamicBoxFixture}
         ,{"AttachFixedBoxFixture"  , boxCreators::AttachFixedBoxFixture}
         ,{"Tick"                   , boxManagers::Tick}
         ,{"Update"                 , boxManagers::Update}
    };
    
    void ExportValueFunction(
      Handle<Object> exports
    , Handle<Value> (*func)(const Arguments& args)
    , const char* name
    ) {
    //export function, expose as name
    exports->Set(
          String::NewSymbol(name)
        , FunctionTemplate::New(func)->GetFunction()
        );
    }
    
    void init(Handle<Object> exports) {
        map <
          const char*
        , ValueFunc
        >::iterator iter;

        // expose the Value functions
        for (
            iter = valueExportables.begin();
            iter != valueExportables.end();
            iter++
            ) {
            ExportValueFunction(exports, iter->second, iter->first); 
        }
    }



}