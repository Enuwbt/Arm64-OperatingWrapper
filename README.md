# Arm64-OperatingWrapper

Usage:
```cpp
    using namespace arm64;

    int value = //...

    static Instruction mov_wd_imm = Instruction::New()
                                        .SetSf(     0,              {31})
                                        .SetOpcode( Bin(10100101),  {30, 23})
                                        .SetHw(     Bin(00),        {22, 21})
                                        .SetImmArea(                {20, 5})
                                        .SetRdArea(                 {4, 0});

    target[0] = mov_wd_imm.Copy().SetImm(value).SetRd(W0).AsInt32(); //MOV(Wide Immediate) W0, #value 
```

TODO: Implement imm sign-extending
