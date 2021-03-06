/*
 * Copyright 2012 Research In Motion Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef PIM_CALENDAR_JS_HPP_
#define PIM_CALENDAR_JS_HPP_

#include <json/value.h>
#include <pthread.h>
#include <plugin.h>
#include <string>

typedef void* ThreadFunc(void *args);

class PimCalendar : public JSExt
{
public:
    explicit PimCalendar(const std::string& id);
    virtual ~PimCalendar() {}
    virtual std::string InvokeMethod(const std::string& command);
    virtual bool CanDelete();
    void NotifyEvent(const std::string& eventId, const std::string& event);

    static void* FindThread(void *args);
    static void* SaveThread(void *args);
    static void* RemoveThread(void *args);
private:
    bool startThread(ThreadFunc threadFunction, Json::Value *jsonObj);

    std::string m_id;
};

#endif // PIM_CALENDAR_JS_HPP_
