#ifndef __TRINITY_ARCHAEOLOGYMGR_H
#define __TRINITY_ARCHAEOLOGYMGR_H

#include <map>
#include <string>

#include "Common.h"
#include <ace/Singleton.h>
#include "DatabaseEnv.h"
#include "DBCEnums.h"
#include "DBCStores.h"

class Player;

#define RESEARCH_SITES_PER_MAP                  4
#define MAX_RESEARCH_SITES                      (RESEARCH_SITES_PER_MAP * 6) // Kalimdor, EasternKingdoms, Outland, Northrend, Pandaria, Draenor
#define ARCHAEOLOGY_DIG_SITE_FAR_DIST           40
#define ARCHAEOLOGY_DIG_SITE_MED_DIST           20
#define ARCHAEOLOGY_DIG_SITE_CLOSE_DIST         8
#define ARCHAEOLOGY_DIG_SITE_FAR_SURVEYBOT      206590
#define ARCHAEOLOGY_DIG_SITE_MEDIUM_SURVEYBOT   206589
#define ARCHAEOLOGY_DIG_SITE_CLOSE_SURVEYBOT    204272

enum ResearchWithLevelResult
{
    RS_RESULT_FAIL  = 0,
    RS_RESULT_OK    = 1,
    RS_RESULT_HIDE  = 2,
};

struct DigitSite
{
    uint8 count;
    uint16 site_id;
    uint32 loot_id;
    float loot_x;
    float loot_y;
    float loot_z;

    void clear()
    {
        site_id = loot_id = 0;
        loot_x = loot_y = loot_z = 0.0f;
        count = 0;
    }

    bool empty() { return site_id == 0; }
};

struct ProjectCost
{
    ProjectCost(uint32 _itemId, uint32 _count, bool isCurrency)
    {
        itemId = _itemId;
        count = _count;
        currency = isCurrency;
    }

    uint32 itemId;
    uint32 count;
    bool currency;
};

struct CompletedProject
{
    uint32 projectId;
    uint32 count;
    uint32 first_date;
};

typedef std::set<uint32> SiteSet;
typedef std::set<uint32> ProjectSet;
typedef std::map<uint32, ProjectSet> Projects;

typedef std::set<uint32> ResearchSiteSet;
typedef std::map<uint32, ResearchSiteSet> ResearchSitesMap;
typedef std::set<uint32> ResearchProjectSet;
typedef std::map<uint32, CompletedProject> CompletedProjectMap;

class ArchaeologyMgr
{
    public:
        ArchaeologyMgr(Player* player) : _player(player)
        {
            for (uint8 i = 0; i < MAX_RESEARCH_SITES; ++i)
                _digSites[i].clear();
        }

        ~ArchaeologyMgr() { }

        void LoadArchaeology(PreparedQueryResult p_Result, PreparedQueryResult p_ResultProjects, PreparedQueryResult p_ResultSites);
        void SaveArchaeology(SQLTransaction& trans);

        void AddProjectCost(uint32 entry, uint32 count, bool isCurrency)
        {
            costData.push_back(ProjectCost(entry, count, isCurrency));
        }
        void ClearProjectCost() { costData.clear(); }

        bool ValidateCostData();
        bool SolveResearchProject(uint32 projectId);
        uint32 GetSurveyBotEntry(float &orientation);

        CompletedProjectMap& GetCompletedProjects() { return _completedProjects; }

        void GenerateResearchProjects();
        void GenerateResearchSites();
        void GenerateResearchSitesForMap(uint32 p_MapId, uint32 p_SitesCount);

        void ShowResearchProjects();
        void ShowResearchSites();

        void UseResearchSite(uint32 id);

        uint16 GetRandomActiveSiteInMap(uint32 mapId);

        void SendSearchComplete(bool finished, uint8 count, uint16 siteId);
        void SendSearchSiteComplete(uint16 siteId);

    private:
        Player* _player;
        std::vector<ProjectCost> costData;
        DigitSite _digSites[MAX_RESEARCH_SITES];
        ResearchSitesMap _researchSites;
        ResearchProjectSet _researchProjects;
        CompletedProjectMap _completedProjects;
        bool _archaeologyChanged;

        bool HasResearchSite(uint32 id, uint32 mapId)
        {
            if (_researchSites.find(mapId) == _researchSites.end())
                return false;

            return _researchSites[mapId].find(id) != _researchSites[mapId].end();
        }

        bool HasResearchProject(uint32 id) const
        {
            return _researchProjects.find(id) != _researchProjects.end();
        }

        bool GenerateDigitLoot(uint16 zoneid, DigitSite &site);

        uint16 GetResearchSiteID();

        void GenerateResearchSiteInMap(uint32 p_MapId);
        ResearchWithLevelResult CanResearchWithLevel(uint32 siteId);

        void ValidateSites();
        void ValidateProjects();
};

#endif
