export module CopiumEngine.Application;

import CopiumEngine.Core.CoreTypes;
import CopiumEngine.Engine.EngineSettings;
import CopiumEngine.Platform.Window;

import <memory>;


export namespace Copium
{

    class Application
    {
    public:
        Application();
        virtual ~Application();

        Application(const Application&) = delete;
        Application& operator=(const Application&) = delete;
        Application(Application&& other) noexcept = default;
        Application& operator=(Application&& other) noexcept = default;

        void Run();

    protected:
        virtual void InitSettings(EngineSettings& engineSettings) = 0;
        virtual void InitSystems() = 0;
        virtual void ShutdownSystems() = 0;

    private:
        void _EngineInit();
        void _EngineShutdown();
        void _EngineLoop();

    private:
        EngineSettings          m_engineSettings;

        std::unique_ptr<Window> m_mainWindow;

        bool                    m_engineInitialized;
        bool                    m_engineClosed;
    };


    extern std::unique_ptr<Application> CreateApplication(int32 argc, const char* const* argv);

} // export namespace Copium
