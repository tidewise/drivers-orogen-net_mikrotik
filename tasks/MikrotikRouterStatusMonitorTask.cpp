/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "MikrotikRouterStatusMonitorTask.hpp"
#include "network_status_monitoring/MikrotikRouterStatusResponse.hpp"

using namespace network_status_monitoring;

MikrotikRouterStatusMonitorTask::MikrotikRouterStatusMonitorTask(std::string const& name)
    : MikrotikRouterStatusMonitorTaskBase(name)
{
}

MikrotikRouterStatusMonitorTask::~MikrotikRouterStatusMonitorTask()
{
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See MikrotikRouterStatusMonitorTask.hpp for more detailed
// documentation about them.

bool MikrotikRouterStatusMonitorTask::configureHook()
{
    if (! MikrotikRouterStatusMonitorTaskBase::configureHook())
        return false;

    m_monitor.setup(_config.get());
    return true;
}
bool MikrotikRouterStatusMonitorTask::startHook()
{
    if (! MikrotikRouterStatusMonitorTaskBase::startHook())
        return false;
    return true;
}
void MikrotikRouterStatusMonitorTask::updateHook()
{
    MikrotikRouterStatusResponse response = m_monitor.update();
    _status.write(response);

    MikrotikRouterStatusMonitorTaskBase::updateHook();
}
void MikrotikRouterStatusMonitorTask::errorHook()
{
    MikrotikRouterStatusMonitorTaskBase::errorHook();
}
void MikrotikRouterStatusMonitorTask::stopHook()
{
    MikrotikRouterStatusMonitorTaskBase::stopHook();
}
void MikrotikRouterStatusMonitorTask::cleanupHook()
{
    m_monitor.disableClient();
    MikrotikRouterStatusMonitorTaskBase::cleanupHook();
}
