# engineering_template

<!-- Replace the title and description with your project name and one-sentence summary. -->

> Generic C++ project template with hexagonal architecture.

## Documentation structure

V-model lifecycle — remove folders that do not apply to your project.

| Folder | Phase | Question |
|--------|-------|----------|
| `overview/` | Context | Why does this project exist? |
| `requirements/` | Define | What must the system do? |
| `architecture/` | Design | How is the system structured? |
| `design/` | Design | How is each part designed in detail? |
| `implementation/` | Build | How do we build and deliver it? |
| `verification/` | Verify | How do we prove it works? |
| `safety-compliance/` | Qualify | What are the risks and obligations? |
| `operations/` | Operate | How do we run it in production? |
| `project/` | Manage | How is the project managed? |
| `meta/` | Meta | How is this documentation managed? |

Writing conventions and templates → [meta/documentation-guide.md](meta/documentation-guide.md)

!!! tip "Using this template"
    Remove folders that don't apply (e.g. no hardware → delete `hw-*` pages and their nav entries in `mkdocs.yml`).
    All placeholder content is marked with HTML comments inside each file.
