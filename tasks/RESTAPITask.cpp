/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "RESTAPITask.hpp"
#include "net_mikrotik/InterfaceStats.hpp"

using namespace net_mikrotik;
using namespace std;

RESTAPITask::RESTAPITask(std::string const& name)
    : RESTAPITaskBase(name)
{
    RestClient::init();
}

RESTAPITask::~RESTAPITask()
{
    RestClient::disable();
}

/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See RESTAPITask.hpp for more detailed
// documentation about them.

bool RESTAPITask::configureHook()
{
    if (!RESTAPITaskBase::configureHook())
        return false;

    m_rest_api.setup(_config.get());
    return true;
}
bool RESTAPITask::startHook()
{
    if (!RESTAPITaskBase::startHook())
        return false;
    return true;
}
void RESTAPITask::updateHook()
{
    RestClient::Response interface_response = m_rest_api.getInterfaceResponse();
    vector<InterfaceStats> stats = m_rest_api.parseInterfaceResponse(interface_response);
    _interface_stats.write(stats);

    RESTAPITaskBase::updateHook();
}
void RESTAPITask::errorHook()
{
    RESTAPITaskBase::errorHook();
}
void RESTAPITask::stopHook()
{
    RESTAPITaskBase::stopHook();
}
void RESTAPITask::cleanupHook()
{
    RESTAPITaskBase::cleanupHook();
}
