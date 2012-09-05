#include "CCInvocation.h"
#include "script_support/CCScriptSupport.h"
#include "base_nodes/CCNode.h"

NS_CC_EXT_BEGIN

CCInvocation::CCInvocation(CCObject* target, SEL_CCControlHandler action, CCControlEvent controlEvent)
{
    m_target=target;
    m_action=action;
    m_controlEvent=controlEvent;
}

void CCInvocation::invoke(CCObject* sender)
{
    if (m_target && m_action)
    {
        (m_target->*m_action)(sender, m_controlEvent);
    }
    /*
    CCScriptEngineProtocol* pEngine = CCScriptEngineManager::sharedManager()->getScriptEngine();
    if (pEngine && kScriptTypeJavascript == pEngine->getScriptType())
    {
        CCNode* pNode = dynamic_cast<CCNode*>(sender);
        if (pNode) {
            void* argv[2];
            argv[0] = (void*)pNode;
            argv[1] = (void*)m_controlEvent;
            pEngine->executeFunctionWithIntegerData(1, kInvocationBeInvoked, argv, 2);
        }
    }
     */
}

NS_CC_EXT_END
