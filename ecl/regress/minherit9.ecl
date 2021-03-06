/*##############################################################################

    HPCC SYSTEMS software Copyright (C) 2012 HPCC Systems®.

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
############################################################################## */



interface1 := module,interface
export boolean useName;
export boolean useAvailable;
        end;

interface2 := interface
export boolean useName;
export boolean useAddress;
        end;

string f1(interface1 ctx) := '[' + (string)ctx.useName + ',' + (string)ctx.useAvailable + ']';
string f2(interface2 ctx) := '[' + (string)ctx.useName + ',' + (string)ctx.useAddress+ ']';

options1 := module(interface1)
export boolean useName := true;
export boolean useAvailable := false;
    end;

options2 := module(interface2)
export boolean useName := true;
export boolean useAddress := true;
    end;

options := module(options1, options2)
        end;

output(f1(options));
output(f2(options));


options2b := module(interface2)
export boolean useName := false;
export boolean useAddress := true;
    end;

optionsb := module(options1, options2b)
export boolean useName := false;            // disambiguate
        end;

output(f1(options));
output(f2(optionsb));
