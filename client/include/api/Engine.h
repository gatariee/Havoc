#ifndef HAVOCCLIENT_API_ENGINE_H
#define HAVOCCLIENT_API_ENGINE_H

#include <Common.h>

#include <api/HcCore.h>
#include <api/HcScriptManager.h>
#include <api/HcAgent.h>

inline auto HcPythonReleaseGil() -> void {
    if ( PyGILState_Check() ) {
        PyEval_SaveThread();
    }
}

class HcPyEngine : public QThread {
    Q_OBJECT

public:
    py11::scoped_interpreter* guard{};

    std::optional<py11::object> PyEval = {};
    std::optional<py11::object> PyLoad = {};

    explicit HcPyEngine();
    ~HcPyEngine();

    auto run() -> void;
};

#endif
