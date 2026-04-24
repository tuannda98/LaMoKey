#ifndef LAMOKEY_FCITX5_ENGINE_H
#define LAMOKEY_FCITX5_ENGINE_H

#include <fcitx/addonfactory.h>
#include <fcitx/inputmethodengine.h>
#include <fcitx/instance.h>

namespace fcitx {

class LaMoKeyEngine : public InputMethodEngineV2 {
public:
    LaMoKeyEngine(Instance *instance);
    ~LaMoKeyEngine() override;

    void keyEvent(KeyEvent &keyEvent) override;
    void activate(const InputMethodEntry &entry, InputContextEvent &event) override;
    void deactivate(const InputMethodEntry &entry, InputContextEvent &event) override;

private:
    Instance *instance_;
};

class LaMoKeyEngineFactory : public AddonFactory {
public:
    AddonInstance *create(AddonManager *manager) override;
};

} // namespace fcitx

#endif // LAMOKEY_FCITX5_ENGINE_H
