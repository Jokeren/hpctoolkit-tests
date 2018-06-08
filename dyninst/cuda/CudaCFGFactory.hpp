#include <CFGFactory.h>
#include <unordered_map>

#include "DotCFG.hpp"

namespace Dyninst {
namespace ParseAPI {

class PARSER_EXPORT CudaCFGFactory : public CFGFactory {   
 public:
    CudaCFGFactory(std::vector<CudaParse::Function *> &functions) : _functions(functions) {};
    ~CudaCFGFactory();

 protected:
    virtual Function * mkfunc(Address addr, FuncSource src, 
            std::string name, CodeObject * obj, CodeRegion * region, 
            Dyninst::InstructionSource * isrc);

 private:
    std::vector<CudaParse::Function *> &_functions;
    std::unordered_map<size_t, Block *> _block_filter; 
};

}
}
