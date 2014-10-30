/********************************************************************* *\
 * INTEL CORPORATION PROPRIETARY INFORMATION                            
 * This software is supplied under the terms of a license agreement or  
 * nondisclosure agreement with Intel Corporation and may not be copied 
 * or disclosed except in accordance with the terms of that agreement.  
 * Copyright (C) 2014 Intel Corporation. All Rights Reserved.           
 ********************************************************************* */

// ospray
#include "ospray/common/Library.h"
#include "ospray/transferfunction/TransferFunction.h"
// stl
#include <map>

namespace ospray {

  TransferFunction *TransferFunction::createInstance(std::string type) {

    // Function pointer type for creating a concrete instance of a subtype of this class.
    typedef TransferFunction *(*creationFunctionPointer)();

    // Function pointers corresponding to each subtype.
    std::map<std::string, creationFunctionPointer> symbolRegistry;

    // Return a concrete instance of the requested subtype if the creation function is already known.
    if (symbolRegistry.count(type) > 0 && symbolRegistry[type] != NULL) return((*symbolRegistry[type])());

    // Otherwise construct the name of the creation function to look for.
    std::string creationFunctionName = "ospray_create_transfer_function_" + type;

    // Look for the named function.
    symbolRegistry[type] = (creationFunctionPointer) getSymbol(creationFunctionName);

    // The named function may not be found if the requested subtype is not known.
    if (!symbolRegistry[type] && ospray::logLevel >= 1) std::cerr << "  ospray::TransferFunction  WARNING: unrecognized subtype '" + type + "'." << std::endl;

    // Create a concrete instance of the requested subtype.
    TransferFunction *transferFunction = (symbolRegistry[type]) ? (*symbolRegistry[type])() : NULL;

    // Denote the subclass type in the ManagedObject base class.
    if (transferFunction) transferFunction->managedObjectType = OSP_TRANSFER_FUNCTION;  

    return(transferFunction);
  }

} // namespace ::ospray

