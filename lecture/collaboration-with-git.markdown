---
layout: default
title: Collaboration with git
---

You know about git from [earlier notes](/lecture/git.html). These notes explain more about the workflow of using git in teams.

![Simple workflow](/images/simple_git_daily_workflow.png)

Image adapted from [Sonassi's guide](https://www.sonassi.com/knowledge-base/our-magento-git-guide-and-work-flow/).

## Branching & merging

It's bad form to develop on the `master` branch. When you do so, you often find yourself stuck with difficult merges for nearly every pushed commit.

Better is to create a branch for yourself, work in that branch for a few days, then merge it into master and delete it. Create a branch for each distinct "feature" that you're working on. This will make merges easier, since each feature often involves disjoint sets of files.

![Branching and merging](/images/git_magento_workflow_diagram.png)

Image adapted from [Sonassi's guide](https://www.sonassi.com/knowledge-base/our-magento-git-guide-and-work-flow/).

## Cheatsheet

Download this image [here](/images/git_workflow_and_cheat_sheet.png).

<div style="text-align: center">
<a href="/images/git_workflow_and_cheat_sheet.png"><img alt="Git cheatsheet" src="/images/git_workflow_and_cheat_sheet-small.png"></a>
</div>


