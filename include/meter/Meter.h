#pragma once

#include <array>
#include <iostream>
#include <memory>
#include <optional>
#include <string>

enum class MeterType
{
    SINGLE_PHASE,
    THREE_PHASE,
};

enum class Client
{
    EDP,
    CEMIG,
    COELCE,
    COPEL,
};

enum class Line
{
    APOLO,
    CRONOS,
    ARES,
    ZEUS,
};

auto meter_type_enum_to_string(MeterType type) -> std::optional<std::string>;
auto client_enum_to_string(Client client) -> std::optional<std::string>;
auto line_enum_to_string(Line line) -> std::optional<std::string>;

class Meter
{
protected:
    int id{0};
    std::string meter_name{};
    MeterType meter_type{};
    Client client{};
    Line line{};
    float phase1{0.0f};
    std::optional<float> phase2{std::nullopt};
    std::optional<float> phase3{std::nullopt};

public:
    virtual ~Meter() = default;
    auto get_meter_as_row() -> std::array<std::string, 5>;
    auto get_id() -> int
    {
        return id;
    }
    auto get_meter_name() -> std::string
    {
        return meter_name;
    }
    auto get_meter_type() -> MeterType
    {
        return meter_type;
    }
    auto get_client() -> Client
    {
        return client;
    }
    auto get_line() -> Line
    {
        return line;
    }
    auto get_phase1() -> float
    {
        return phase1;
    }
    auto get_phase2() -> std::optional<float>
    {
        return phase2;
    }
    auto get_phase3() -> std::optional<float>
    {
        return phase3;
    }
    auto set_id(int i) -> void
    {
        id = i;
    }
    auto set_meter_name(std::string name) -> void
    {
        meter_name = name;
    }
    auto set_meter_type(MeterType type) -> void
    {
        meter_type = type;
    }
    auto set_client(Client c) -> void
    {
        client = c;
    }
    auto set_line(Line l) -> void
    {
        line = l;
    }
    auto set_phase1(float p1) -> void
    {
        phase1 = p1;
    }
    auto set_phase2(std::optional<float> p2) -> void
    {
        phase2 = p2;
    }
    auto set_phase3(std::optional<float> p3) -> void
    {
        phase3 = p3;
    }
    auto operator==(const Meter &other) const -> bool
    {
        return (((this->line == other.line) && (this->meter_name == other.meter_name)));
    }
};

class BuilderMeter
{
private:
    Meter meter;

public:
    BuilderMeter() = default;
    auto Reset() -> void;
    auto set_id(int id) -> BuilderMeter &;
    auto set_meter_name(std::string name) -> BuilderMeter &;
    auto set_meter_type(MeterType type) -> BuilderMeter &;
    auto set_client(Client client) -> BuilderMeter &;
    auto set_line(Line line) -> BuilderMeter &;
    auto set_phase1(float phase1) -> BuilderMeter &;
    auto set_phase2(std::optional<float> phase2) -> BuilderMeter &;
    auto set_phase3(std::optional<float> phase3) -> BuilderMeter &;
    auto build() -> std::unique_ptr<Meter>;
};
