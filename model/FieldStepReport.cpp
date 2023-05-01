#include "FieldStepReport.h"

#include <utility>

FieldStepReport::FieldStepReport(FieldStepReport::ReportType type, std::string msg) : type(type), msg(std::move(msg)) {}

WINFieldStepReport::WINFieldStepReport(const std::string& msg, int row, int column,
                                       WINFieldStepReport::DIR dir) : FieldStepReport(WIN, msg), row(row),
                                                                      column(column), dir(dir) {}

WINFieldStepReport::WINFieldStepReport(int row, int column,
                                       WINFieldStepReport::DIR dir) : FieldStepReport(WIN, ""), row(row),
                                                                      column(column), dir(dir) {}
