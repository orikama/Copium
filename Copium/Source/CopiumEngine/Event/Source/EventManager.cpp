module;

#include <optional>
#include <utility>

module CopiumEngine.Event.EventManager;


namespace Copium
{

    void EventManager::DispatchEvents()
    {
        for (auto& handleAndResizeEvents : m_windowResizeEvents)
        {
            if (handleAndResizeEvents.second.has_value())
            {
                WindowResizeEvent evt = handleAndResizeEvents.second.value();
                handleAndResizeEvents.second.reset();
                m_windowResizeCallbacks.find(handleAndResizeEvents.first)->second(evt);
            }
        }
    }


    void EventManager::RegisterWindowCloseCallback(WindowHandle windowHandle, WindowCloseCallback callback)
    {
        m_windowCloseCallbacks.emplace(windowHandle, callback);
    }

    void EventManager::RegisterWindowResizeCallback(WindowHandle windowHandle, WindowResizeCallback callback)
    {
        m_windowResizeCallbacks.emplace(windowHandle, callback);
        m_windowResizeEvents.emplace(windowHandle, std::nullopt);
    }


    void EventManager::SendWindowCloseEvent(WindowHandle windowHandle)
    {
        if (auto it = m_windowCloseCallbacks.find(windowHandle); it != m_windowCloseCallbacks.end())
        {
            it->second();
        }
    }

    void EventManager::SendWindowResizeEvent(WindowHandle windowHandle, WindowResizeEvent&& evt)
    {
        if (auto it = m_windowResizeEvents.find(windowHandle); it != m_windowResizeEvents.end())
        {
            it->second = std::move(evt);
        }
    }

} // namespace Copium
