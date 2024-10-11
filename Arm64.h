#ifndef SELFARM64NLINEHOOK_ARM64_H
#define SELFARM64NLINEHOOK_ARM64_H

#include <cstdint>
#include <string>

#define Bin(num) 0b##num

namespace arm64 {

    class Instruction;

#define REG(reg_type, bin_num) static Register reg_type(#reg_type, bin_num);

    class Register {

        friend class Instruction;

        uint32_t size_flag, bin_num;

    public:

        constexpr Register(std::string const &sf, uint32_t bn) : size_flag(
                (sf.find('X') != std::string::npos || sf.find('D') != std::string::npos) ? 1 : 0),
                                                                 bin_num(bn) {}

    };

    REG(X0, Bin(00000))
    REG(X1, Bin(00001))
    REG(X2, Bin(00010))
    REG(X3, Bin(00011))
    REG(X4, Bin(00100))
    REG(X5, Bin(00101))
    REG(X6, Bin(00110))
    REG(X7, Bin(00111))
    REG(X8, Bin(01000))
    REG(X9, Bin(01001))
    REG(X10, Bin(01010))
    REG(X11, Bin(01011))
    REG(X12, Bin(01100))
    REG(X13, Bin(01101))
    REG(X14, Bin(01110))
    REG(X15, Bin(01111))
    REG(X16, Bin(10000))
    REG(X17, Bin(10001))
    REG(X18, Bin(10010))
    REG(X19, Bin(10011))
    REG(X20, Bin(10100))
    REG(X21, Bin(10101))
    REG(X22, Bin(10110))
    REG(X23, Bin(10111))
    REG(X24, Bin(11000))
    REG(X25, Bin(11001))
    REG(X26, Bin(11010))
    REG(X27, Bin(11011))
    REG(X28, Bin(11100))
    REG(X29, Bin(11101))
    REG(X30, Bin(11110))
    REG(X31, Bin(11111))

    REG(W0, Bin(00000))
    REG(W1, Bin(00001))
    REG(W2, Bin(00010))
    REG(W3, Bin(00011))
    REG(W4, Bin(00100))
    REG(W5, Bin(00101))
    REG(W6, Bin(00110))
    REG(W7, Bin(00111))
    REG(W8, Bin(01000))
    REG(W9, Bin(01001))
    REG(W10, Bin(01010))
    REG(W11, Bin(01011))
    REG(W12, Bin(01100))
    REG(W13, Bin(01101))
    REG(W14, Bin(01110))
    REG(W15, Bin(01111))
    REG(W16, Bin(10000))
    REG(W17, Bin(10001))
    REG(W18, Bin(10010))
    REG(W19, Bin(10011))
    REG(W20, Bin(10100))
    REG(W21, Bin(10101))
    REG(W22, Bin(10110))
    REG(W23, Bin(10111))
    REG(W24, Bin(11000))
    REG(W25, Bin(11001))
    REG(W26, Bin(11010))
    REG(W27, Bin(11011))
    REG(W28, Bin(11100))
    REG(W29, Bin(11101))
    REG(W30, Bin(11110))
    REG(W31, Bin(11111))

    REG(S0, Bin(00000))
    REG(S1, Bin(00001))
    REG(S2, Bin(00010))
    REG(S3, Bin(00011))
    REG(S4, Bin(00100))
    REG(S5, Bin(00101))
    REG(S6, Bin(00110))
    REG(S7, Bin(00111))
    REG(S8, Bin(01000))
    REG(S9, Bin(01001))
    REG(S10, Bin(01010))
    REG(S11, Bin(01011))
    REG(S12, Bin(01100))
    REG(S13, Bin(01101))
    REG(S14, Bin(01110))
    REG(S15, Bin(01111))
    REG(S16, Bin(10000))
    REG(S17, Bin(10001))
    REG(S18, Bin(10010))
    REG(S19, Bin(10011))
    REG(S20, Bin(10100))
    REG(S21, Bin(10101))
    REG(S22, Bin(10110))
    REG(S23, Bin(10111))
    REG(S24, Bin(11000))
    REG(S25, Bin(11001))
    REG(S26, Bin(11010))
    REG(S27, Bin(11011))
    REG(S28, Bin(11100))
    REG(S29, Bin(11101))
    REG(S30, Bin(11110))
    REG(S31, Bin(11111))

    REG(D0, Bin(00000))
    REG(D1, Bin(00001))
    REG(D2, Bin(00010))
    REG(D3, Bin(00011))
    REG(D4, Bin(00100))
    REG(D5, Bin(00101))
    REG(D6, Bin(00110))
    REG(D7, Bin(00111))
    REG(D8, Bin(01000))
    REG(D9, Bin(01001))
    REG(D10, Bin(01010))
    REG(D11, Bin(01011))
    REG(D12, Bin(01100))
    REG(D13, Bin(01101))
    REG(D14, Bin(01110))
    REG(D15, Bin(01111))
    REG(D16, Bin(10000))
    REG(D17, Bin(10001))
    REG(D18, Bin(10010))
    REG(D19, Bin(10011))
    REG(D20, Bin(10100))
    REG(D21, Bin(10101))
    REG(D22, Bin(10110))
    REG(D23, Bin(10111))
    REG(D24, Bin(11000))
    REG(D25, Bin(11001))
    REG(D26, Bin(11010))
    REG(D27, Bin(11011))
    REG(D28, Bin(11100))
    REG(D29, Bin(11101))
    REG(D30, Bin(11110))
    REG(D31, Bin(11111))


    class Instruction {
    public:

        class Area {
        public:

            int8_t begin_, end_;

            Area(int8_t begin, int8_t end) {
                if (begin < end) {
                    begin_ = begin;
                    end_ = end;
                } else {
                    begin_ = end;
                    end_ = begin;
                }
            }

            Area(int8_t pos) : Area(pos, pos) {}

            Area() : Area(-1) {}

            bool operator==(Area const &o) const {
                return o.begin_ == begin_ && o.end_ == end_;
            }

            bool operator!=(Area const &o) const {
                return !(*this == o);
            }

            [[nodiscard]] bool IsValid() const {
                return begin_ >= 0 && end_ >= 0;
            }
        };

        struct SymbolInfo {
            uint32_t mask{};
            Area area{};
        };

    public:

        static Instruction New() {
            return {};
        }

        Instruction Encode() {
            return *this;
        }

        [[nodiscard]] uint32_t GetOpcode() const {
            return ((code_ & opcode_info.mask) >> opcode_info.area.begin_);
        }

        Instruction &SetOpcode(uint32_t opcode, Area const &area) {
            return ReplaceCode(opcode_info, area, opcode);
        }

        Instruction &SetOpcode(Instruction const &o) {
            auto const &o_opcode_info = o.opcode_info;
            uint32_t retrieved = (o.code_ & o_opcode_info.mask);
            code_ &= ~o_opcode_info.mask;
            code_ |= retrieved;
            return *this;
        }

        Instruction &SetOpcodeArea(Area const &area) {
            return SetArea(opcode_info, area);
        }

        [[nodiscard]] int32_t GetImm() const {
            return static_cast<int32_t>(FetchValue(imm_info));
        }

        Instruction &SetImm(uint32_t imm_code, Area const &area) {
            return ReplaceCode(imm_info, area, imm_code);
        }

        Instruction &SetImm(uint32_t imm_code) {
            return ReplaceCode(imm_info, imm_info.area, imm_code);
        }

        Instruction &SetImmArea(Area const &area) {
            return SetArea(imm_info, area);
        }

        [[nodiscard]] uint32_t GetImmHi() const {
            return FetchValue(immhi_info);
        }

        Instruction &SetImmHi(uint32_t immhi_code, Area const &area) {
            return ReplaceCode(immhi_info, area, immhi_code);
        }

        Instruction &SetImmHiArea(Area const &area) {
            return SetArea(immhi_info, area);
        }

        [[nodiscard]] uint32_t GetImmLo() const {
            return FetchValue(immlo_info);
        }

        Instruction &SetImmLo(uint32_t immlo_code, Area const &area) {
            return ReplaceCode(immlo_info, area, immlo_code);
        }

        Instruction &SetImmLoArea(Area const &area) {
            return SetArea(immlo_info, area);
        }

        [[nodiscard]] uint32_t GetSf() const {
            return (code_ & sf_info.mask);
        }

        Instruction &SetSf(uint32_t sf_code, Area const &area) {
            return ReplaceCode(sf_info, area, sf_code);
        }

        Instruction &SetSfArea(Area const &area) {
            return SetArea(sf_info, area);
        }

        [[nodiscard]] uint32_t GetHw() const {
            return (code_ & hw_info.mask);
        }

        Instruction &SetHw(uint32_t hw_code, Area const &area) {
            return ReplaceCode(hw_info, area, hw_code);
        }

        Instruction &SetHwArea(Area const &area) {
            return SetArea(hw_info, area);
        }

        [[nodiscard]] uint32_t GetRt() const {
            return (code_ & rt_info.mask);
        }

        Instruction &SetRt(uint32_t rt_code, Area const &area) {
            return ReplaceCode(rt_info, area, rt_code);
        }

        Instruction &SetRtArea(Area const &area) {
            return SetArea(rt_info, area);
        }

        [[nodiscard]] uint32_t GetRn() const {
            return (code_ & rn_info.mask);
        }

        Instruction &SetRn(uint32_t rn_code, Area const &area) {
            return ReplaceCode(rn_info, area, rn_code);
        }

        Instruction &SetRnArea(Area const &area) {
            return SetArea(rn_info, area);
        }

        [[nodiscard]] uint32_t GetRd() const {
            return (code_ & rd_info.mask);
        }

        Instruction &SetRd(Register const &reg, Area const &area = {4, 0}) {
            auto gen_mask = GenMask(area.begin_, area.end_);
            code_ &= ~gen_mask;
            code_ |= (gen_mask & reg.bin_num) << area.begin_;
            UpdateSymbolInfo(rd_info, gen_mask, area);
            return *this;
        }

        Instruction &SetRd(uint32_t rd_code, Area const &area = {4, 0}) {
            return ReplaceCode(rd_info, area, rd_code);
        }

        Instruction &SetRdArea(Area const &area) {
            return SetArea(rd_info, area);
        }

        [[nodiscard]] uint32_t GetCond() const {
            return (code_ & cond_info.mask);
        }

        Instruction &SetCond(uint32_t cond_code, Area const &area) {
            return ReplaceCode(cond_info, area, cond_code);
        }

        Instruction &SetCondArea(Area const &area) {
            return SetArea(cond_info, area);
        }

        void Set(uint32_t code) {
            code_ = code;
        }

        [[nodiscard]] Instruction Copy() {
            return *this;
        }

        [[nodiscard]] Instruction CopyFrom(Instruction const &src) const {
            const_cast<Instruction &>(*this) = src;
            return *this;
        }

        [[nodiscard]] uint32_t AsInt32() const {
            return code_;
        }

        [[nodiscard]] bool IsSameOpcode(uint32_t opcode) const {
            return ((code_ & opcode_info.mask) ==
                    ((opcode << opcode_info.area.begin_) & opcode_info.mask));
        }

        [[nodiscard]] bool IsSameOpcode(Instruction const &instruction) const {
            return ((instruction.code_ & instruction.opcode_info.mask) ==
                    (code_ & opcode_info.mask));
        }

    private:

        Instruction &SetArea(SymbolInfo &info, Area const &area) {
            info.area = area;
            return *this;
        }

        [[nodiscard]] uint32_t FetchValue(SymbolInfo const &info) const {
            return ((code_ & info.mask) >> info.area.begin_);
        }

        Instruction &ReplaceCode(SymbolInfo &info, Area const &new_area, uint32_t new_code) {
            uint32_t new_mask = GenMask(new_area);
            if (info.area != new_area && info.area.IsValid()) {
                ClearPreviousCode(info);
            } else {
                ClearPreviousCode(new_mask);
            }
            SetNewCode(new_mask, new_code, new_area);
            UpdateSymbolInfo(info, new_mask, new_area);

            return *this;
        }

        void SetNewCode(uint32_t gen_mask, uint32_t new_code, Area const &new_area) {
            code_ |= (gen_mask) & (new_code << new_area.begin_);
        }

        void ClearPreviousCode(SymbolInfo &info) {
            code_ &= ~info.mask;
        }

        void ClearPreviousCode(uint32_t mask) {
            code_ &= ~mask;
        }

        static void UpdateSymbolInfo(SymbolInfo &info, uint32_t mask, Area const &area) {
            info.mask = mask;
            info.area = area;
        }

        static uint32_t GenMask(Area const &area) {
            return GenMask(area.begin_, area.end_);
        }

        static uint32_t GenMask(size_t begin, size_t end) {
            if (begin < 0 || end > 31 || begin > end) {
                std::terminate();
            }

            return ((1u << (end - begin + 1)) - 1) << begin;
        }

    private:

        uint32_t code_{};

        SymbolInfo sf_info,
                opcode_info,
                hw_info,
                imm_info, immhi_info, immlo_info,
                rd_info, rt_info, rn_info,
                cond_info;

    };
}

#endif //SELFARM64NLINEHOOK_ARM64_H
